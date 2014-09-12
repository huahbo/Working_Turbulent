
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/


#include "Allocate.h"
#include "Allocate-inl.h"


void DeAllocator_LES_Rhos( turbulence_rhos *les,
                  int ldz, int ldy, int ldx,
                  int lx, int rx,
                  int ly, int ry,
                  int lz, int rz)
{


  //Deallocating the memory of the velocity derivatives
  Free_Matrix(les->x, lx,ly,lz);
  Free_Matrix(les->y, lx,ly,lz);
  Free_Matrix(les->z, lx,ly,lz);

  Free_Matrix(les->rho, lx,ly,lz);


}
