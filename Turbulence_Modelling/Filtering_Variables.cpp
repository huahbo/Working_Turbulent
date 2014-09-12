/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 14:42:15 mike_georgiou>   
*
*
Filtering_Alphas.cpp -- This function computes the filtered alphas
    and the velocity spatial derivatives
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include"../Struct.h"
#include "Filtering.h"
void Filtering_Variables(turbulence_variables subgrid,
                      turbulence_variables filtered,
                      int ldx, int ldy, int ldz)
{


for (int k = 0; k < ldz; k++){
  for (int j = 0; j < ldy; j++){
    for (int i = 0; i < ldx; i++){
      

      //filtering alphas, xx xy xz
      Filtering(subgrid.xx, filtered.xx,i, j, k);
      Filtering(subgrid.xy, filtered.xy,i, j, k);
      Filtering(subgrid.xz, filtered.xz,i, j, k);


      //filtering alphas, yy yz zz
      Filtering(subgrid.yy, filtered.yy,i, j, k);
      Filtering(subgrid.yz, filtered.yz,i, j, k);
      Filtering(subgrid.zz, filtered.zz,i, j, k);




    }
  }	    
 }   
}
