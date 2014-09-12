/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-10 11:23:15 mike_georgiou>   
*
*
Dynamic_Smagorinsky.cpp -- This functions computes the Smagorinsky
    constant dynamically. 

The procedure that is followed to compute the eddy viscosity
dynamically is described by lesieur and metais paper "New Trends in
LES of Turbulence"

*
* Written on Monday,  1 September 2014.
********************************************/
#include "Dynamic_Smagorinsky.h"
#include "Dynamic_Smagorinsky-inl.h"

void Dynamic_Smagorinsky(turbulence_derivatives subgrid,
                         turbulence_derivatives filtered,
                         turbulence_variables alpha,
                         turbulence_variables alpha_filtered,
                         turbulence_variables beta,
                         turbulence_variables mi,
                         turbulence_variables lambda,
                         turbulence_variables rho_uu,
                         turbulence_variables rho_uu_filtered,
                         turbulence_rhos rho_u,
                         turbulence_rhos rho_u_filtered,
                         double *C_s,
                         double ***velocity_x,
                         double ***velocity_y,
                         double ***velocity_z,
                         double ***rho,
                         double dx, double *dy, double dz,
                         int left_x, int right_x,
                         int left_y, int right_y,
                         int left_z, int right_z,
                         int ldx, int ldy, int ldz)
{

  //Computation of spatial derivatives
  Derivative_Computation( subgrid,
                          velocity_x,
                          velocity_y,
                          velocity_z,
                          dx, dy,  dz,
                          ldx, ldy,  ldz);


 //Implementing periodic boundary conditions in the homogeneous
 //directions for the velocity spatial derivatives
  Periodic_BC_Derivatives(subgrid,
                          left_x,  right_x,
                          left_z,  right_z,
                          ldx,  ldy,  ldz);


  //Filtering  the velocity spatial derivatives.
  Filtering_Derivatives( subgrid,
                         filtered,
                         ldx,  ldy, ldz);  


  //Computation of the alpha array.
  Alpha_Computation( subgrid,
                     alpha,
                     rho,
                     dx, dy,  dz,
                     ldx,  ldy,  ldz);

  //Implementing periodic boundary conditions for Alpha
  Periodic_BC_Variables(alpha,
                        left_x,  right_x,
                        left_z,  right_z,
                        ldx,  ldy,  ldz);

  //Filtering alpha
  Filtering_Variables( alpha,
                       alpha_filtered,
                       ldx,  ldy, ldz);  

  //Initializing and filtering rho.
  Rho_Initialization(rho_u,
                     rho_u_filtered,
                     rho_uu,
                     rho_uu_filtered,
                     rho,
                     velocity_x,
                     velocity_y,
                     velocity_z,
                     left_x,  right_x,
                     left_y,  right_y,
                     left_z,  right_z,
                     ldx,  ldy,  ldz);


  //Computing Beta.
  Beta_Computation( filtered,
                    beta,
                    rho,
                    dx,  dy,  dz,
                    ldx,  ldy, ldz);


  //Computing Mi and Lambda
  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){
        
        mi.xx[k][j][i] =beta.xx[k][j][i]-alpha_filtered.xx[k][j][i];
        mi.xy[k][j][i] =beta.xy[k][j][i]-alpha_filtered.xy[k][j][i];
        mi.xz[k][j][i] =beta.xz[k][j][i]-alpha_filtered.xz[k][j][i];

        mi.yy[k][j][i] =beta.yy[k][j][i]-alpha_filtered.yy[k][j][i];
        mi.yz[k][j][i] =beta.yz[k][j][i]-alpha_filtered.yz[k][j][i];
        mi.zz[k][j][i] =beta.zz[k][j][i]-alpha_filtered.zz[k][j][i];
        
      // Lambda xx xy and xz computation      
      lambda.xx[k][j][i]=rho_uu_filtered.xx[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.x[k][j][i]
                                        *rho_u_filtered.x[k][j][i]);


      lambda.xy[k][j][i]=rho_uu_filtered.xy[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.x[k][j][i]
                                        *rho_u_filtered.y[k][j][i]);

      lambda.xz[k][j][i]=rho_uu_filtered.xz[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.x[k][j][i]
                                        *rho_u_filtered.z[k][j][i]);


      // Lambda yy yz and zz computation      
      lambda.yy[k][j][i]=rho_uu_filtered.yy[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.y[k][j][i]
                                        *rho_u_filtered.y[k][j][i]);


      lambda.yz[k][j][i]=rho_uu_filtered.yz[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.y[k][j][i]
                                        *rho_u_filtered.z[k][j][i]);

      lambda.zz[k][j][i]=rho_uu_filtered.zz[k][j][i]-
        1./rho_u_filtered.rho[k][j][i]*(rho_u_filtered.z[k][j][i]
                                        *rho_u_filtered.z[k][j][i]);

      }
    }	    
  }   

//Computation of the C_s based on the relation 8.12 of the Lesieur paper
 for (int j = 0; j < ldy; j++){
    double sum_1=0.;
    double sum_2=0.;

    for (int k = 0; k < ldz; k++){
      for (int i = 0; i < ldx; i++){
      
        sum_1 += 
          lambda.xx[k][j][i]*mi.xx[k][j][i] 
          +lambda.yy[k][j][i]*mi.yy[k][j][i]
          +lambda.zz[k][j][i]*mi.zz[k][j][i]
          +2.*(lambda.xy[k][j][i]*mi.xy[k][j][i]
               +lambda.xz[k][j][i]*mi.xz[k][j][i]
               +lambda.yz[k][j][i]*mi.yz[k][j][i]);


        sum_2 += 
          mi.xx[k][j][i]*mi.xx[k][j][i] 
          +mi.yy[k][j][i]*mi.yy[k][j][i]
          +mi.zz[k][j][i]*mi.zz[k][j][i]
          +2.*(mi.xy[k][j][i]*mi.xy[k][j][i]
               +mi.xz[k][j][i]*mi.xz[k][j][i]
               +mi.yz[k][j][i]*mi.yz[k][j][i]);
        
      }
    }	 
    //averaging over the periodic dimensions
    sum_1/=ldx*ldz;
    sum_2/=ldx*ldz;
    
    C_s[j]=(-sum_1/sum_2)/2.;
  }   

}
