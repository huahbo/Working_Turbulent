/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 12:37:52 mike_georgiou>   
*
*
Deallocator_LES.cpp -- 
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include "../Struct.h"
#include"Allocate.h"
#include "DeAllocator_LES.h"


void DeAllocator_LES(turbulence_derivatives *subgrid,
                     turbulence_derivatives *filtered,
                     turbulence_variables *alpha,
                     turbulence_variables *alpha_filtered,
                     turbulence_variables *beta,
                     turbulence_variables *mi,
                     turbulence_variables *lambda,
                     turbulence_variables *rho_uu,
                     turbulence_variables *rho_uu_filtered,
                     turbulence_rhos *subgrid_rho,
                     turbulence_rhos *filtered_rho,
                     int ldx, int ldy, int ldz,
                     int left_x, int right_x,
                     int left_y, int right_y,
                     int left_z, int right_z)
{




  DeAllocator_LES_Derivatives(subgrid, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Derivatives(filtered, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);


  DeAllocator_LES_Variables(alpha, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Variables(alpha_filtered, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);


  DeAllocator_LES_Variables(beta, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Variables(mi, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Variables(lambda, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Variables(rho_uu, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Variables(rho_uu_filtered, 
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Rhos(subgrid_rho,
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

  DeAllocator_LES_Rhos(filtered_rho,
                  ldx,ldy,ldz,
                  left_x,right_x,
                  left_y,right_y,
                  left_z,right_z);

}
