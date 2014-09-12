/*  Last Modified Time-stamp: <2014-09-12 10:39:48 mike_georgiou> */ 
#ifndef STRUCT_H
#define STRUCT_H

struct Arrays{
  double
  *half_dy, *y,

    ***velocity_x, ***velocity_y, ***velocity_z,
    ***velocity_x_new, ***velocity_y_new, ***velocity_z_new,
    ***velocity_x_tilda, ***velocity_y_tilda, ***velocity_z_tilda,

    ***flux_x, ***flux_y, ***flux_z,
    /* ***flux_x_new, ***flux_y_new, ***flux_z_new, */

    ***rho, ***rho_new, ***rho_old,

    ***pressure,

    ***temperature, ***temperature_new, ***temperature_avg,

    ***residual_x_old, ***residual_y_old, ***residual_z_old,
    ***residual_y, ***residual_z, ***residual_x,
    ***eddy_viscosity,

    ***velocity_x_avg, ***velocity_y_avg, ***velocity_z_avg,
    ***velocity_x_square, ***velocity_y_square, ***velocity_z_square,
    ***velocity_x_y, ***velocity_x_z, ***velocity_y_z;
  

};

typedef   struct Arrays Ar;


typedef struct Turbulence{
  double
    ***u_over_x, ***u_over_y, ***u_over_z,
    ***v_over_x, ***v_over_y, ***v_over_z,
    ***w_over_x, ***w_over_y, ***w_over_z;

} turbulence_derivatives;

typedef struct Dynamic_Smagorinsky{

  double 
  ***xx, ***xy, ***xz, 
  ***yy, ***yz,
  ***zz;
} turbulence_variables;

typedef struct Turbulence_Rhos{

  double
  ***x, ***z,
    ***y, ***rho;  

} turbulence_rhos;

#endif
