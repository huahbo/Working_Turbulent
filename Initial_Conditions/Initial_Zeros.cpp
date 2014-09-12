/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-19 12:08:23 mike_georgiou>
 *
 *
Initial_Brown_2.cpp --
*
* Written on Thursday, 22 May 2014.
********************************************/


#include <math.h>
#include <iostream>
#include <stdio.h>
using namespace std;


void Initial_Zeros(double*** velocity_x, double*** velocity_y,
                   double*** velocity_z,
                   double dx, double* dy,
                   int ldx, int ldy, int ldz)
{


  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){

        velocity_x[k][j][i]=0.;
        velocity_y[k][j][i] =0.;
        velocity_z[k][j][i] =0.;

      }
    }
  }

}
