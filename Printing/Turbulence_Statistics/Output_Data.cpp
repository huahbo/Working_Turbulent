/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-03 10:02:29 mike_georgiou>   
*
*
Output_Data.cpp -- This program will save the computed data into
    binary format and output it
*
* Written on Friday, 29 August 2014.
********************************************/


#include "Output_Data.h"
#include "Turbulence_Structure.h"
void Output_Data(output out,
                 domain grid)
{
  string filename="mean_x.bin";
  Save_Data(out.mean_x,
            grid.ldy,
            filename);

  filename.clear();
  filename="mean_y.bin";
  Save_Data(out.mean_y,
            grid.ldy,
            filename);


  filename.clear();
  filename="mean_z.bin";
  Save_Data(out.mean_z,
            grid.ldy,
            filename);


  filename.clear();
  filename="rms_x.bin";
  Save_Data(out.rms_x,
            grid.ldy,
            filename);


  filename.clear();
  filename="rms_y.bin";
  Save_Data(out.rms_y,
            grid.ldy,
            filename);

  filename.clear();
  filename="rms_z.bin";
  Save_Data(out.rms_z,
            grid.ldy,
            filename);



  filename.clear();
  filename="uv_prime.bin";
  Save_Data(out.uv_prime,
            grid.ldy,
            filename);


  filename.clear();
  filename="uw_prime.bin";
  Save_Data(out.uw_prime,
            grid.ldy,
            filename);

  filename.clear();
  filename="vw_prime.bin";
  Save_Data(out.vw_prime,
            grid.ldy,
            filename);


}
