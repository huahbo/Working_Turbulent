/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-03 12:47:20 mike_georgiou>   
*
*
Periodic_BC.cpp -- This function will implement periodic BC in
    the homogeneous directions for the inputted quantities
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include "../Struct.h"

void Periodic_BC_Derivatives(turbulence_derivatives les,
                       int lx, int rx,
                       int lz, int rz,
                       int ldx, int ldy, int ldz)
{


  //X-Direction BC
  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){

      for (int i=1; i<=lx; i++)
        {
          /*******Left-Periodic-BC************/

          //derivatives of U
          les.u_over_x[k][j][-i] =  les.u_over_x[k][j][ldx-i];
          les.u_over_y[k][j][-i] =  les.u_over_y[k][j][ldx-i];
          les.u_over_z[k][j][-i] =  les.u_over_z[k][j][ldx-i];

          //derivatives of V    les.
          les.v_over_x[k][j][-i] =  les.v_over_x[k][j][ldx-i];
          les.v_over_y[k][j][-i] =  les.v_over_y[k][j][ldx-i];
          les.v_over_z[k][j][-i] =  les.v_over_z[k][j][ldx-i];

          //derivatives of W    les.
          les.w_over_x[k][j][-i] =  les.w_over_x[k][j][ldx-i];
          les.w_over_y[k][j][-i] =  les.w_over_y[k][j][ldx-i];
          les.w_over_z[k][j][-i] =  les.w_over_z[k][j][ldx-i];

        }
      for (int i=0; i<rx; i++)
        {
          /*******Right-Periodic-BC***********/

          //Derivatives of U
          les.u_over_x[k][j][ldx+i] =  les.u_over_x[k][j][i];
          les.u_over_y[k][j][ldx+i] =  les.u_over_y[k][j][i];
          les.u_over_z[k][j][ldx+i] =  les.u_over_z[k][j][i];

          //derivatives of V
          les.v_over_x[k][j][ldx+i] =  les.v_over_x[k][j][i];
          les.v_over_y[k][j][ldx+i] =  les.v_over_y[k][j][i];
          les.v_over_z[k][j][ldx+i] =  les.v_over_z[k][j][i];

          //derivatives of W
          les.w_over_x[k][j][ldx+i] =  les.w_over_x[k][j][i];
          les.w_over_y[k][j][ldx+i] =  les.w_over_y[k][j][i];
          les.w_over_z[k][j][ldx+i] =  les.w_over_z[k][j][i];
          
        }
    }
  }


  //Periodic BC in the Z direction
  // Z-Direction BC
  for (int j = 0; j < ldy; j++){
    for (int i = -lx; i< ldx+rx; i++){


      for (int k=1; k<=lz; k++)
        {
          /*******Left-Periodic-BC************/

          //derivatives of U
          les.u_over_x[-k][j][i] =  les.u_over_x[ldz-k][j][i];
          les.u_over_y[-k][j][i] =  les.u_over_y[ldz-k][j][i];
          les.u_over_z[-k][j][i] =  les.u_over_z[ldz-k][j][i];

          //derivatives of V
          les.v_over_x[-k][j][i] =  les.v_over_x[ldz-k][j][i];
          les.v_over_y[-k][j][i] =  les.v_over_y[ldz-k][j][i];
          les.v_over_z[-k][j][i] =  les.v_over_z[ldz-k][j][i];

          //derivatives of W
          les.w_over_x[-k][j][i] =  les.w_over_x[ldz-k][j][i];
          les.w_over_y[-k][j][i] =  les.w_over_y[ldz-k][j][i];
          les.w_over_z[-k][j][i] =  les.w_over_z[ldz-k][j][i];

        }
      for (int k=0; k<rz; k++)
        {

          /*******Right-Periodic-BC***********/

          //Derivatives of U
          les.u_over_x[ldz+k][j][i] =  les.u_over_x[k][j][i];
          les.u_over_y[ldz+k][j][i] =  les.u_over_y[k][j][i];
          les.u_over_z[ldz+k][j][i] =  les.u_over_z[k][j][i];

          //derivatives of V
          les.v_over_x[ldz+k][j][i] =  les.v_over_x[k][j][i];
          les.v_over_y[ldz+k][j][i] =  les.v_over_y[k][j][i];
          les.v_over_z[ldz+k][j][i] =  les.v_over_z[k][j][i];

          //derivatives of W
          les.w_over_x[ldz+k][j][i] =  les.w_over_x[k][j][i];
          les.w_over_y[ldz+k][j][i] =  les.w_over_y[k][j][i];
          les.w_over_z[ldz+k][j][i] =  les.w_over_z[k][j][i];

        }

    }
  }


}
