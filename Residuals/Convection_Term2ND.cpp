/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-11 15:03:57 mike_georgiou>
 *
 *
Convection_Term.cpp -- This function will compute the convection term of the
velocity residuals
*
* Written on Thursday, 17 April 2014.
********************************************/

#include"Residuals-inl.h"

double Convection_Term2ND( double*** velocity,
                           double*** flux_x, double*** flux_y,
                           double*** flux_z,
                           double dx, double* dy, double dz,
                           int i, int j, int k)
{

  double convection_terms[3];

  convection_terms[0] = ((velocity[k][j][i+1]+velocity[k][j][i])/2.
                         *flux_x[k][j][i+1]-
                         (velocity[k][j][i]+velocity[k][j][i-1])/2.
                         *flux_x[k][j][i])/(dx);


  convection_terms[1] = 
    (Interpolation_Y(velocity[k][j+1][i],dy[j+1],
                     velocity[k][j][i],dy[j]) * flux_y[k][j+1][i]

     -Interpolation_Y(velocity[k][j][i],dy[j],
                      velocity[k][j-1][i],dy[j-1]) *flux_y[k][j][i])/(2.*dy[j]);



   convection_terms[2] = 
   ((velocity[k+1][j][i]+velocity[k][j][i])/2.
    *flux_z[k+1][j][i]-
    (velocity[k][j][i]+velocity[k-1][j][i])/2.
    *flux_z[k][j][i])/(dz);





  double convection_total =0.;
  for (int i=0; i<3; i++)
    convection_total +=convection_terms[i];


  return convection_total;

}
