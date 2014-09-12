/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-03 09:57:49 mike_georgiou>
 *
 *
Initial_Reader.cpp -- This program reads the initial velocity
profiles from a number of data files that will be introduced by the
user in this folder.
*
* Written on Thursday, 15 May 2014.
********************************************/

#include "Initial_Reader.h"

void Initial_Reader(stats variables,
                    domain grid)
{


  Data_Reader( variables.velocity_x,"u_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_y,"v_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_z,"w_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_x_square,"u_square_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_y_square,"v_square_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_z_square,"w_square_time_averaged0.bin",
               grid);



  Data_Reader( variables.velocity_x_y,"u_v_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_x_z,"u_w_time_averaged0.bin",
               grid);

  Data_Reader( variables.velocity_y_z,"v_w_time_averaged0.bin",
               grid);


}
