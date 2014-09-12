#ifndef MESH_FUNCTIONS_H
#define MESH_FUNCTIONS_H


void Hyperbolic_Mesh( double *dy, double *y,
                      double length_y,
                      int ldy,
                      int yl, int yr,
                      double* y_min);

void Cubic_Mesh( double *dy, double *y,
                 double length_y,
                 int ldy,
                 int yl, int yr,
                 double* y_min);


#endif
