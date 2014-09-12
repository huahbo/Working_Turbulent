#ifndef LES_MODELLING2ND_H
#define LES_MODELLING2ND_H


#include<math.h>
void Gradients2ND(double*** velocity,
                  double* velocity_over_x,  double* velocity_over_y,
                  double* velocity_over_z,
                  double dx, double* dy, double dz,
                  int i, int j, int k);

#endif
