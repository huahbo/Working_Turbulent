/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-19 14:29:15 mike_georgiou>
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


void Initial_Brown_2(double*** velocity_x, double*** velocity_y,
                     double*** velocity_z,
                     double dx, double* dy, double dz,
                     int ldx, int ldy, int ldz,
                     int index)
{

  static const double pi=4.*atan(1.);


  if (index==1)
    {

      for (int k = 0; k < ldz; k++){

        double y_local =0.;
        for (int j = 0; j < ldy; j++){

          y_local+=dy[j];

          double x_local=0.;
          for (int i = 0; i < ldx; i++){

            x_local += dx/2.;


            velocity_x[k][j][i]=
              sin(2.*pi*(y_local))
              *sin(pi*(x_local))
              *sin(pi*(x_local));


            velocity_y[k][j][i] =
              -sin(2.*pi*(x_local))
              *sin(pi*(y_local))
              *sin(pi*(y_local));


            velocity_z[k][j][i] =0.;

            x_local += dx/2.;

          }
          y_local+=dy[j];
        }
      }
    }

  else if(index==2)
    {
      double z_local=0.;
      for (int k = 0; k < ldz; k++){
        z_local += dz/2.;
        double y_local =0.;
        for (int j = 0; j < ldy; j++){
          y_local+=dy[j];


          for (int i = 0; i < ldx; i++){

            velocity_x[k][j][i]=0.;


            velocity_y[k][j][i] =
              -sin(2.*pi*(z_local))
              *sin(pi*(y_local))
              *sin(pi*(y_local));


            velocity_z[k][j][i] =
              sin(2.*pi*(y_local))
              *sin(pi*(z_local))
              *sin(pi*(z_local));;

          }
          y_local+=dy[j];
        }
        z_local += dz/2.;
      }

    } 
  else
    {
      cout<<"Wrong input for the initialization"<<endl;
    }


    






}
