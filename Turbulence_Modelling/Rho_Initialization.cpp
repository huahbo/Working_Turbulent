/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 14:56:46 mike_georgiou>   
*
*
Rho_Initialization.cpp -- This function initializes rho which will be
    used in the Dynamic_Smagorinsky() function
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include"../Struct.h"

#include <stdio.h>
#include <string.h>
#include  "Filtering.h"

void Rho_Initialization(turbulence_rhos subgrid_rho_u,
                        turbulence_rhos filtered_rho_u,
                        turbulence_variables rho_uu,
                        turbulence_variables rho_uu_filtered,
                        double ***rho,
                        double ***velocity_x,
                        double ***velocity_y, 
                        double ***velocity_z,
                        int lx, int rx,
                        int ly, int ry,
                        int lz, int rz,
                        int ldx, int ldy, int ldz)

{

  // memcpy ( subgrid_rho.rho, rho, (ldx+6)*(ldy+2)*(ldz+6)*sizeof(double));

  //Initializing the rho and rho_uu structures
  for (int k = -lz; k < ldz+rz; k++){
    for (int j = -ly; j < ldy+ry; j++){
      for (int i = -lx; i < ldx+rx; i++){
      
        //initializing rho and rho*u_i arrays.
        subgrid_rho_u.rho[k][j][i]=rho[k][j][i];
        subgrid_rho_u.x[k][j][i]=rho[k][j][i]*velocity_x[k][j][i];
        subgrid_rho_u.y[k][j][i]=rho[k][j][i]*velocity_y[k][j][i];
        subgrid_rho_u.z[k][j][i]=rho[k][j][i]*velocity_z[k][j][i];


        //Initializing rho*u_i*u_i arrays

        //xx xy xz
        rho_uu.xx[k][j][i]=
          rho[k][j][i]*velocity_x[k][j][i]*velocity_x[k][j][i];

        rho_uu.xy[k][j][i]=
          rho[k][j][i]*velocity_x[k][j][i]*velocity_y[k][j][i];

        rho_uu.xz[k][j][i]=
          rho[k][j][i]*velocity_x[k][j][i]*velocity_z[k][j][i];

        //yy yz zz
        rho_uu.yy[k][j][i]=
          rho[k][j][i]*velocity_y[k][j][i]*velocity_y[k][j][i];

        rho_uu.yz[k][j][i]=
          rho[k][j][i]*velocity_y[k][j][i]*velocity_z[k][j][i];

        rho_uu.zz[k][j][i]=
          rho[k][j][i]*velocity_z[k][j][i]*velocity_z[k][j][i];

      }
    }	    
  }   

  //Computing the filtered quantities
  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){

        //Filtering rho, rho*u, rho*v, rho*w
        Filtering(subgrid_rho_u.rho, filtered_rho_u.rho, i, j, k);
        Filtering(subgrid_rho_u.x, filtered_rho_u.x, i, j, k);
        Filtering(subgrid_rho_u.y, filtered_rho_u.y, i, j, k);
        Filtering(subgrid_rho_u.z, filtered_rho_u.z, i, j, k);

        //filtering alphas, xx xy xz
        Filtering(rho_uu.xx, rho_uu_filtered.xx, i, j, k);
        Filtering(rho_uu.xy, rho_uu_filtered.xy, i, j, k);
        Filtering(rho_uu.xz, rho_uu_filtered.xz, i, j, k);


        //filtering alphas, yy yz zz
        Filtering(rho_uu.yy, rho_uu_filtered.yy, i, j, k);
        Filtering(rho_uu.yz, rho_uu_filtered.yz, i, j, k);
        Filtering(rho_uu.zz, rho_uu_filtered.zz, i, j, k);

      }
    }	    
  }   


}
