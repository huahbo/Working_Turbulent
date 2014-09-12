/*  Last Modified Time-stamp: <2014-09-09 17:56:13 mike_georgiou> */
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

void Allocator(Ar *Arr, 
               int ldx, int ldy, int ldz,
               int lx, int rx,
               int ly, int ry,
               int lz, int rz)

{

  Arr->half_dy = new double[ldy+ly+ry];  Arr->half_dy+=ly;
  Arr->y = new double[ldy+ly+ry];  Arr->y+=ly;

  //velocity Arrays - Expanded in all directions because of the calculation of
  //the convective fluxes
  Arr->eddy_viscosity = Matrix_Allocator(ldx, ldy, ldz,
                                         lx,rx,
                                         ly,ry,
                                         lz,rz);

  Arr->velocity_x = Matrix_Allocator(ldx,ldy,ldz,
                                     lx,rx,
                                     ly,ry,
                                     lz,rz);

  Arr->velocity_y = Matrix_Allocator(ldx,ldy,ldz,
                                     lx,rx,
                                     ly,ry,
                                     lz,rz);

  Arr->velocity_z = Matrix_Allocator(ldx,ldy,ldz,
                                     lx,rx,
                                     ly,ry,
                                     lz,rz);


  Arr->velocity_x_new = Matrix_Allocator(ldx,ldy,ldz,
                                         lx,rx,
                                         ly,ry,
                                         lz,rz);

  Arr->velocity_y_new = Matrix_Allocator(ldx,ldy,ldz,
                                         lx,rx,
                                         ly,ry,
                                         lz,rz);

  Arr->velocity_z_new = Matrix_Allocator(ldx,ldy,ldz,
                                         lx,rx,
                                         ly,ry,
                                         lz,rz);





  //The expansion in these matrices is arbitrary and has nothing to do with the
  //BC i am using

  Arr->velocity_x_tilda = Matrix_Allocator(ldx,ldy,ldz,
                                           lx,rx,
                                           0,0,
                                           0,0);

  Arr->velocity_y_tilda = Matrix_Allocator(ldx,ldy,ldz,
                                           0,0,
                                           ly,ry,
                                           0,0);

  Arr->velocity_z_tilda = Matrix_Allocator(ldx,ldy,ldz,
                                           0,0,
                                           0,0,
                                           lz,rz);



  /* Temperature - Density - Pressure  Arrays*/
  Arr->temperature = Matrix_Allocator(ldx,ldy,ldz,
                                      lx,rx,
                                      ly,ry,
                                      lz,rz);


  Arr->temperature_new = Matrix_Allocator(ldx,ldy,ldz,
                                          lx,rx,
                                          ly,ry,
                                          lz,rz);

  Arr->temperature_avg = Matrix_Allocator(ldx,ldy,ldz,
                                          lx,rx,
                                          ly,ry,
                                          lz,rz);


  Arr->rho =   Matrix_Allocator(ldx,ldy,ldz,
                                lx,rx,
                                ly,ry,
                                lz,rz);


  Arr->rho_old = Matrix_Allocator(ldx,ldy,ldz,
                                  lx,rx,
                                  ly,ry,
                                  lz,rz);

  Arr->rho_new =  Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


  Arr->pressure = Matrix_Allocator(ldx,ldy,ldz,
                                   lx,rx,
                                   ly,ry,
                                   lz,rz);


  /*Fluxes*/
  Arr->flux_z = Matrix_Allocator(ldx, ldy, ldz+1,
                                       0,0,
                                       0,0,
                                       0,0);


  Arr->flux_x = Matrix_Allocator(ldx+1, ldy, ldz,
                                       0,0,
                                       0,0,
                                       0,0);

  Arr->flux_y = Matrix_Allocator(ldx, ldy+1, ldz,
                                       0,0,
                                       0,0,
                                       0,0);

  /* Residuals */
  Arr->residual_x = Matrix_Allocator(ldx, ldy, ldz,
                                     0, 0,
                                     0, 0,
                                     0, 0);

  Arr->residual_y =  Matrix_Allocator(ldx, ldy, ldz,
                                      0, 0,
                                      0, 0,
                                      0, 0);

  Arr->residual_z = Matrix_Allocator(ldx, ldy, ldz,
                                     0, 0,
                                     0, 0,
                                     0, 0);

  Arr->residual_z_old =  Matrix_Allocator(ldx, ldy, ldz,
                                          0, 0,
                                          0, 0,
                                          0, 0);


  Arr->residual_x_old = Matrix_Allocator(ldx, ldy, ldz,
                                         0, 0,
                                         0, 0,
                                         0, 0);

  Arr->residual_y_old =  Matrix_Allocator(ldx, ldy, ldz,
                                          0, 0,
                                          0, 0,
                                          0, 0);



  Arr->velocity_x_avg = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_y_avg = Matrix_Allocator(ldx,ldy,ldz,
                                         0,0,
                                         0,0,
                                         0,0);

  Arr->velocity_z_avg = Matrix_Allocator(ldx,ldy,ldz,
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

  //Reynolds stresses
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
