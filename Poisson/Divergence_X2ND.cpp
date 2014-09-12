/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-11 16:58:03 mike_georgiou>
 *
 *
Divergence_X.cpp -- This program computes the X-component of the divergence
that is used in the Right_Hand_Side_Poisson.cpp program
*
* Written on Friday, 25 April 2014.
********************************************/



double Divergence_X2ND(double*** velocity_x, double*** rho,
                    double dx,
                    int i, int j, int k)
{

  double divergence_x= (rho[k][j][i+1]*velocity_x[k][j][i+1]-
                        rho[k][j][i-1]*velocity_x[k][j][i-1])/(2.*dx);

  return divergence_x;

}
