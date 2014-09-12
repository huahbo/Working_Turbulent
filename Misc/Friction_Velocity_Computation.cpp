/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-10 13:10:11 mike_georgiou>   
*
*
Friction_Velocity_Computation.cpp -- This function computes u_tau at the bottom
    and the top wall based on the relation that bamdad uses.
*
* Written on Wednesday,  3 September 2014.
********************************************/

#include"../Struct.h"
#include <math.h>
void Friction_Velocity_Computation(Ar arrays,
                                   double *friction_velocity,
                                   double Reynolds,
                                   double dx,  double dz,
                                   int ldx, int ldy, int ldz)
{

  //Computation of the wall shear stresses
  double sum[2]; sum[0]=0. , sum[1]=0.; 
  double rho_avg[2]; rho_avg[0]=0.; rho_avg[1]=0.;

    for (int k = 0; k < ldz; k++){
      for (int i = 0; i < ldx; i++){
        
        sum[0]+=
          arrays.rho[k][0][i]*(1.)
          *(arrays.velocity_x[k][0][i]/(arrays.half_dy[0]));


        sum[1]+=
          arrays.rho[k][ldy][i]*(1.)
          *(arrays.velocity_x[k][ldy][i]/(arrays.half_dy[ldy]));

        
        rho_avg[0]+=arrays.rho[k][0][i];
        rho_avg[1]+=arrays.rho[k][ldy][i];

      }
    }	    

    double shear_stress[2];
    for (int vi=0; vi<2; vi++)
      {
        shear_stress[vi]=sum[vi]/(ldx*ldz);
        rho_avg[vi]/=(ldx*ldz);

        friction_velocity[vi]=sqrt(fabs(shear_stress[vi])/rho_avg[vi]/Reynolds);
      }

}
