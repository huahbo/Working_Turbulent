/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-08-13 12:02:42 mike_georgiou>
 *
 *
Divergence_Y.cpp -- This function computes the y component of the
divergence that gonna be used in the Right_Hand_Side_Poisson function.
Because I am having non-uniform grid in this direction I ll use second  order
accurate scheme.

* Written on Friday, 25 April 2014.
********************************************/



double Divergence_Y2ND(double*** velocity_y, double*** rho,
                    double* dy,
                    int i, int j, int k)
{

  double divergence_y= (rho[k][j+1][i]*velocity_y[k][j+1][i]-
                        rho[k][j-1][i]*velocity_y[k][j-1][i])
    /((dy[j-1]+2.*dy[j]+dy[j+1]));


  return divergence_y;
}
