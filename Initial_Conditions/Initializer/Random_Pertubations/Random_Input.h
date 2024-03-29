#ifndef RANDOM_INPUT_H
#define RANDOM_INPUT_H

double *** Matrix_Allocator(int ldx, int ldy, int ldz,
                            int x_left,int x_right,
                            int y_left,int y_right,
                            int z_left,int z_right);

void Initial_Conditions_Turbulence(double*** velocity_x,
                                   double*** velocity_y,
                                   double*** velocity_z,
                                   double Reynolds, double dt,
                                   double dx, double* dy, double dz,
                                   int ldx, int ldy, int ldz);

void Hyperbolic_Mesh(double* dy, double *y,
                     double length_y,
                     int ldy, int ly, int ry,
                     double* y_min);

void Free_Matrix(double ***pA,
                 int x_left, int y_left, int z_left);


void Initial_Zero( double ***data,
                   int ldx, int ldy, int ldz,
                   int lx, int rx,
                   int ly, int ry,
                   int lz, int rz);

void Initial_One( double ***data,
                   int ldx, int ldy, int ldz,
                   int lx, int rx,
                   int ly, int ry,
                   int lz, int rz);


void Print_Output(double ***rho, double ***u, double***v,
                  double ***w, double***p, double***t,
                  int ldx, int ldy, int ldz);


void Print_Binary(double ***A,
                  int ldx, int ldy, int ldz,
                  int left_x,int right_x,
                  int left_y, int right_y,
                  int left_z, int right_z,
                  int time_index,const char *mike);

#include<cmath>
#include<iostream>

using namespace std;
#endif
