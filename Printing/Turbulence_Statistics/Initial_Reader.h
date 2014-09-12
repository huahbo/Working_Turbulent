#include "Turbulence_Structure.h"



#ifndef INITIAL_READER_H
#define INITIAL_READER_H

#include<iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <sstream>


using namespace std;




inline void Data_Reader(double*** variable,const char* filename,
                        domain grid)
{


  // Global variables that will be used for the transformation from
  //binary to ascii
  char value[8];
  double result=0.;


  // Opening the .dat file to read the necessary information
 ifstream input_x(filename, ifstream::in | ios::binary);
  //X
  if(input_x.is_open())
    {
      for (int k = 0; k < grid.ldz; k++){
        for (int j = 0; j < grid.ldy; j++){
          for (int i =0; i < grid.ldx; i++){


        input_x.read(value,8);
        memcpy(&result, &value, sizeof(double));
        variable[k][j][i]=result;




          }
        }
      }
    }
  else {cout << "Unable to open file"<<filename<<"\n";}

  input_x.close();


}

#endif
