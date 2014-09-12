#include "Time_Average.h"

#ifndef TIME_AVERAGE_INL_H
#define TIME_AVERAGE_INL_H
inline void Average_Computation(double ***averaged_quantity,
                                double ***quantity,
                                double time_total, double dt,
                                int i, int j, int k)
{

  //Computing the average for each point
  averaged_quantity[k][j][i]=((time_total)*averaged_quantity[k][j][i]+
                              dt*quantity[k][j][i])
    /(time_total +dt);
  
  
}


inline void Average_Computation_Square(double ***averaged_quantity_squared,
                                       double ***quantity_1,
                                       double ***quantity_2,
                                       double time_total, double dt,
                                       int i, int j, int k)
{

  //Computing the average for each point
  averaged_quantity_squared[k][j][i]=
    ((time_total)*averaged_quantity_squared[k][j][i]+
     dt*quantity_1[k][j][i]*quantity_2[k][j][i])/(time_total +dt);
  
}


#endif
