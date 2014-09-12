/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-09 17:09:17 mike_georgiou>
 *
 *
Flux.cpp -- This programs computes the fluxes, with fourth order
accurate precision, in the Z direction. The formula that is used to compute
these fluxes can be found at the Lessani-Papalexandris paper eq.63
*
* Written on Thursday, 17 April 2014.
********************************************/

void Flux_Evaluation_X2ND(double*** flux_x, double*** velocity_x,
                          double*** rho, double*** pressure,
                          double dx, double dt,
                          int ldx, int ldy, int ldz)
{

  for (int  k=0; k<ldz; k++){
    for (int  j=0; j<ldy; j++){
      for (int  i=0; i<ldx; i++){

        flux_x[k][j][i] = (rho[k][j][i]*velocity_x[k][j][i]+
                           rho[k][j][i-1]*velocity_x[k][j][i-1])/2.
          -dt * (pressure[k][j][i]-pressure[k][j][i-1])/dx;



      }
    }
  }

}
