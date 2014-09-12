#ifndef DYNAMIC_SMAGORINSKY_INL_H
#define DYNAMIC_SMAGORINSKY_INL_H

#include "../Residuals/Residuals-inl.h"

inline void Gradients_Computation( double *** velocity,
                                   double *** velocity_over_x,
                                   double *** velocity_over_y,
                                   double *** velocity_over_z,
                                   double dx, double *dy, double dz,
                                   int i, int j, int k)
{

  // d/dx
  velocity_over_x[k][j][i]=(velocity[k][j][i+1]-velocity[k][j][i-1])/(2.*dx);

  // d/dy 
  velocity_over_y[k][j][i]=(Interpolation_Y( velocity[k][j+1][i],dy[j+1],
                                             velocity[k][j][i],  dy[j])-
                            Interpolation_Y( velocity[k][j][i],  dy[j],
                                             velocity[k][j-1][i],dy[j-1]))/(2.*dy[j]);

  // d/dz
  velocity_over_z[k][j][i] =(velocity[k+1][j][i]-velocity[k-1][j][i])/(2.*dz);

}


#endif
