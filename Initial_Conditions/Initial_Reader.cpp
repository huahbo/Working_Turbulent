/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-29 15:01:39 mike_georgiou>
 *
 *
Initial_Reader.cpp -- This program reads the initial velocity
profiles from a number of data files that will be introduced by the
user in this folder.
*
* Written on Thursday, 15 May 2014.
********************************************/

#include "Initial_Reader.h"

#include <iostream>
#include <cstring>

using namespace std;

void Initial_Reader(double*** velocity_x, double*** velocity_y,
                    double*** velocity_z,double*** pressure,
                    int left_x, int right_x,
                    int left_y, int right_y,
                    int left_z, int right_z,
                    int ldx, int ldy, int ldz)
{

  // Global variables that will be used for the transformation from
  //binary to ascii
  char value[8];
  double result=0.;


  // Opening the .dat file to read the necessary information
  ifstream input_x("Input_Velocity_X.bin", ifstream::in | ios::binary);
  //X
  if(input_x.is_open())
    {
      for (int k = -left_z; k < ldz+right_z; k++){
        for (int j = -left_y; j < ldy+right_y; j++){
          for (int i = -left_x; i < ldx+right_x; i++){


        input_x.read(value,8);
        memcpy(&result, &value, sizeof(double));
        velocity_x[k][j][i]=result;

          }
        }
      }
    }
  else {cout << "Unable to open file X\n";}

  input_x.close();
  //Y
  ifstream input_y("Input_Velocity_Y.bin", ifstream::in);
  if(input_y.is_open())
    {


      for (int k = -left_z; k < ldz+right_z; k++){
        for (int j = -left_y; j < ldy+right_y; j++){
          for (int i = -left_x; i < ldx+right_x; i++){


        input_y.read(value,8);
        memcpy(&result, &value, sizeof(double));
        velocity_y[k][j][i]=result;

          }
        }
      }
    }
  else {cout << "Unable to open file Y\n";}

  input_y.close();


  //Z
  ifstream input_z("Input_Velocity_Z.bin", ifstream::in);
  if(input_z.is_open())
    {

      for (int k = -left_z; k < ldz+right_z; k++){
        for (int j = -left_y; j < ldy+right_y; j++){
          for (int i = -left_x; i < ldx+right_x; i++){


        input_z.read(value,8);
        memcpy(&result, &value, sizeof(double));
        velocity_z[k][j][i]=result;

          }
        }
      }
    }
  else{ cout << "Unable to open file Z\n";}
  input_z.close();

  //Pressure
  ifstream input_p("Input_Pressure.bin", ifstream::in);
  if(input_p.is_open())
    {

      for (int k = -left_z; k < ldz+right_z; k++){
        for (int j = -left_y; j < ldy+right_y; j++){
          for (int i = -left_x; i < ldx+right_x; i++){


        input_p.read(value,8);
        memcpy(&result, &value, sizeof(double));
        pressure[k][j][i]=result;

          }
        }
      }
    }
  else{ cout << "Unable to open file P\n";}
  input_p.close();


}
