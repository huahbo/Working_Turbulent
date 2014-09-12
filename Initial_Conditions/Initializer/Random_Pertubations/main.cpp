/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-12 11:46:34 mike_georgiou>   
*
*
main.cpp -- 
*
* Written on Wednesday, 10 September 2014.
********************************************/

#include"Random_Input.h"
#define PI 4.*atan(1.)

int  main()
{
  int ldx=64, ldy=80, ldz=64; 
  double ***rho, ***u, ***v, ***w, ***p, ***t;
  double dx, *dy,*y, dz, dt=0;

  dx=4.*PI/64;
  dz=4./3.*PI/64;

  dy=new double [ldy+2]; dy+=1;
  y=new double [ldy+2]; y+=1;

  rho=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);

  u=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);

 v=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);

 w=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);

 p=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);

 t=Matrix_Allocator(ldx,ldy,ldz,
                       0,0,
                       0,0,
                       0,0);



 //Assigning constant values to the temperature density and pressure.
 Initial_One( rho,
              ldx,  ldy,  ldz,
              0, 0,
              0, 0,
              0, 0);

 Initial_One( t,
              ldx,  ldy,  ldz,
              0, 0,
              0, 0,
              0, 0);

 Initial_Zero( p,
              ldx,  ldy,  ldz,
              0, 0,
              0, 0,
              0, 0);

 double y_min=2;
 Hyperbolic_Mesh( dy, y,
                  2,
                  ldy, 1, 1,&y_min);
   
 Initial_Conditions_Turbulence(u,
                               v,
                               w,
                               180,  dt,
                               dx,  dy,  dz,
                               ldx,  ldy,  ldz);


 Print_Binary(u,
              ldx,  ldy, ldz,
              0,0,
              0, 0,
              0, 0,
              0,"X");

 Print_Binary(v,
              ldx,  ldy, ldz,
              0,0,
              0, 0,
              0, 0,
              0,"Y");

 Print_Binary(w,
              ldx,  ldy, ldz,
              0,0,
              0, 0,
              0, 0,
              0,"Z");


 Print_Output(rho,u,v,w,p,t,
              ldx,ldy,ldz);


 y--; delete[]y;
 dy--; delete[]dy;

 Free_Matrix(rho,0,0,0);
 Free_Matrix(u,0,0,0);
 Free_Matrix(v,0,0,0);
 Free_Matrix(w,0,0,0);
 Free_Matrix(p,0,0,0);
 Free_Matrix(t,0,0,0);


}
