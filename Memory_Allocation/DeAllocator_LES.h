#ifndef DEALLOCATOR_LES_H
#define DEALLOCATOR_LES_H

void Allocator_LES_Derivatives(turbulence_derivatives *les, 
                               int ldx, int ldy, int ldz,
                               int lx, int rx,
                               int ly, int ry,
                               int lz, int rz);


void DeAllocator_LES_Derivatives( turbulence_derivatives *les, 
                                  int ldz, int ldy, int ldx,
                                  int lx, int rx,
                                  int ly, int ry,
                                  int lz, int rz);



void Allocator_LES_Variables(turbulence_variables *les, 
                               int ldx, int ldy, int ldz,
                               int lx, int rx,
                               int ly, int ry,
                               int lz, int rz);


void DeAllocator_LES_Variables( turbulence_variables *les, 
                                  int ldz, int ldy, int ldx,
                                  int lx, int rx,
                                  int ly, int ry,
                                  int lz, int rz);


void Allocator_LES_Rhos(turbulence_rhos *les, 
                        int ldx, int ldy, int ldz,
                        int lx, int rx,
                        int ly, int ry,
                        int lz, int rz);


void DeAllocator_LES_Rhos( turbulence_rhos *les, 
                           int ldz, int ldy, int ldx,
                           int lx, int rx,
                           int ly, int ry,
                           int lz, int rz);


#endif
