/*  Last Modified Time-stamp: <2014-09-09 18:03:43 mike_georgiou> */
/*******************************************
 *   Author: Michail Georgiou
 * Allocator->cpp --  In this program I will put all the arrays that i have to
 * allocate memory in my code
 * inside a structure. This will be done in order to make my code more flexible
 *
 * Written on Monday, 17 March 2014
 ********************************************/



#include "Allocate.h"
#include "Allocate-inl.h"

void Allocator_LES_Derivatives(turbulence_derivatives *les, 
                               int ldx, int ldy, int ldz,
                               int lx, int rx,
                               int ly, int ry,
                               int lz, int rz)

{


  //Allocating memory for the velocity derivatives
  les->u_over_x = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->u_over_y = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->u_over_z = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


  les->v_over_x = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->v_over_y = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->v_over_z = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


  les->w_over_x = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->w_over_y = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);

  les->w_over_z = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);
}
