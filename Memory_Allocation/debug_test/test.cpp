/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-09 17:02:35 mike_georgiou>   
*
*
test.cpp -- 
*
* Written on Tuesday,  9 September 2014.
********************************************/

#include <iostream>
using namespace std;

double *** Matrix_Allocator_debug(int ldx, int ldy, int ldz,
                                  int x_left,int x_right,
                                  int y_left,int y_right,
                                  int z_left,int z_right);

int main()
{


  int ldz=5, ldy=5, ldx=5;
  double ***array = Matrix_Allocator_debug(ldx,ldy,ldz,
                                           1,1,
                                           1,1,
                                           1,1);

 //printing
 for (int k = -1; k < ldz+1; k++){
   for (int j = -1; j < ldy+1; j++){
    for (int i = -1; i < ldx+1; i++){

      array[k][j][i]=i+j*3+k*9;
    }
   }	    
 }   




 //printing
 for (int k = -1; k < ldz+1; k++){
   for (int j = -1; j < ldy+1; j++){
    for (int i = -1; i < ldx+1; i++){
      cout<<&array[k][j][i]<<" "<<endl;
    }

    cout<<endl;
  }	    
     cout<<endl;
  }   




}
