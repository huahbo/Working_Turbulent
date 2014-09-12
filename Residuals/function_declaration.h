#ifndef FUNCTION_DECLARATION_H
#define FUNCTION_DECLARATION_H

void Velocity_Residual_Initialization(double ***residual_x, double***residual_y,
                                      double *** residual_z,double***velocity_x,
                                      double ***velocity_y, double***velocity_z,
                                      double ***flux_x, double ***flux_y, 
                                      double***flux_z, 
                                      double ***eddy_viscosity,
                                      double Reynolds,
                                      double pressure_gradient,
                                      double *explicit_term,
                                      double dx, double *dy, double dz,
                                      int ldx, int ldy, int ldz);
#endif
