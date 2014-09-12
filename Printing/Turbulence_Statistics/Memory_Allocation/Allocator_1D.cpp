/*  Last Modified Time-stamp: <2014-09-03 09:56:42 mike_georgiou> */
/*******************************************
 *   Author: Michail Georgiou
 * Allocator->cpp --  In this program I will put all the arrays that i have to
 * allocate memory in my code
 * inside a structure. This will be done in order to make my code more flexible
 *
 * Written on Monday, 17 March 2014
 ********************************************/

#include"Allocator.h"

void Allocator_1D(  int ldy,
                    output *out)

{

  //velocity Arrays - Expanded in all directions because of the calculation of
  //the convective fluxes
  out->mean_x=new double[ldy];
  out->mean_y=new double[ldy];
  out->mean_z=new double[ldy];


  out->rms_x=new double[ldy];
  out->rms_y=new double[ldy];
  out->rms_z=new double[ldy];



  out->uv_prime=new double[ldy];
  out->uw_prime=new double[ldy];
  out->vw_prime=new double[ldy];


}
