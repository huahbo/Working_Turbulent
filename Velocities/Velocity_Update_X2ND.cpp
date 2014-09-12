/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-11 17:05:07 mike_georgiou>
 *
 *
Velocity_Update_X.cpp -- This function updates the velocity based on eq.64 of
the lessani-papalexandris paper
*
* Written on Tuesday, 29 April 2014.
********************************************/



void Velocity_Update_X2ND(double*** velocity_x, double*** velocity_x_tilda,
                       double*** rho, double*** pressure,
                       double dx, double dt,
                       int ldx, int ldy, int ldz)
{
  for (int k=0; k<ldz; k++){
    for (int j=0; j<ldy; j++){
      for (int i=0; i<ldx; i++){


        velocity_x[k][j][i] = velocity_x_tilda[k][j][i]
          -dt/rho[k][j][i]*
          ( pressure[k][j][i+1]-pressure[k][j][i-1])/(2.*dx);


      }
    }
  }
}
