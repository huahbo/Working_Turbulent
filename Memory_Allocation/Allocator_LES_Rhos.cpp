/*  Last Modified Time-stamp: <2014-09-09 18:03:56 mike_georgiou> */
/*******************************************
 *   Author: Michail Georgiou
 * Allocator->cpp --  In this program I will put all the arrays that i have to
 * allocate memory in my code
 * inside a structure. This will be done in order to make my code more flexible
 *
 * Written on Monday, 17 March 2014
 ********************************************/
#include"../Struct.h"
#include "Allocate.h"

void Allocator_LES_Rhos(turbulence_rhos *les,
                        int ldx, int ldy, int ldz,
                        int lx, int rx,
                        int ly, int ry,
                        int lz, int rz)

{

  //Allocating memory for the alpha variable
  les->x = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->y = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->z = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


  les->rho = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


}
