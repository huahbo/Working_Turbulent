/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-11 15:10:23 mike_georgiou>
 *
 *
Initial_Reader.cpp -- This program reads the initial velocity
profiles from a number of data files that will be introduced by the
user in this folder.
*
* Written on Thursday, 15 May 2014.
********************************************/

#include "Read_Data.h"

using namespace std;

void Read_Data(Ar vars, 
               double *pressure,
               string filename,
               int ldx, int ldy, int ldz)
{
  // Opening the .dat file to read the necessary information
  ifstream input_x;
  input_x.open(filename);

  double temp;
  if(input_x.is_open())
    {

      for (int k = 0; k < ldz; k++){
        for (int j = 0; j <ldy; j++){
          for (int i =0; i < ldx; i++){

            input_x >> temp;//vars.rho[k][j][i] ;
            input_x >> vars.velocity_x[k][j][i]; 
            input_x >> vars.velocity_y[k][j][i]; 
            input_x >> vars.velocity_z[k][j][i]; 
            input_x >> pressure[k*ldy*ldx + (j)*ldx +i +1];
            input_x>>temp;//vars.temperature[k][j][i];

          }
        }
      }
    }
  else {cout << "Unable to open file "<<filename<<endl;}

  input_x.close();
}
