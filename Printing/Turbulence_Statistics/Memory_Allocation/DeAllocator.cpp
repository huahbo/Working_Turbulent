
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/

#include"Allocator.h"


void DeAllocator( stats *Arr,
                  int ldz, int ldy, int ldx,
                  int lx, int rx,
                  int ly, int ry,
                  int lz, int rz)
{



  Free_Matrix(Arr->velocity_x,  0, 0, 0);
  Free_Matrix(Arr->velocity_y,  0, 0, 0);
  Free_Matrix(Arr->velocity_z,  0, 0, 0);



  Free_Matrix(Arr->velocity_x_square, 0, 0, 0);
  Free_Matrix(Arr->velocity_y_square, 0, 0, 0);
  Free_Matrix(Arr->velocity_z_square, 0, 0, 0);

  Free_Matrix(Arr->velocity_x_y, 0, 0, 0);
  Free_Matrix(Arr->velocity_x_z, 0, 0, 0);
  Free_Matrix(Arr->velocity_y_z, 0, 0, 0);


}
