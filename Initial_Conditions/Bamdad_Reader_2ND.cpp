/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-20 16:52:04 mike_georgiou>
 *
 *
Initial_Reader.cpp -- This program reads the initial velocity
profiles from a number of data files that will be introduced by the
user in this folder.
*
* Written on Thursday, 15 May 2014.
********************************************/

#include "Initial_Reader.h"

using namespace std;

void Bamdad_Reader_2ND(double*** velocity_x, double*** velocity_y,
                       double*** velocity_z, double *pressure,
                       int ldx, int ldy, int ldz)
{



  // Opening the .dat file to read the necessary information
  ifstream input_x("ini_sol_pc.out");
  //X
  if(input_x.is_open())
    {
      double temp;
      for (int k = 0; k < ldz; k++){
        for (int j = 0; j < ldy; j++){
          for (int i =0; i < ldx; i++){

            input_x>>temp;
            input_x >> velocity_x[k][j][i]; 
            input_x >> velocity_y[k][j][i]; 
            input_x >> velocity_z[k][j][i]; 
            input_x >> pressure[k*ldy*ldx + j*ldx +i +1];

            input_x>>temp;

          }
        }
      }
    }
  else {cout << "Unable to open file X\n";}


  //subtracting the mean of the pressure from the pressure field
      for (int k = 0; k < ldz; k++){
        for (int j = 0; j < ldy; j++){
          for (int i =0; i < ldx; i++){

            
            pressure[k*ldy*ldx + j*ldx +i +1]=
              pressure[k*ldy*ldx + j*ldx +i +1];

       
          }
        }
      }
    




  input_x.close();
}
