/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 14:09:21 mike_georgiou>   
*
*
Derivative_Computation.cpp -- 
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include "../Struct.h"
#include "Dynamic_Smagorinsky.h"
 #include "Dynamic_Smagorinsky-inl.h"



void Derivative_Computation(turbulence_derivatives subgrid,
                            double ***velocity_x,
                            double ***velocity_y,
                            double ***velocity_z,
                            double dx, double *dy, double dz,
                            int ldx, int ldy, int ldz)
{



for (int k = 0; k < ldz; k++){
  for (int j = 0; j < ldy; j++){
    for (int i = 0; i < ldx; i++){
      

        //Computing the derivatives of
        Gradients_Computation( velocity_x,
                               subgrid.u_over_x,subgrid.u_over_y,
                               subgrid.u_over_z,
                               dx, dy, dz,
                               i, j, k);

        Gradients_Computation( velocity_y,
                               subgrid.v_over_x,subgrid.v_over_y,
                               subgrid.v_over_z,
                               dx, dy, dz,
                               i, j, k);

        Gradients_Computation( velocity_z,
                               subgrid.w_over_x,subgrid.w_over_y,
                               subgrid.w_over_z,
                               dx, dy, dz,
                               i, j, k);


    }
  }	    
 }   

}
