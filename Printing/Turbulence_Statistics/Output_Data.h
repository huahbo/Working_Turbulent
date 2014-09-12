#ifndef OUTPUT_DATA_H
#define OUTPUT_DATA_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


inline void Save_Data(double *output,
                      int ldy,
                      string filename)
{

  ofstream  outfile;
  outfile.open(filename, ios::binary);

    for (int j = 0; j < ldy; j++)
      {
        outfile.write( (char*)&output[j],sizeof(double));
      }


    outfile.close();

}

#endif
