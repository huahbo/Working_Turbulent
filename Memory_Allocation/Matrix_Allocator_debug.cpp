/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-09 17:52:03 mike_georgiou>
 *
 *
Matrix_Allocator.cpp -- This function allocates contiguous memory for my 3D
matrice. In addition, it introduces a number of ghost cells, which is given as
an input in all the edges of my domain
*
* Written on Tuesday, 29 April 2014.
********************************************/

#include<cstdlib>

double *** Matrix_Allocator_debug(int ldx, int ldy, int ldz,
                                  int x_left,int x_right,
                                  int y_left,int y_right,
                                  int z_left,int z_right)
{

  double ***mu;

  mu = new double**[ldz + z_left+z_right];

  for (int i = 0; i < ldz + z_left+z_right; i++) {

    mu[i] = new double*[ldy+y_left+y_right];
    for (int j = 0; j < ldy +y_left+y_right ; j++) {

      mu[i][j] = new double[ldx +x_left+x_right];

      if(x_left !=0)mu[i][j]+=x_left;
    }
    if(y_left !=0)mu[i]+=y_left;
  }
  if(z_left !=0)mu+=z_left;

   return mu;

}


