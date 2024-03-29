/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-08 13:24:58 mike_georgiou>
 *
 *
LES_Modelling2ND.cpp -- This program will compute the eddy viscosity, based on
    the LES approach. Second order accurate schemes will be used.
    *
    * Written on Wednesday, 20 August 2014.
    ********************************************/

#include "LES_Modelling2ND.h"

void LES_Modelling_Dynamic(double ***eddy_viscosity,
                           double ***velocity_x,
                           double ***velocity_y,
                           double ***velocity_z,
                           double ***rho,
                           double *C_s,
                           double Reynolds,
                           double dx, double *dy, double dz,
                           int ldx, int ldy, int ldz)
{


  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){

        // Declaring the gradients.
        double
          u_over_x=0., u_over_y=0., u_over_z = 0.,
          v_over_x=0., v_over_y=0., v_over_z = 0.,
          w_over_x=0., w_over_y=0., w_over_z = 0.;


        // Computing the gradients of the x component of the velocity.
        Gradients2ND(velocity_x,
                     &u_over_x,  &u_over_y,
                     &u_over_z,
                     dx, dy,  dz,
                     i,  j,  k);


        // Computing the gradients of the y component of the velocity.
        Gradients2ND(velocity_y,
                     &v_over_x,  &v_over_y,
                     &v_over_z,
                     dx, dy,  dz,
                     i,  j,  k);


        // Computing the gradients of the z component of the velocity.
        Gradients2ND(velocity_z,
                     &w_over_x,  &w_over_y,
                     &w_over_z,
                     dx, dy,  dz,
                     i,  j,  k);

        // Computing the characteristing filtered rate of strain
        double filtered_strain =0.;
        double temp=0.;
        temp=
          2*(u_over_x*u_over_x+ v_over_y*v_over_y + w_over_z*w_over_z+
             u_over_y*v_over_x + u_over_z*w_over_x + v_over_z*w_over_y)
          +(u_over_y*u_over_y + u_over_z*u_over_z + v_over_x*v_over_x
            +v_over_z*v_over_z + w_over_x*w_over_x + w_over_y*w_over_y);


        filtered_strain= sqrt(temp);

        //Width of the filter
        double width_square =dx*dx + (2.*dy[j]*2.*dy[j]) + dz*dz;

        //characteristic length

        // multiply only with C_s
        double length_square = C_s[j] * width_square;

        //Computing the eddy viscosity
        eddy_viscosity[k][j][i] =  length_square * filtered_strain*rho[k][j][i]*Reynolds;

      }
    }
  }


  //Averaging eddy viscosity
  for (int j = 0; j < ldy; j++){
    int sum=0.;
    for (int k = 0; k < ldz; k++){
      for (int i = 0; i < ldx; i++){

        sum+=eddy_viscosity[k][j][i];

      }
    }
    eddy_viscosity[1][j][1]=sum/(ldx*ldz);
  }



}
