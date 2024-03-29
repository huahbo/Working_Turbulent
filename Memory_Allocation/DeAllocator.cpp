
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/


#include "Allocate.h"
#include "Allocate-inl.h"


void DeAllocator( Ar *Arr,
                  int ldz, int ldy, int ldx,
                  int lx, int rx,
                  int ly, int ry,
                  int lz, int rz)
{


  delete [] &Arr->half_dy[-ly];
  delete [] &Arr->y[-ly];

  Free_Matrix(Arr->velocity_x, lx,ly,lz);
  Free_Matrix(Arr->velocity_y, lx,ly,lz);
  Free_Matrix(Arr->velocity_z, lx,ly,lz);

  Free_Matrix(Arr->velocity_x_new,lx,ly,lz);
  Free_Matrix(Arr->velocity_y_new,lx,ly,lz);
  Free_Matrix(Arr->velocity_z_new,lx,ly,lz);

  Free_Matrix(Arr->velocity_x_tilda, lx,0,0);
  Free_Matrix(Arr->velocity_y_tilda, 0,ly,0);
  Free_Matrix(Arr->velocity_z_tilda, 0,0,lz);

  Free_Matrix(Arr->temperature,lx,ly,lz);
  Free_Matrix(Arr->temperature_new, lx,ly,lz);
  Free_Matrix(Arr->temperature_avg,lx,ly,lz);


  Free_Matrix(Arr->rho, lx, ly, lz);
  Free_Matrix(Arr->rho_new, lx, ly, lz);
  Free_Matrix(Arr->rho_old, lx, ly, lz);

  Free_Matrix(Arr->pressure,lx,ly,lz);

  Free_Matrix(Arr->flux_x, 0,0,0);
  Free_Matrix(Arr->flux_y, 0,0,0);
  Free_Matrix(Arr->flux_z, 0,0,0);

  Free_Matrix(Arr->residual_x, 0, 0, 0);
  Free_Matrix(Arr->residual_y, 0, 0, 0);
  Free_Matrix(Arr->residual_z, 0, 0, 0);

  Free_Matrix(Arr->residual_x_old, 0, 0, 0);
  Free_Matrix(Arr->residual_y_old, 0, 0, 0);
  Free_Matrix(Arr->residual_z_old, 0, 0, 0);

  Free_Matrix(Arr->eddy_viscosity, lx, ly, lz);


  Free_Matrix(Arr->velocity_x_avg, 0, 0, 0);
  Free_Matrix(Arr->velocity_y_avg, 0, 0, 0);
  Free_Matrix(Arr->velocity_z_avg, 0, 0, 0);


  Free_Matrix(Arr->velocity_x_square, 0, 0, 0);
  Free_Matrix(Arr->velocity_y_square, 0, 0, 0);
  Free_Matrix(Arr->velocity_z_square, 0, 0, 0);


  Free_Matrix(Arr->velocity_x_y, 0, 0, 0);
  Free_Matrix(Arr->velocity_x_z, 0, 0, 0);
  Free_Matrix(Arr->velocity_y_z, 0, 0, 0);


}
