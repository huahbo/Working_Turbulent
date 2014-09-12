/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-09 17:08:36 mike_georgiou>
 *
 *
Flux.cpp -- This programs computes the fluxes, with fourth order
accurate precision, in the X direction. The formula that is used to compute
these fluxes can be found at the Lessani-Papalexandris paper eq.63
*
* Written on Thursday, 17 April 2014.
********************************************/

void Flux_Initialization(double*** flux_x, double ***flux_y,
                         double ***flux_z, 
                         double*** velocity_x, double*** velocity_y,
                         double*** velocity_z,
                         double*** rho,
                         int ldx, int ldy, int ldz)
{


  // I modified that manually BE CAREFULL
  for (int  k=0; k<ldz;   k++){
   for ( int  j=0; j<ldy;  j++){
      for (int   i=0; i<ldx+1;  i++)
        {

        flux_x[k][j][i] = (rho[k][j][i]*velocity_x[k][j][i]+
                           rho[k][j][i-1]*velocity_x[k][j][i-1])/2.;
        
        }


    }
  }


  for (int  k=0; k<ldz;   k++){
   for ( int  j=0; j<ldy+1;  j++){
      for (int   i=0; i<ldx;  i++)
        {

        flux_y[k][j][i] = (rho[k][j][i]*velocity_y[k][j][i]+
                           rho[k][j-1][i]*velocity_y[k][j-1][i])/2.;
        }
    }
  }





  for (int  k=0; k<ldz+1;   k++){
   for ( int  j=0; j<ldy;  j++){
     for (int   i=0; i<ldx;  i++){
       
        flux_z[k][j][i] = (rho[k][j][i]*velocity_z[k][j][i]+
                           rho[k-1][j][i]*velocity_z[k-1][j][i])/2.;

      }
      
    }
  }


}