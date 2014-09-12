/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-20 13:45:04 mike_georgiou>
 *
 *
Coefficient_Calculator.cpp -- This Function computes the coefficients that
are necessary used to fill the inputs of the tridag solver extracted
by the Numerical Recipes
*
* Written on Friday, 30 May 2014.
********************************************/

#include"../Residuals/Residuals-inl.h"
#include<iostream>

using namespace std;


void Coefficient_Calculator(double* coefficients,
                            double ***rho,
                            double ***eddy_viscosity,
                            double Reynolds,
                            double* dy, double dt,
                            double implicit_scheme,
                            int i, int j, int k)

{
  //Computing the delta_y
  double   dy_local[3];
  for (int vi = 0; vi<3; vi++)
    {
      dy_local[vi] = dy[j]+ dy[j+vi-1];

    }



  //computing the viscosity at j\pm 1/2
  double viscosity[2];

  viscosity[0]=1.+Interpolation_Y(eddy_viscosity[k][j][i],dy[j],
                                  eddy_viscosity[k][j-1][i],dy[j-1]);

  // computing the viscosity at j+1/2
  viscosity[1]=1.+Interpolation_Y(eddy_viscosity[k][j+1][i],dy[j+1],
                                  eddy_viscosity[k][j][i],dy[j]);



  //Computing the coefficients.
  coefficients[0] =-(viscosity[1]*(1./(dy_local[0]*dy_local[1])));
                     

  coefficients[1] = +((viscosity[1]*dy_local[0]+ viscosity[0]*dy_local[2])
                      /(dy_local[0]*dy_local[1]*dy_local[2]) );


  coefficients[2] = -(viscosity[0]*(1./(dy_local[2]*dy_local[1])));


  //multiplying the quantities with the constant coefficient that is in
  // front of them
  for (int vi=0; vi<3; vi++)
    coefficients[vi] *= dt/(rho[k][j][i]*Reynolds)*implicit_scheme;

}
