#ifndef DYNAMIC_SMAGORINSKY_H
#define DYNAMIC_SMAGORINSKY_H

#include<math.h>
#include "../Struct.h"


//Functions

void Derivative_Computation(turbulence_derivatives subgrid,
                            double ***velocity_x,
                            double ***velocity_y,
                            double ***velocity_z,
                            double dx, double *dy, double dz,
                            int ldx, int ldy, int ldz);


void Alpha_Computation(turbulence_derivatives subgrid,
                       turbulence_variables alpha,
                       double ***rho,
                       double dx, double *dy, double dz,
                       int ldx, int ldy, int ldz);


void Periodic_BC_Derivatives(turbulence_derivatives les,
                             int lx, int rx,
                             int lz, int rz,
                             int ldx, int ldy, int ldz);


void Periodic_BC_Variables(turbulence_variables les,
                           int lx, int rx,
                           int lz, int rz,
                           int ldx, int ldy, int ldz);


void Filtering_Derivatives(turbulence_derivatives subgrid,
                           turbulence_derivatives filtered,
                           int ldx, int ldy, int ldz);


void Filtering_Variables(turbulence_variables subgrid,
                         turbulence_variables filtered,
                         int ldx, int ldy, int ldz);



void Rho_Initialization(turbulence_rhos subgrid_rho,
                        turbulence_rhos filtered_rho,
                        turbulence_variables rho_uu,
                        turbulence_variables rho_uu_filtered,
                        double ***rho,
                        double ***velocity_x,
                        double ***velocity_y, 
                        double ***velocity_z,
                        int lx, int rx,
                        int ly, int ry,
                        int lz, int rz,
                        int ldx, int ldy, int ldz);

void Beta_Computation(turbulence_derivatives filtered,
                      turbulence_variables beta,
                      double ***rho,
                      double dx, double *dy, double dz,
                      int ldx, int ldy, int ldz);


#endif
