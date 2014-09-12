/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 12:57:08 mike_georgiou>   
*
*
Filtering_Alphas.cpp -- This function computes the filtered alphas
    and the velocity spatial derivatives
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include"../Struct.h"
#include "Filtering.h"
void Filtering_Derivatives(turbulence_derivatives subgrid,
                           turbulence_derivatives filtered,
                           int ldx, int ldy, int ldz)
{


for (int k = 0; k < ldz; k++){
  for (int j = 0; j < ldy; j++){
    for (int i = 0; i < ldx; i++){
      
      //Filtering the derivatives of u      
      Filtering(subgrid.u_over_x, filtered.u_over_x,
                i, j, k);

      Filtering(subgrid.u_over_y, filtered.u_over_y,
                i, j, k);

      Filtering(subgrid.u_over_z, filtered.u_over_z,
                i, j, k);


      //Filtering the derivatives of v      
      Filtering(subgrid.v_over_x, filtered.v_over_x,
                i, j, k);

      Filtering(subgrid.v_over_y, filtered.v_over_y,
                i, j, k);

      Filtering(subgrid.v_over_z, filtered.v_over_z,
                i, j, k);

      //Filtering the derivatives of w      
      Filtering(subgrid.w_over_x, filtered.w_over_x,
                i, j, k);

      Filtering(subgrid.w_over_y, filtered.w_over_y,
                i, j, k);

      Filtering(subgrid.w_over_z, filtered.w_over_z,
                i, j, k);

    }
  }	    
 }   

}
