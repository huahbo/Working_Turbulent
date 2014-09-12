/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-04 13:37:07 mike_georgiou>   
*
*
Viscous_Term2ND.cpp -- This function computes the viscous term of the velocity
residuals
*
* Written on Tuesday, 19 August 2014.
********************************************/

#include "Residuals-inl.h"

double Viscous_Term2ND(double ***velocity,
                       double ***eddy_viscosity,
                       double *explicit_term,
                       double Reynolds,
                       double dx, double* dy, double dz,
                       int i, int j, int k)
{

  double viscous_terms[3];
  double viscosity[2];


  // Second derivative over X


  //For now i have constant viscosity so i ll just add the eddy viscosity to
  //unity.  

  //computing the viscosity at i-1/2
  viscosity[0]=1.+Interpolation(eddy_viscosity[k][j][i],
                               eddy_viscosity[k][j][i-1]);

  // computing the viscosity at i+1/2
  viscosity[1]=1.+Interpolation(eddy_viscosity[k][j][i+1],
                               eddy_viscosity[k][j][i]);


  // Computing the viscous component in the x direction.
  viscous_terms[0]=
    1./dx*(viscosity[1]*(velocity[k][j][i+1]-velocity[k][j][i])/dx
           -viscosity[0]*(velocity[k][j][i]-velocity[k][j][i-1])/dx);



  // Second derivative over Y



  //computing the viscosity at j-1/2
  viscosity[0]=1.+Interpolation_Y(eddy_viscosity[k][j][i],dy[j],
                                  eddy_viscosity[k][j-1][i],dy[j-1]);

  // computing the viscosity at j+1/2
  viscosity[1]=1.+Interpolation_Y(eddy_viscosity[k][j+1][i],dy[j+1],
                                  eddy_viscosity[k][j][i],dy[j]);


  // Computing the viscous component in the y direction.
  // This term will be placed in the lhs of the equation
  // since the u_tilda is being computed implicitly along the y
  viscous_terms[1]=
    1./(2.*dy[j])*(viscosity[1]*(velocity[k][j+1][i]-velocity[k][j][i])
                   /(dy[j]+dy[j+1])
                   -viscosity[0]*(velocity[k][j][i]-velocity[k][j-1][i])
                   /(dy[j]+dy[j-1]));
  


  // Second derivative over Z



  //computing the viscosity at k-1/2
  viscosity[0]=1.+Interpolation(eddy_viscosity[k][j][i],
                                eddy_viscosity[k-1][j][i]);

  // computing the viscosity at k+1/2
  viscosity[1]=1.+Interpolation(eddy_viscosity[k+1][j][i],
                                eddy_viscosity[k][j][i]);




  // Computing the viscous components in the z direction
  viscous_terms[2] = 
    1./dz*(viscosity[1]*(velocity[k+1][j][i]-velocity[k][j][i])/dz
           -viscosity[0]*(velocity[k][j][i]-velocity[k-1][j][i])/dz);


  double viscous_total=(viscous_terms[0]+viscous_terms[2])/Reynolds;


  //Returning the explicit term also
  *explicit_term = viscous_terms[1]/Reynolds;

  return viscous_total;

}
