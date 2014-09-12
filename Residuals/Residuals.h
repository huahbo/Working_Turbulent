#ifndef SOLVER_RESIDUALS_H
#define SOLVER_RESIDUALS_H

#include <stdio.h>

// Function Declaration

double Convection_Term2ND( double*** velocity_x,
                        double*** flux_x, double*** flux_y, double*** flux_z,
                        double dx, double* dy, double dz,
                        int i, int j, int k);

double Viscous_Term2ND(double ***velocity,
                       double ***eddy_viscosity,
                       double *explicit_term,
                       double Reynolds,
                       double dx, double* dy, double dz,
                       int i, int j, int k);

#endif
