/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-11 17:07:24 mike_georgiou>
 *
 *
Velocity_Update_Z.cpp -- This function updates the velocity based on eq.64 of
the lessani-papalexandris paper
*
* Written on Tuesday, 29 April 2014.
********************************************/

#include "Velocity_Update.h"


void Velocity_Update_Z2ND(double*** velocity_z, double*** velocity_z_tilda,
                          double*** rho, double*** pressure,
                          double dz, double dt,
                          int ldx, int ldy, int ldz)

{
  for (int k=0; k<ldz; k++){
    for (int j=0; j<ldy; j++){
      for (int i=0; i<ldx; i++){

        velocity_z[k][j][i] = velocity_z_tilda[k][j][i]
          -dt/rho[k][j][i]*
          ( pressure[k+1][j][i]-pressure[k-1][j][i])/(2.*dz);


      }
    }
  }
}
