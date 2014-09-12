#ifndef FLUX_FUNCTIONS_H
#define FLUX_FUNCTIONS_H

void Flux_Evaluation_Z2ND(double*** flux_z, double*** velocity_z,
                          double*** rho, double*** pressure,
                          double dz, double dt,
                          int ldx, int ldy, int ldz);

void Flux_Evaluation_Y2ND(double*** flux_y, double*** velocity_y,
                          double*** rho, double*** pressure,
                          double* dy, double dt,
                          int ldx, int ldy, int ldz);

void Flux_Evaluation_X2ND(double*** flux_x, double*** velocity_x,
                          double*** rho, double*** pressure,
                          double dx, double dt,
                          int ldx, int ldy, int ldz);



void Flux_Initialization(double*** flux_x, double ***flux_y,
                         double ***flux_z, 
                         double*** velocity_x, double*** velocity_y,
                         double*** velocity_z,
                         double*** rho,
                         int ldx, int ldy, int ldz);

#endif
