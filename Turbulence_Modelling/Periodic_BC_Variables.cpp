/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 12:53:57 mike_georgiou>   
*
*
Periodic_BC.cpp -- This function will implement periodic BC in
    the homogeneous directions for the inputted quantities
*
* Written on Tuesday,  2 September 2014.
********************************************/

#include "../Struct.h"

void Periodic_BC_Variables(turbulence_variables les,
                           int lx, int rx,
                           int lz, int rz,
                           int ldx, int ldy, int ldz)
{


  //X-Direction BC
  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){

      for (int i=1; i<=lx; i++)
        {
          /*******Left-Periodic-BC************/

          // alpha xx xy xz     les.
          les.xx[k][j][-i] =  les.xx[k][j][ldx-i];
          les.xy[k][j][-i] =  les.xy[k][j][ldx-i];
          les.xz[k][j][-i] =  les.xz[k][j][ldx-i];
          
          // alpha yy yz zz     les.
          les.yy[k][j][-i] =  les.yy[k][j][ldx-i];
          les.yz[k][j][-i] =  les.yz[k][j][ldx-i];
          les.zz[k][j][-i] =  les.zz[k][j][ldx-i];
        }
      for (int i=0; i<rx; i++)
        {
          /*******Right-Periodic-BC***********/

          // alpha xx xy xz
          les.xx[k][j][ldx+i] =  les.xx[k][j][i];
          les.xy[k][j][ldx+i] =  les.xy[k][j][i];
          les.xz[k][j][ldx+i] =  les.xz[k][j][i];

          // alpha yy yz zz
          les.yy[k][j][ldx+i] =  les.yy[k][j][i];
          les.yz[k][j][ldx+i] =  les.yz[k][j][i];
          les.zz[k][j][ldx+i] =  les.zz[k][j][i];

        }
    }
  }


  //Periodic BC in the Z direction
  // Z-Direction BC
  for (int j = 0; j < ldy; j++){
    for (int i = -lx; i< ldx+rx; i++){


      for (int k=1; k<=lz; k++)
        {
          /*******Left-Periodic-BC************/

          // alpha xx xy xz
          les.xx[-k][j][i] =  les.xx[ldz-k][j][i];
          les.xy[-k][j][i] =  les.xy[ldz-k][j][i];
          les.xz[-k][j][i] =  les.xz[ldz-k][j][i];

          // alpha yy yz zz
          les.yy[-k][j][i] =  les.yy[ldz-k][j][i];
          les.yz[-k][j][i] =  les.yz[ldz-k][j][i];
          les.zz[-k][j][i] =  les.zz[ldz-k][j][i];
        }
      for (int k=0; k<rz; k++)
        {

          /*******Right-Periodic-BC***********/


          // alpha xx xy xz
          les.xx[ldz+k][j][i] =  les.xx[k][j][i];
          les.xy[ldz+k][j][i] =  les.xy[k][j][i];
          les.xz[ldz+k][j][i] =  les.xz[k][j][i];

          // alpha yy yz zz
          les.yy[ldz+k][j][i] =  les.yy[k][j][i];
          les.yz[ldz+k][j][i] =  les.yz[k][j][i];
          les.zz[ldz+k][j][i] =  les.zz[k][j][i];

        }

    }
  }


}
