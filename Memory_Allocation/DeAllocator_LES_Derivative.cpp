
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/


#include "Allocate.h"
#include "Allocate-inl.h"


void DeAllocator_LES_Derivatives( turbulence_derivatives *les,
                                  int ldz, int ldy, int ldx,
                                  int lx, int rx,
                                  int ly, int ry,
                                  int lz, int rz)
{


  //Deallocating the memory of the velocity derivatives
  Free_Matrix(les->u_over_x, lx,ly,lz);
  Free_Matrix(les->u_over_y, lx,ly,lz);
  Free_Matrix(les->u_over_z, lx,ly,lz);


  Free_Matrix(les->v_over_x, lx,ly,lz);
  Free_Matrix(les->v_over_y, lx,ly,lz);
  Free_Matrix(les->v_over_z, lx,ly,lz);

  Free_Matrix(les->w_over_x, lx,ly,lz);
  Free_Matrix(les->w_over_y, lx,ly,lz);
  Free_Matrix(les->w_over_z, lx,ly,lz);

}
