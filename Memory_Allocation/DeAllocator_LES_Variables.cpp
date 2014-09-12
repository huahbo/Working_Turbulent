
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/


#include "Allocate.h"
#include "Allocate-inl.h"


void DeAllocator_LES_Variables( turbulence_variables *les,
                                int ldz, int ldy, int ldx,
                                int lx, int rx,
                                int ly, int ry,
                                int lz, int rz)
{

  //Deallocaing memory for the alpha variable
  Free_Matrix(les->xx, lx,ly,lz);
  Free_Matrix(les->xy, lx,ly,lz);
  Free_Matrix(les->xz, lx,ly,lz);


  Free_Matrix(les->yy, lx,ly,lz);
  Free_Matrix(les->yz, lx,ly,lz);
  Free_Matrix(les->zz, lx,ly,lz);



}
