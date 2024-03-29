
#include"../Turbulence_Structure.h"


#ifndef ALLOCATOR_H
#define ALLOCATOR_H

double *** Matrix_Allocator(int ldx, int ldy, int ldz,
                            int x_left,int x_right,
                            int y_left,int y_right,
                            int z_left,int z_right);

void Free_Matrix(double ***pA,
                 int x_left, int y_left, int z_left);

#endif
