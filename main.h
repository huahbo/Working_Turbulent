#ifndef MAIN_H
#define MAIN_H
#include "./Header_Files/Data.h"
#include "Struct.h"



#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <signal.h>
#include <sstream>
#include <string>
#include <iostream>

#include "./Fluxes/flux_functions.h"
#include "./Velocities/velocity_functions2nd.h"
#include "./Residuals/function_declaration.h"
#include "./Tildas/tilda_functions.h"
#include "./Printing/printing_functions.h"
#include "./Turbulence_Modelling/turbulence_functions.h"
#include "./Memory_Allocation/allocation_functions.h"
#include "./Misc/misc_functions.h"
#include "./Boundary_Conditions/bc_functions.h"
#include "./Mesh_Generation/mesh_functions.h"
#include "./Initial_Conditions/initial_functions.h"
#include "./Poisson/poisson_functions.h"




static const double pi = 4.*atan(1.);


int 
  ldx,ldy,ldz,
/*Nze is defined in order to construct the vectors for the sparse solver*/
  nze, dim_a, flag;

int
  left_z=1,right_z=1,
  left_y=1,right_y=1,
  left_x=1,right_x=1;



double *s_a, *precond_a, *result, *rhs,Coefficients_X[4],Coefficients_Z[4];
int *ij_a;


double dx, dz, dt, length_x, length_y, length_z;
double cfl, tolerance, time_total, time_end, time_statistics;
double explicit_term=0.;

int iterations, printing_variable;




/* Structure defined in the Struct.h file*/
Ar Arr;

turbulence_derivatives subgrid, filtered;

turbulence_variables  
  alpha, alpha_filtered, beta, 
  mi, lambda, rho_uu, rho_uu_filtered;

turbulence_rhos subgrid_rho, filtered_rho;


#endif
