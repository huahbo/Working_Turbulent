/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-08-28 15:12:59 mike_georgiou>   
*
*
Statistical_Analysis.cpp -- This function will compute the means and the
   rms of the velocity field of my problem
*
* Written on Thursday, 28 August 2014.
********************************************/

#include "../Turbulence_Structure.h"
#include "Statistical_Analysis.h"

void Statistical_Analysis(stats variables,
                          output out,
                          domain grid)
{

  //Creation of three variables that will save the mean of <u*u>
  // They will be deleted at the end of the program.


  //Computing the means of the velocity fields
  Mean_Computation(variables,
                   out,
                   grid);


  //Reynolds Stresses computation
  RMS_Computation( out,
                   grid);


}
