/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-11 16:58:05 mike_georgiou>
 *
 *
Divergence_X.cpp -- This program computes the X-component of the divergence
that is used in the Right_Hand_Side_Poisson.cpp program
*
* Written on Friday, 25 April 2014.
********************************************/



double Divergence_Z2ND(double*** velocity_z, double*** rho,
                    double dz,
                    int i, int j, int k)
{



  double divergence_z= (rho[k+1][j][i]*velocity_z[k+1][j][i]-
                        rho[k-1][j][i]*velocity_z[k-1][j][i])/(2.*dz);


  return divergence_z;
}
