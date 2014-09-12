#ifndef ALLOCATOR_FUNCTIONS_H
#define ALLOCATOR_FUNCTIONS_H

void Allocator(Ar *Arr, 
               int ldx, int ldy, int ldz,
                int lx, int rx,
                int ly, int ry,
                int lz, int rz);

void DeAllocator( Ar *Arr,
                  int ldz, int ldy, int ldx,
                  int lx, int rx,
                  int ly, int ry,
                  int lz, int rz);

void Allocator_LES(turbulence_derivatives *subgrid,
                   turbulence_derivatives *filtered,
                   turbulence_variables *alpha,
                   turbulence_variables *alpha_filtered,
                   turbulence_variables *beta,
                   turbulence_variables *mi,
                   turbulence_variables *lambda,
                   turbulence_variables *rho_uu,
                   turbulence_variables *rho_uu_filtered,
                   turbulence_rhos *subgrid_rho,
                   turbulence_rhos *filtered_rho,
                   int ldx, int ldy, int ldz,
                   int left_x, int right_x,
                   int left_y, int right_y,
                   int left_z, int right_z);

void DeAllocator_LES(turbulence_derivatives *subgrid,
                   turbulence_derivatives *filtered,
                   turbulence_variables *alpha,
                   turbulence_variables *alpha_filtered,
                   turbulence_variables *beta,
                   turbulence_variables *mi,
                   turbulence_variables *lambda,
                   turbulence_variables *rho_uu,
                   turbulence_variables *rho_uu_filtered,
                   turbulence_rhos *subgrid_rho,
                   turbulence_rhos *filtered_rho,
                   int ldx, int ldy, int ldz,
                   int left_x, int right_x,
                   int left_y, int right_y,
                   int left_z, int right_z);






#endif
