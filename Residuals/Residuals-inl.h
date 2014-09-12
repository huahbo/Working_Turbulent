#ifndef SOLVER_RESIDUALS_INL_H
#define SOLVER_RESIDUALS_INL_H

#include <iostream>
using namespace std;

inline double Interpolation(double value_right, double value_left)
{
  return   0.5*( value_right+value_left);
}

inline double Derivative( double value_right, double value_left,
                          double dx, int order)
{
  return (1./(dx*order))*( value_right-value_left);
}


//Interpolating and differentiating in the non-uniform direction.
inline double Interpolation_Y(double value_right, double dy_right,
                              double value_left, double dy_left)
{
  double coefficient[2];
  coefficient[0] = dy_left/(dy_left+dy_right); // Right coeff
  coefficient[1] = dy_right/(dy_left+dy_right); // left coeff

  return coefficient[0]*value_right + coefficient[1]*value_left;
}


#endif
