/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-03 10:09:13 mike_georgiou>   
*
*
Turbulence_Statistics.cpp -- This code will produce the statistical
    quantities that are necessary to describe the turbulent channel flow
*
* Written on Thursday, 28 August 2014.
********************************************/

#include"Turbulence_Statistics.h"

int main()
{

  //Reading domain information
  Information_Reader( &grid.ldx,&grid.ldy, &grid.ldz,
                      &grid.length_x, &grid.length_y, 
                      &grid.length_z);


  //Allocating memory for the arrays that will be used to read the
  //inputs in this program
  Allocator(grid.ldx, grid.ldy, grid.ldz,
            0,0,0,0,0,0,
            &variables);

  //Allocating memory for the arrays that will be used to 
  //save the outputs of the program.
  Allocator_1D( grid.ldy,
                &out);

  //Reading the data from the input files
  Initial_Reader(variables, grid);



  // Analysing the data
  Statistical_Analysis(variables,
                       out,
                       grid);

  //Saving the data
  Output_Data(out, grid);


  //Freeing the allocated memory
  DeAllocator(&variables,
              grid.ldx, grid.ldy, grid.ldz,
              0,0,0,0,0,0);


  DeAllocator_1D(&out);



}
