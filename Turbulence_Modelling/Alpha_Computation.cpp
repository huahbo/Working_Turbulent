/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-03 12:51:59 mike_georgiou>
 *
 *
Alpha_Computation.cpp -- This function computes the variable alpha
    which is part of the procedure of computation of the dynamic eddy
    viscosity
    *
    * Written on Tuesday,  2 September 2014.
    ********************************************/

#include "Dynamic_Smagorinsky.h"
 #include "Dynamic_Smagorinsky-inl.h"


void Alpha_Computation(turbulence_derivatives subgrid,
                       turbulence_variables alpha,
                       double ***rho,
                       double dx, double *dy, double dz,
                       int ldx, int ldy, int ldz)
{


  // At the first stage of this function the spatial derivatives of
  // the velocity components will be computed.
  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){


        //computing the characteristic filtered rate of strain
        double  filtered_strain =
          2*(subgrid.u_over_x[k][j][i]*subgrid.u_over_x[k][j][i]+
             subgrid.v_over_y[k][j][i]*subgrid.v_over_y[k][j][i]+
             subgrid.w_over_z[k][j][i]*subgrid.w_over_z[k][j][i]+
             subgrid.u_over_y[k][j][i]*subgrid.v_over_x[k][j][i]+
             subgrid.u_over_z[k][j][i]*subgrid.w_over_x[k][j][i]+
             subgrid.v_over_z[k][j][i]*subgrid.w_over_y[k][j][i])

          +(subgrid.u_over_y[k][j][i]*subgrid.u_over_y[k][j][i] +
            subgrid.u_over_z[k][j][i]*subgrid.u_over_z[k][j][i] +
            subgrid.v_over_x[k][j][i]*subgrid.v_over_x[k][j][i] +
            subgrid.v_over_z[k][j][i]*subgrid.v_over_z[k][j][i] +
            subgrid.w_over_x[k][j][i]*subgrid.w_over_x[k][j][i] +
            subgrid.w_over_y[k][j][i]*subgrid.w_over_y[k][j][i]);

        filtered_strain= sqrt(filtered_strain);

        double C_s= rho[k][j][i]
          *(dx*dx+(2.*dy[j]*2.*dy[j])+dz*dz)
          *filtered_strain;


        //computation of the variable alpha.

        //xx xy xz
        alpha.xx[k][j][i]=C_s*(2./3.*subgrid.u_over_x[k][j][i]
                                   -1./3.*(subgrid.v_over_y[k][j][i]
                                           +subgrid.w_over_z[k][j][i]));

        alpha.xy[k][j][i]=C_s*(subgrid.u_over_y[k][j][i]
                               +subgrid.v_over_x[k][j][i])/2.;

        alpha.xz[k][j][i]=C_s*(subgrid.u_over_z[k][j][i]
                               +subgrid.w_over_x[k][j][i])/2.;

        //yy yz
        alpha.yy[k][j][i]=C_s*(2./3.*subgrid.v_over_y[k][j][i]
                               -1./3.*(subgrid.u_over_x[k][j][i]
                                       +subgrid.w_over_z[k][j][i]));


        alpha.yz[k][j][i]=C_s*(subgrid.v_over_z[k][j][i]
                               +subgrid.w_over_y[k][j][i])/2.;

        //zz
        alpha.zz[k][j][i]=C_s*(2./3.*subgrid.w_over_z[k][j][i]
                                   -1./3.*(subgrid.v_over_y[k][j][i]
                                           +subgrid.u_over_x[k][j][i]));

      }
    }
  }


}
