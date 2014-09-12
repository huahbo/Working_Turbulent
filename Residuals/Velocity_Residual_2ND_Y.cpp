/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-20 12:55:13 mike_georgiou>
 *
 *
Velocity_Residual_X_Implicit.cpp -- This program will compute the
velocity  residuals of the X-momentum equation. These residuals will
be used for the implicit calculation of velocity_tilda.
*
* Written on Wednesday, 28 May 2014.
********************************************/

#include"Velocity_Residual.h"


void Velocity_Residual_2ND_Y( double*** residual_y,
                              double*** velocity_y,
                              double*** flux_x, double*** flux_y,
                              double*** flux_z,
                              double ***eddy_viscosity,
                              double Reynolds,
                              double source,
                              double dx, double* dy, double dz,
                              int i, int j, int k,
                              double* explicit_term)
{

  //Computing the convection term of the residuals by calling the
  //Convection Term
  double  convection_term= Convection_Term2ND(velocity_y,
                                              flux_x, flux_y,flux_z,
                                              dx, dy, dz,
                                              i, j, k);

  double viscous_term=  Viscous_Term2ND(velocity_y,
                                        eddy_viscosity,
                                        explicit_term,
                                        Reynolds,
                                        dx, dy, dz,
                                        i, j, k);


  residual_y[k][j][i] = -convection_term + viscous_term + source;



}
