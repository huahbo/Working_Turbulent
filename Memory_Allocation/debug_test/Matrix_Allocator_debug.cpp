/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-09 15:36:03 mike_georgiou>
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

  int z_total=ldz+z_left+z_right;
  int y_total=ldy+y_left+y_right;
  int x_total=ldx+x_left+x_right;
  
  double ***array = new double**[z_total]; array+=z_left;
  for(int j = 0; j < z_total; ++j) {
    array[j-z_left] = new double*[z_total*y_total];  
    array[j-z_left]+=y_left;

   
    for (int i=0; i<y_total; i++)
      {
        array[j-z_left][i-y_left]=new double[z_total*y_total*x_total]; 
        array[j-z_left][i-y_left]+=x_left;
      }
 }





   return array;

}


