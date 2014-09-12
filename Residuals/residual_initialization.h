#ifndef RESIDUAL_FUNCTIONS_H
#define RESIDUAL_FUNCTIONS_H

void Velocity_Residual_2ND_X( double*** residual_x,
                              double*** velocity_x,
                              double*** flux_x, double*** flux_y,
                              double*** flux_z,
                              double ***eddy_viscosity,
                              double Reynolds,
                              double source,
                              double dx, double* dy, double dz,
                              int i, int j, int k,
                              double* explicit_term);


void Velocity_Residual_2ND_Y( double*** residual_y,
                              double*** velocity_y,
                              double*** flux_x, double*** flux_y,
                              double*** flux_z,
                              double ***eddy_viscosity,
                              double Reynolds,
                              double source,
                              double dx, double* dy, double dz,
                              int i, int j, int k,
                              double* explicit_term);

void Velocity_Residual_2ND_Z( double*** residual_z,
                              double*** velocity_z,
                              double*** flux_x, double*** flux_y,
                              double*** flux_z,
                              double ***eddy_viscosity,
                              double Reynolds,
                              double source,
                              double dx, double* dy, double dz,
                              int i, int j, int k,
                              double* explicit_term);


#endif
