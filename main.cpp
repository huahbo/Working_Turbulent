/*******************************************
 *   Author: Michail Georgiou
 * main.cpp -- This project solves the 3D navier stokes equations for a
  non-isothermal problem. Fourth order accurate conservative schemes are used in
  the spanwise(x) and streamwise(z) directions. These schemes are being adopted by
  the Lessani-Papalexandris paper. On the vertical direction(y) a non-uniform grid
  is used.
  *
  * Written on Wednesday, 30 April 2014.
  ********************************************/

//Definition of the libraries that this program will use
#include "main.h"
#include "main-inl.h"



int main (int argc, char *argv[])
{

  //Opening a file to print dts
  ofstream output_file, frict_vel,iteration_file;
  File_Opener(&output_file, "dt.txt");
  File_Opener( &frict_vel, "u_tau.txt");
  File_Opener (&iteration_file, "iterations.txt");

  string filename;
  Information_Reader( &ldx, &ldy, &ldz,
                      &length_x, &length_y, &length_z,
                      &cfl, &tolerance,
                      &iterations, &time_total, &time_end,
                      &time_statistics,
                      &printing_variable,
                      &filename);

  Allocator( &Arr,
             ldx,ldy,ldz,
             left_x,right_x,left_y,right_y,left_z,right_z);


  Allocator_LES( &subgrid, &filtered, &alpha, &alpha_filtered,
                 &beta,&mi, &lambda, &rho_uu, &rho_uu_filtered,
                 &subgrid_rho, &filtered_rho, ldx,  ldy,  ldz,
                 left_x, right_x, left_y, right_y, left_z, right_z);


  //calculating dx and dz
  dx= length_x/(ldx*1.0);
  dz= length_z/(ldz*1.0);

  //Calculation of the Dy's
  double dy_min=100.;
  Hyperbolic_Mesh(Arr.half_dy, Arr.y,
                  length_y,
                  ldy,
                  left_y,right_y,
                  &dy_min);

  Print_Domain( dx, Arr.half_dy,  dz,
                ldx,  ldy,  ldz);


  //Defining the Non-Zero Elements for the Poisson solver
  nze = 15*ldz*(ldy-2)*ldx + 14*ldz*ldx*2;

  //Dimension of the A matrix of the Poisson Equation
  dim_a=ldz*ldy*ldx;


  //Vectors for the Poisson Solver
  s_a = new double [nze  +2];
  ij_a = new int [nze  +2];
  rhs = new double [dim_a +1];
  precond_a = new double [dim_a +1];
  result = new double [dim_a +1];

  //Reading data to initialize my run
  Read_Data(Arr, result,
            filename,
            ldx, ldy,ldz);

  ////Passing the Poisson solution to the Arr.pressure Array
  for (int k=0; k<ldz; k++){
    for (int j=0; j<ldy; j++){
      for (int i=0; i<ldx; i++){
      Arr.pressure[k][j][i] = result[A(i,ldx,j,ldy,k,ldz) +1];
      }
    }
  }

  BC_Single(Arr.pressure,
            ldx,ldy,ldz,
            left_x,right_x,
            left_y,right_y,
            left_z,right_z,
            2,
            pressure_gradient_top, pressure_gradient_bottom,
            Arr.half_dy);

  BC_Velocities( Arr.velocity_x,
                 Arr.velocity_y,
                 Arr.velocity_z,
                 ldx, ldy, ldz,
                 left_x, right_x,
                 left_y, right_y,
                 left_z, right_z,
                 1,
                 velocity_x_top, velocity_x_bottom,
                 velocity_y_top, velocity_y_bottom,
                 velocity_z_top, velocity_z_bottom,
                 Arr.half_dy, dx, 0.);

  Print_Data( Arr.velocity_x, Arr.velocity_y,
              Arr.velocity_z, Arr.pressure,
              ldx, ldy, ldz,
              left_x,right_x,left_y, right_y,left_z, right_z, 
              12);


  double cfl_ratio[3];
  double u_max=0.,v_max=0.,w_max=0.;
  Maximum_Velocities(Arr.velocity_x, Arr.velocity_y,
                     Arr.velocity_z,
                     &u_max, &v_max, &w_max,
                     ldx,  ldy,  ldz);

  cfl_ratio[0]=dx/u_max;
  cfl_ratio[1]=dy_min/v_max;
  cfl_ratio[2]=dz/w_max;

  double min_ratio=fmin(cfl_ratio[0],cfl_ratio[1]);
  min_ratio=fmin(min_ratio,cfl_ratio[2]);

  dt=min_ratio*cfl;
  cout<< "dt = "<<dt<<endl;

  Initial_One(Arr.rho, ldx, ldy, ldz,
              left_x,right_x,
              left_y,right_y,
              left_z, right_z);

  Initial_One(Arr.rho_new, ldx, ldy, ldz,
              left_x,right_x,
              left_y,right_y,
              left_z, right_z);

  Initial_One(Arr.rho_old, ldx, ldy, ldz,
              left_x,right_x,
              left_y,right_y,
              left_z, right_z);


  Initial_One(Arr.temperature, ldx, ldy, ldz,
              left_x,right_x,
              left_y,right_y,
              left_z, right_z);


  //Initializing the Arr.Fluxes.
  //In order to do that I will use the Arr.Flux_Evaluation function.
  //But with the initial values as an input
  Flux_Initialization(Arr.flux_x, Arr.flux_y,
                      Arr.flux_z,
                      Arr.velocity_x, Arr.velocity_y,
                      Arr.velocity_z,
                      Arr.rho,
                      ldx,  ldy,  ldz);


  Initial_Zero(Arr.eddy_viscosity, ldx, ldy, ldz,
               left_x,right_x,
               left_y,right_y,
               left_z, right_z);


  // Be carefull with the sign of the pressure_gradient which is different
  // than the one that i am inputting to the tildas
  Velocity_Residual_Initialization(Arr.residual_x_old, Arr.residual_y_old,
                                   Arr.residual_z_old,Arr.velocity_x,
                                   Arr.velocity_y, Arr.velocity_z,
                                   Arr.flux_x, Arr.flux_y,
                                   Arr.flux_z,
                                   Arr.eddy_viscosity,
                                   Reynolds,
                                   Pressure_Gradient,
                                   &explicit_term,
                                   dx, Arr.half_dy,  dz,
                                   ldx,  ldy,  ldz);

  //////////////////////////////////////////////////////////////////////
  //////////////////////Time Integration Loop///////////////////////////
  //////////////////////////////////////////////////////////////////////

  Coefficients_X[0] = 1./(576.*dx*dx);
  Coefficients_X[1] = -9./(96.*dx*dx);
  Coefficients_X[2] = ( 81./(64.*dx*dx) + 9./(96.*dx*dx) );
  Coefficients_X[3] = (- 81./(32.*dx*dx) - 1./(288.*dx*dx) );

  Coefficients_Z[0] = 1./(576.*dz*dz);
  Coefficients_Z[1] = -9./(96.*dz*dz);
  Coefficients_Z[2] = ( 81./(64.*dz*dz) + 9./(96.*dz*dz) );
  Coefficients_Z[3] = (- 81./(32.*dz*dz) - 1./(288.*dz*dz) );


  Vector_Constructor( s_a, precond_a, ij_a,
                      Coefficients_Z,  Coefficients_X, Arr.half_dy,
                      ldz,  ldy,  ldx,  nze);

  double C_s[ldy];
  int  time_index=0;
  while(time_total<time_end)
    {

      time_total += dt;

      if(time_index%50==0)
        {
          Dynamic_Smagorinsky( subgrid,
                               filtered,
                               alpha,
                               alpha_filtered,
                               beta,
                               mi,
                               lambda,
                               rho_uu,
                               rho_uu_filtered,
                               subgrid_rho,
                               filtered_rho,
                               C_s,
                               Arr.velocity_x,
                               Arr.velocity_y,
                               Arr.velocity_z,
                               Arr.rho,
                               dx, Arr.half_dy, dz,
                               left_x,  right_x,left_y,  right_y,
                               left_z,  right_z,
                               ldx,  ldy,  ldz);
        }

      LES_Modelling_Dynamic(Arr.eddy_viscosity,
                            Arr.velocity_x,
                            Arr.velocity_y, Arr.velocity_z,
                            Arr.rho,
                            C_s,
                            Reynolds,
                            dx, Arr.half_dy,  dz,
                            ldx,  ldy,  ldz);

      BC_Single(Arr.eddy_viscosity,
                ldx, ldy, ldz,
                left_x,right_x,
                left_y,right_y,
                left_z,right_z,
                2,
                0., 0.,
                Arr.half_dy);

      ////Calculating the Intermediate Velocity at the Predictor Stage
      Intermediate_Velocity_Predictor_2ND_X(Arr.velocity_x_tilda,
                                            Arr.residual_x,
                                            Arr.residual_x_old,
                                            Arr.velocity_x,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new,
                                            Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            -Pressure_Gradient,
                                            implicit_scheme,
                                            dx, Arr.half_dy, dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      Intermediate_Velocity_Predictor_2ND_Y(Arr.velocity_y_tilda,
                                            Arr.residual_y,
                                            Arr.residual_y_old,
                                            Arr.velocity_y,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new,
                                            Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            0.,
                                            implicit_scheme,
                                            dx, Arr.half_dy, dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      Intermediate_Velocity_Predictor_2ND_Z(Arr.velocity_z_tilda,
                                            Arr.residual_z,
                                            Arr.residual_z_old,
                                            Arr.velocity_z,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new,
                                            Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            0.,
                                            implicit_scheme,
                                            dx, Arr.half_dy, dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      BC_Tilda(Arr.velocity_x_tilda,
               Arr.velocity_y_tilda,
               Arr.velocity_z_tilda,
               ldx, ldy, ldz,
               left_x, right_x,
               left_y, right_y,
               left_z, right_z);

      //Determining the RHS of the Poisson Equation
      Right_Hand_Side_Poisson(rhs,Arr.velocity_x_tilda,
                              Arr.velocity_y_tilda, Arr.velocity_z_tilda,
                              Arr.rho_new,Arr.rho, Arr.rho_old,
                              dx, Arr.half_dy, dz,
                              dt,
                              ldx, ldy,  ldz);


      ////Solving the Poisson Equation
      BCSG(s_a, ij_a, result, rhs, precond_a,
           tolerance, iterations, dim_a, flag, &iteration_file);
      if(flag==1)
        {

          Print_Data( Arr.velocity_x, Arr.velocity_y,
                      Arr.velocity_z, Arr.pressure,
                      ldx, ldy, ldz,
                      left_x,right_x,
                      left_y, right_y,
                      left_z, right_z, time_index);
          cout<<time_index<<endl;
          break;
        }

      ////Passing the Poisson solution to the Arr.pressure Array
      for (int k=0; k<ldz; k++){
        for (int j=0; j<ldy; j++){
          for (int i=0; i<ldx; i++){

            Arr.pressure[k][j][i] = result[A(i,ldx,j,ldy,k,ldz) +1];

          }
        }
      }
      BC_Single(Arr.pressure,
                ldx,ldy,ldz,
                left_x,right_x,
                left_y,right_y,
                left_z,right_z,
                2,
                pressure_gradient_top, pressure_gradient_bottom,
                Arr.half_dy);


      ///computing the Updated Velocity
      Velocity_Update_X2ND(Arr.velocity_x_new, Arr.velocity_x_tilda,
                           Arr.rho_new, Arr.pressure,
                           dx, dt,
                           ldx,  ldy,  ldz);

      Velocity_Update_Y2ND(Arr.velocity_y_new,  Arr.velocity_y_tilda,
                           Arr.rho_new, Arr.pressure,
                           Arr.half_dy, dt,
                           ldx,  ldy,  ldz);

      Velocity_Update_Z2ND(Arr.velocity_z_new,  Arr.velocity_z_tilda,
                           Arr.rho_new, Arr.pressure,
                           dz, dt,
                           ldx,  ldy,  ldz);

      BC_Velocities( Arr.velocity_x_new,
                     Arr.velocity_y_new,
                     Arr.velocity_z_new,
                     ldx, ldy, ldz,
                     left_x, right_x,
                     left_y, right_y,
                     left_z, right_z,
                     1,
                     velocity_x_top, velocity_x_bottom,
                     velocity_y_top, velocity_y_bottom,
                     velocity_z_top, velocity_z_bottom,
                     Arr.half_dy, dx, time_total);


      //Updating the Auxiliary Arr.Fluxes in order to proceed at
      //the Corrector Stage
      Flux_Evaluation_X2ND(Arr.flux_x, Arr.velocity_x_tilda,
                           Arr.rho_new, Arr.pressure,
                           dx, dt,
                           ldx+1,  ldy,  ldz);

      Flux_Evaluation_Y2ND(Arr.flux_y, Arr.velocity_y_tilda,
                           Arr.rho_new, Arr.pressure,
                           Arr.half_dy, dt,
                           ldx,  ldy+1,  ldz);

      Flux_Evaluation_Z2ND(Arr.flux_z, Arr.velocity_z_tilda,
                           Arr.rho_new,  Arr.pressure,
                           dx, dt,
                           ldx,  ldy,  ldz+1);

      ///////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////
      //////////////////End of the predictor stage///////////////////////
      ///////////////////////////////////////////////////////////////////
      ///////////////////////////////////////////////////////////////////

      Predictor_To_Corrector(&Arr);
      //////////////////////////////////////////////////////////////////
      ////////////////////// Corrector Stage ///////////////////////////
      //////////////////////////////////////////////////////////////////

      LES_Modelling_Dynamic(Arr.eddy_viscosity,
                            Arr.velocity_x_new,
                            Arr.velocity_y_new, Arr.velocity_z_new,
                            Arr.rho,
                            C_s,
                            Reynolds,
                            dx, Arr.half_dy,  dz,
                            ldx,  ldy,  ldz);

      BC_Single(Arr.eddy_viscosity,
                ldx, ldy, ldz,
                left_x,right_x,
                left_y,right_y,
                left_z,right_z,
                2,
                0., 0.,
                Arr.half_dy);

      Intermediate_Velocity_Corrector_2ND_X(Arr.velocity_x_tilda,
                                            Arr.residual_x,
                                            Arr.residual_x_old,
                                            Arr.velocity_x_new,
                                            Arr.velocity_x,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new,
                                            Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            -Pressure_Gradient,
                                            implicit_scheme,
                                            dx, Arr.half_dy,  dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      Intermediate_Velocity_Corrector_2ND_Y(Arr.velocity_y_tilda,
                                            Arr.residual_y,
                                            Arr.residual_y_old,
                                            Arr.velocity_y_new,
                                            Arr.velocity_y,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new, Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            0.,
                                            implicit_scheme,
                                            dx, Arr.half_dy, dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      Intermediate_Velocity_Corrector_2ND_Z(Arr.velocity_z_tilda,
                                            Arr.residual_z,
                                            Arr.residual_z_old,
                                            Arr.velocity_z_new,
                                            Arr.velocity_z,
                                            Arr.flux_x,
                                            Arr.flux_y,
                                            Arr.flux_z,
                                            Arr.rho_new, Arr.rho,
                                            Arr.pressure,
                                            Arr.eddy_viscosity,
                                            Reynolds,
                                            0.,
                                            implicit_scheme,
                                            dx, Arr.half_dy, dz,
                                            dt,
                                            ldx,  ldy,  ldz);

      BC_Tilda(Arr.velocity_x_tilda,
               Arr.velocity_y_tilda,
               Arr.velocity_z_tilda,
               ldx, ldy, ldz,
               left_x, right_x,
               left_y, right_y,
               left_z, right_z);

      ///Determining the RHS of the Poisson Equation
      Right_Hand_Side_Poisson(rhs,Arr.velocity_x_tilda,
                              Arr.velocity_y_tilda,
                              Arr.velocity_z_tilda,
                              Arr.rho_new,Arr.rho, Arr.rho_old,
                              dx, Arr.half_dy, dz,
                              dt,
                              ldx,  ldy,  ldz);

      ///Solving the Poisson Equation
      BCSG(s_a, ij_a, result, rhs, precond_a,
           tolerance, iterations, dim_a,flag, &iteration_file);
      if(flag==1)
        {

          Print_Data( Arr.velocity_x_new, Arr.velocity_y_new,
                      Arr.velocity_z_new, Arr.pressure,
                      ldx, ldy, ldz,
                      left_x,right_x,
                      left_y, right_y,
                      left_z, right_z, time_index);

          cout<<time_index<<endl;
          break;
        }

      //Passing the Poisson solution to the Arr.pressure Array
      for (int k=0; k<ldz; k++){
        for (int j=0; j<ldy; j++){
          for (int i=0; i<ldx; i++){

            Arr.pressure[k][j][i] = result[A(i,ldx,j,ldy,k,ldz) +1];

          }
        }
      }
      BC_Single(Arr.pressure,
                ldx,ldy,ldz,
                left_x,right_x,
                left_y,right_y,
                left_z,right_z,
                2,
                pressure_gradient_top, pressure_gradient_bottom,
                Arr.half_dy);


      //computing the Updated Velocity
      Velocity_Update_X2ND(Arr.velocity_x_new, Arr.velocity_x_tilda,
                           Arr.rho_new, Arr.pressure,
                           dx, dt,
                           ldx,  ldy,  ldz);

      Velocity_Update_Y2ND(Arr.velocity_y_new,  Arr.velocity_y_tilda,
                           Arr.rho_new, Arr.pressure,
                           Arr.half_dy, dt,
                           ldx,  ldy,  ldz);


      Velocity_Update_Z2ND(Arr.velocity_z_new,  Arr.velocity_z_tilda,
                           Arr.rho_new, Arr.pressure,
                           dz, dt,
                           ldx,  ldy,  ldz);

      ///Implementing the Velocity  boundary conditions for the next step
      BC_Velocities( Arr.velocity_x_new,
                     Arr.velocity_y_new,
                     Arr.velocity_z_new,
                     ldx, ldy, ldz,
                     left_x, right_x,
                     left_y, right_y,
                     left_z, right_z,
                     1,
                     velocity_x_top, velocity_x_bottom,
                     velocity_y_top, velocity_y_bottom,
                     velocity_z_top, velocity_z_bottom,
                     Arr.half_dy, dx, time_total);


      ///Updating the Auxiliary Arr.Fluxes in order to proceed
      //  the next timestep
      Flux_Evaluation_X2ND(Arr.flux_x, Arr.velocity_x_tilda,
                           Arr.rho_new, Arr.pressure,
                           dx,dt,
                           ldx+1,  ldy,  ldz);


      Flux_Evaluation_Y2ND(Arr.flux_y, Arr.velocity_y_tilda,
                           Arr.rho_new, Arr.pressure,
                           Arr.half_dy, dt,
                           ldx,  ldy+1,  ldz);


      Flux_Evaluation_Z2ND(Arr.flux_z, Arr.velocity_z_tilda,
                           Arr.rho_new,  Arr.pressure,
                           dx, dt,
                           ldx,  ldy,  ldz+1);

      if (time_index%printing_variable==0)
        {

          Print_Data( Arr.velocity_x_new, Arr.velocity_y_new,
                      Arr.velocity_z_new, Arr.pressure,
                      ldx, ldy, ldz,
                      left_x,right_x,
                      left_y, right_y,
                      left_z, right_z, time_index);

          
          Print_Output(Arr,
                       ldx,  ldy,  ldz);


          cout<<time_index<<endl;
        }


      if(time_index%50==0)
        {

          double friction_velocity[2];
          Friction_Velocity_Computation( Arr,
                                         friction_velocity,
                                         Reynolds,
                                         dx,  dz,ldx,  ldy,  ldz);
        
          frict_vel<<friction_velocity[0]<<" "<<friction_velocity[1]<<endl;
        }
      
      //Time averaging the velocity components and the pressure.
      int auxilary; 
      // Im not initializing that because of the Time_Average()
      if(time_index==1)auxilary=0;
      if(time_total>=time_statistics)
        {
          auxilary+=1;
          if(auxilary==1)
            {
            cout<<" The time averaging starts at time "<<time_total<<endl;
            }

          Time_Average(Arr,
                       time_index,
                       time_total,  dt,
                       auxilary,
                       ldx,  ldy, ldz);
        }


      Maximum_Velocities(Arr.velocity_x_new, Arr.velocity_y_new,
                         Arr.velocity_z_new,
                         &u_max, &v_max, &w_max,
                         ldx,  ldy,  ldz);

      cfl_ratio[0]=dx/u_max;
      cfl_ratio[1]=dy_min/v_max;
      cfl_ratio[2]=dz/w_max;


      double min_ratio=fmin(cfl_ratio[0],cfl_ratio[1]);
      min_ratio=fmin(min_ratio,cfl_ratio[2]);


      dt=min_ratio*cfl;
      if(time_index%50==0)
        {
          output_file<<time_index<<" "<<dt<<" "<<time_total<<endl;
        }

      //Actions to proceed to the next step
      time_index++;
      Next_Step(&Arr);


      signal (SIGINT, termination_handler);
      if (ibroke)
        {
          Print_Data( Arr.velocity_x_new, Arr.velocity_y_new,
                      Arr.velocity_z_new, Arr.pressure,
                      ldx, ldy, ldz,
                      left_x,right_x,
                      left_y, right_y,
                      left_z, right_z, time_index);

          cout<<time_index<<endl;
          break;
        }


    }
  
  Print_Output(Arr,
               ldx,  ldy,  ldz);


  //Closing the output file
  output_file.close();
  frict_vel.close();
  iteration_file.close();

  // Releasing the allocated memory
  DeAllocator(  &Arr,
                ldx,  ldy,  ldz,
                left_x,right_x,
                left_y,right_y,
                left_z,right_z);

  DeAllocator_LES( &subgrid,&filtered,&alpha,&alpha_filtered,
                   &beta,&mi,&lambda,&rho_uu,&rho_uu_filtered,
                   &subgrid_rho,&filtered_rho,ldx,  ldy,  ldz,
                   left_x,  right_x,left_y,  right_y,left_z,  right_z);


  delete[] s_a;
  delete[] ij_a;
  delete[] precond_a;
  delete[] rhs;
  delete[] result;

}
