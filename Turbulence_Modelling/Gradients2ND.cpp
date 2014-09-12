/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-08 17:00:30 mike_georgiou>
 *
 *
Gradients.cpp -- This function will compute the gradients  velocity
components
*
* Written on Thursday, 19 June 2014.
********************************************/
#include "../Residuals/Residuals-inl.h"

void Gradients2ND(double*** velocity,
                  double* velocity_over_x,  double* velocity_over_y,
                  double* velocity_over_z,
                  double dx, double* dy, double dz,
                  int i, int j, int k)

{

  // d/dx
  *velocity_over_x=(velocity[k][j][i+1]-velocity[k][j][i-1])/(2.*dx);



  // d/dy 
  *velocity_over_y=(Interpolation_Y( velocity[k][j+1][i],dy[j+1],
                                     velocity[k][j][i],  dy[j])-
                    Interpolation_Y( velocity[k][j][i],  dy[j],
                                     velocity[k][j-1][i],dy[j-1]))/(2.*dy[j]);


  // d/dz
  *velocity_over_z =(velocity[k+1][j][i]-velocity[k-1][j][i])/(2.*dz);

}
