/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-11 16:24:00 mike_georgiou>
 *
 *
Flux.cpp -- This programs computes the fluxes, with second order
accurate precision, in the Y direction. The formula that is used to compute
these fluxes can be found at the Lessani-Papalexandris paper eq.51.

In this case, second order accurate scheme is chosen because I have a
non-uniform grid in this direction.
*
* Written on Thursday, 17 April 2014.
********************************************/


void Flux_Evaluation_Y2ND(double*** flux_y, double*** velocity_y,
                          double*** rho, double*** pressure,
                          double* dy, double dt,
                          int ldx, int ldy, int ldz)
{
  for (int k=0; k<ldz;  k++){
    for (int j=0; j<ldy; j++){
      for (int i=0; i<ldx; i++){

        flux_y[k][j][i] = (rho[k][j][i]*velocity_y[k][j][i]+
                           rho[k][j-1][i]*velocity_y[k][j-1][i])/2.
          -dt*(pressure[k][j][i]-pressure[k][j-1][i])/(2.*dy[j]);

      }
    }
  }

}
