/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-03 09:59:44 mike_georgiou>   
*
*
Mean_Computation.cpp -- this function computes the means of the three
    velocity components
*
* Written on Thursday, 28 August 2014.
********************************************/


#include "../Turbulence_Structure.h"

void Mean_Computation(stats var,
                      output out,
                      domain grid)

{

  for (int j = 0; j < grid.ldy; j++){
    double sums[9];

    //setting the sum values into zero
    for (int vj=0; vj<9; vj++)
      sums[vj]=0.;
    
    for (int k = 0; k < grid.ldz; k++){
      for (int i = 0; i < grid.ldx; i++){
  
        sums[0]+= var.velocity_x[k][j][i];
        sums[1]+= var.velocity_y[k][j][i];
        sums[2]+= var.velocity_z[k][j][i];

        sums[3]+= var.velocity_x_square[k][j][i];
        sums[4]+= var.velocity_y_square[k][j][i];
        sums[5]+= var.velocity_z_square[k][j][i];

        sums[6]+= var.velocity_x_y[k][j][i];
        sums[7]+= var.velocity_x_z[k][j][i];
        sums[8]+= var.velocity_y_z[k][j][i];

        
      }
    }	    

    out.mean_x[j]=sums[0]/(grid.ldx*grid.ldz);
    out.mean_y[j]=sums[1]/(grid.ldx*grid.ldz);
    out.mean_z[j]=sums[2]/(grid.ldx*grid.ldz);

    //saving 
    out.rms_x[j]=sums[3]/(grid.ldx*grid.ldz);
    out.rms_y[j]=sums[4]/(grid.ldx*grid.ldz);
    out.rms_z[j]=sums[5]/(grid.ldx*grid.ldz);


    out.uv_prime[j]=sums[6]/(grid.ldx*grid.ldz);
    out.uw_prime[j]=sums[7]/(grid.ldx*grid.ldz);
    out.vw_prime[j]=sums[8]/(grid.ldx*grid.ldz);

  }   
  


}
