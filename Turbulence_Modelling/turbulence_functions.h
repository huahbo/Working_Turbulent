#ifndef TURBULENCE_FUNCTIONS_H
#define TURBULENCE_FUNCTIONS_H

void LES_Modelling2ND(double ***eddy_viscosity,
                      double ***velocity_x, 
                      double ***velocity_y,
                      double ***velocity_z,
                      double ***rho,
                      double Reynolds,
                      double dx, double *dy, double dz,
                      int ldx, int ldy, int ldz);


void Time_Average(Ar structure,
                  int time_index,
                  double time_total, double dt,
                  int auxilary,
                  int ldx, int ldy, int ldz);

void LES_Modelling_Dynamic(double ***eddy_viscosity,
                           double ***velocity_x, 
                           double ***velocity_y,
                           double ***velocity_z,
                           double ***rho,
                           double *C_s,
                           double Reynolds,
                           double dx, double *dy, double dz,
                           int ldx, int ldy, int ldz);


void Dynamic_Smagorinsky(turbulence_derivatives subgrid,
                         turbulence_derivatives filtered,
                         turbulence_variables alpha,
                         turbulence_variables alpha_filtered,
                         turbulence_variables beta,
                         turbulence_variables mi,
                         turbulence_variables lambda,
                         turbulence_variables rho_uu,
                         turbulence_variables rho_uu_filtered,
                         turbulence_rhos rho_u,
                         turbulence_rhos rho_u_filtered,
                         double *C_s,
                         double ***velocity_x,
                         double ***velocity_y,
                         double ***velocity_z,
                         double ***rho,
                         double dx, double *dy, double dz,
                         int left_x, int right_x,
                         int left_y, int right_y,
                         int left_z, int right_z,
                         int ldx, int ldy, int ldz);

#endif
