#include "../Struct.h"

#ifndef INITIAL_FUNCTIONS_H
#define INITIAL_FUNCTIONS_H



void Initial_Zero( double ***Speed_X,
                   int ldz, int ldy, int ldx,
                   int lz, int rz,
                   int ly, int ry,
                   int lx, int rx);

void Initial_One( double ***Speed_X,
                  int ldz, int ldy, int ldx,
                  int lz, int rz,
                  int ly, int ry,
                  int lx, int rx);

void Initial_Reader(double*** velocity_x, double*** velocity_y,
                    double*** velocity_z,double*** pressure,
                    int left_x, int right_x,
                    int left_y, int right_y,
                    int left_z, int right_z,
                    int ldx, int ldy, int ldz);

void Initial_Brown_2(double*** velocity_x, double*** velocity_y,
                     double*** velocity_z,
                     double dx, double* dy, double dz,
                     int ldx, int ldy, int ldz,
                     int index);

void Initial_Conditions_Turbulence(double*** velocity_x,
                                   double*** velocity_y,
                                   double*** velocity_z,
                                   double Reynolds, double dt,
                                   double dx, double* dy, double dz,
                                   int ldx, int ldy, int ldz);



void Initial_Zeros(double*** velocity_x, double*** velocity_y,
                   double*** velocity_z,
                   double dx, double* dy,
                   int ldx, int ldy, int ldz);

void Bamdad_Reader_2ND(double*** velocity_x, double*** velocity_y,
                       double*** velocity_z, double *pressure,
                       int ldx, int ldy, int ldz);



void Read_Data(Ar vars, 
               double *pressure,
               string filename,
               int ldx, int ldy, int ldz);

#endif
