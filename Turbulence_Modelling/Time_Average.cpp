/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-09-04 11:00:48 mike_georgiou>
 *
 *
Time_Average.cpp -- This function will average on time the
    variables of my problem

At the first step of the time loop the data will be saved to the files
only.

From the next step of the time loop thought the following procedure
will be followed.
1) Read the data from the files.
2) Perform the time averaging, which is based on the following formula
    (<u>^n)_t=((n-1)(<u>^n-1)_u +  u_n)/n
3) Save back the data to the files.
*
* Written on Wednesday, 27 August 2014.
********************************************/

#include"../Struct.h"
#include "Time_Average.h"
#include "Time_Average-inl.h"

void Time_Average(Ar structure,
                  int time_index,
                  double time_total, double dt,
                  int auxilary,
                  int ldx, int ldy, int ldz)
{

  if(auxilary==1)
    {

      // At the first time step i will write the data only
      for (int k = 0; k < ldz; k++){
        for (int j = 0; j < ldy; j++){
          for (int i = 0; i < ldx; i++){

            structure.velocity_x_avg[k][j][i]=structure.velocity_x_new[k][j][i];
            structure.velocity_y_avg[k][j][i]=structure.velocity_y_new[k][j][i];
            structure.velocity_z_avg[k][j][i]=structure.velocity_z_new[k][j][i];


            structure.velocity_x_square[k][j][i]=
              structure.velocity_x_new[k][j][i]*structure.velocity_x_new[k][j][i];

            structure.velocity_y_square[k][j][i]=
              structure.velocity_y_new[k][j][i]*structure.velocity_y_new[k][j][i];

            structure.velocity_z_square[k][j][i]=
              structure.velocity_z_new[k][j][i]*structure.velocity_z_new[k][j][i];


            structure.velocity_x_y[k][j][i]=
              structure.velocity_x_new[k][j][i]*structure.velocity_y_new[k][j][i];

            structure.velocity_x_z[k][j][i]=
              structure.velocity_x_new[k][j][i]*structure.velocity_z_new[k][j][i];

            structure.velocity_y_z[k][j][i]=
              structure.velocity_y_new[k][j][i]*structure.velocity_z_new[k][j][i];



          }
        }
      }
    }

  else if( auxilary>1)
    {

      // Computing and saving the averaged quantities
      for (int k = 0; k < ldz; k++){
        for (int j = 0; j < ldy; j++){
          for (int i = 0; i < ldx; i++){


            // Time averaging of the velocities
            Average_Computation(structure.velocity_x_avg,
                                structure.velocity_x_new,
                                time_total, dt,
                                i, j,  k);

            Average_Computation(structure.velocity_y_avg,
                                structure.velocity_y_new,
                                time_total, dt,
                                i, j,  k);

            Average_Computation(structure.velocity_z_avg,
                                structure.velocity_z_new,
                                time_total, dt,
                                i, j,  k);


            // Time averaging of the velocity squares
            //<u'u''> <v'v'> <w'w'>
            Average_Computation_Square(structure.velocity_x_square,
                                       structure.velocity_x_new,
                                       structure.velocity_x_new,
                                       time_total, dt,
                                       i, j,  k);

            Average_Computation_Square(structure.velocity_y_square,
                                       structure.velocity_y_new,
                                       structure.velocity_y_new,
                                       time_total, dt,
                                       i, j,  k);

            Average_Computation_Square(structure.velocity_z_square,
                                       structure.velocity_z_new,
                                       structure.velocity_z_new,
                                       time_total, dt,
                                       i, j,  k);


            //<u'v'> <u'w'> <v'w'>
            Average_Computation_Square(structure.velocity_x_y,
                                       structure.velocity_x_new,
                                       structure.velocity_y_new,
                                       time_total, dt,
                                       i, j,  k);

            Average_Computation_Square(structure.velocity_x_z,
                                       structure.velocity_x_new,
                                       structure.velocity_z_new,
                                       time_total, dt,
                                       i, j,  k);

            Average_Computation_Square(structure.velocity_y_z,
                                       structure.velocity_y_new,
                                       structure.velocity_z_new,
                                       time_total, dt,
                                       i, j,  k);


          }
        }
      }


    }


  if((auxilary-1)%100==0)
    {

      Print_Binary_Stats(structure.velocity_x_avg,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"u_time_averaged");

      Print_Binary_Stats(structure.velocity_y_avg,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"v_time_averaged");

      Print_Binary_Stats(structure.velocity_z_avg,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"w_time_averaged");


      Print_Binary_Stats(structure.velocity_x_square,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"u_square_time_averaged");

      Print_Binary_Stats(structure.velocity_y_square,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"v_square_time_averaged");

      Print_Binary_Stats(structure.velocity_z_square,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"w_square_time_averaged");

      //<u'v'> <u'w'> <v'w'>
      Print_Binary_Stats(structure.velocity_x_y,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"u_v_time_averaged");

      Print_Binary_Stats(structure.velocity_x_z,
                         ldx, ldy,  ldz,
                         0,0,
                         0,0,
                         0,0,
                         0,"u_w_time_averaged");

      Print_Binary_Stats(structure.velocity_y_z,
                   ldx, ldy,  ldz,
                   0,0,
                   0,0,
                   0,0,
                   0,"v_w_time_averaged");

    }



}
