#ifndef INTERMEDIATE_VELOCITY_H
#define INTERMEDIATE_VELOCITY_H

#include<new>
#include"../Residuals/residual_initialization.h"



void Coefficient_Calculator(double* coefficients,
                            double ***rho,
                            double*** eddy_viscosity,
                            double Reynolds,
                            double* dy, double dt,
                            double implicit_scheme,
                            int i, int j, int k);


void tridag (double* a, double* b, double* c, double* r, double* u, int n,
             double* gam, int& flag, int x, int z);



inline double Derivative(double pressure_right, double pressure_left,
                         double dx, int order)
{

  return 1./(order * dx)*( (pressure_right) - (pressure_left));

}


inline double Interpolation_Y(double value_right, double dy_right,
                              double value_left, double dy_left)
{
  double coefficient[2];
  coefficient[0] = dy_left/(dy_left+dy_right); // Right coeff
  coefficient[1] = dy_right/(dy_left+dy_right); // left coeff

  return coefficient[0]*value_right+
    coefficient[1]*value_left;
}

inline double Interpolation(double value_right, double value_left)
{
  return   0.5*( value_right+value_left);
}



#endif
