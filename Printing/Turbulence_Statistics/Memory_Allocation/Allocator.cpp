/*  Last Modified Time-stamp: <2014-09-03 10:04:44 mike_georgiou> */
/*******************************************
 *   Author: Michail Georgiou
 * Allocator->cpp --  In this program I will put all the arrays that i have to
 * allocate memory in my code
 * inside a structure. This will be done in order to make my code more flexible
 *
 * Written on Monday, 17 March 2014
 ********************************************/

#include"Allocator.h"

void Allocator( int ldx, int ldy, int ldz,
                int lx, int rx,
                int ly, int ry,
                int lz, int rz,
                stats *Arr)

{

  //velocity Arrays - Expanded in all directions because of the calculation of
  //the convective fluxes

  Arr->velocity_x = Matrix_Allocator(ldx,ldy,ldz,
                                     0,0,
                                     0,0,
                                     0,0);
  Arr->velocity_y = Matrix_Allocator(ldx,ldy,ldz,
                                     0,0,
                                     0,0,
                                     0,0);

  Arr->velocity_z = Matrix_Allocator(ldx,ldy,ldz,
                                     0,0,
                                     0,0,
                                     0,0);


  Arr->velocity_x_square = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_y_square = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_z_square = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);


  Arr->velocity_x_y = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_x_z = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_y_z = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

}
