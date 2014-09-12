#ifndef DIVERGENCE_SECOND_H
#define DIVERGENCE_SECOND_H


double Divergence_X_Second(double*** velocity_x, double*** rho,
                    double dx,
                           int i, int j, int k);

double Divergence_Y_Second(double*** velocity_x, double*** rho,
                           double *dx,
                           int i, int j, int k);

double Divergence_Z_Second(double*** velocity_x, double*** rho,
                           double dx,
                           int i, int j, int k);

#endif
