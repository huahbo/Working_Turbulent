/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-03 10:01:07 mike_georgiou>
 *
 *
RMS_Computation.cpp -- This function computes the reynolds stresses
*
* Written on Thursday, 28 August 2014.
********************************************/

#include"../Turbulence_Structure.h"
#include <math.h>
void RMS_Computation(output out,
                     domain grid)
{



    for (int j = 0; j < grid.ldy; j++){

        out.rms_x[j]-=out.mean_x[j]*out.mean_x[j];
        out.rms_y[j]-=out.mean_y[j]*out.mean_y[j];
        out.rms_z[j]-=out.mean_z[j]*out.mean_z[j];

        out.uv_prime[j]-=out.mean_x[j]*out.mean_y[j];
        out.uw_prime[j]-=out.mean_x[j]*out.mean_z[j];
        out.vw_prime[j]-=out.mean_y[j]*out.mean_z[j];

        
    }


    for (int j = 0; j < grid.ldy; j++){

      out.rms_x[j]=sqrt(out.rms_x[j]);
      out.rms_y[j]=sqrt(out.rms_y[j]);
      out.rms_z[j]=sqrt(out.rms_z[j]);
        
    }


}

