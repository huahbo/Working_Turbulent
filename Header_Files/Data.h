/*  Last Modified Time-stamp: <2014-09-10 16:28:06 mike_georgiou> */
//d Program that the problems constant's will be defined
/* const identifier must be placed in order for the variables to be read only once */


// General contants

#ifndef Constants
#define Constants

// Non-Dimensional Numbers and quatities of my problem
const double Reynolds = 180.;
const double Pressure_Gradient = -1.;
#endif


#ifndef Boundary_Conditions
#define Boundary_Conditions

const double temperature_top = 1.;
const double temperature_bottom = 1.;

const double temperature_gradient_top = 0.;
const double temperature_gradient_bottom = 0.;

const double rho_top = 1.;
const double rho_bottom = 1.;

const double rho_gradient_top = 0.;
const double rho_gradient_bottom = 0.;

const double pressure_gradient_top = 0.;
const double pressure_gradient_bottom = 0.;

const double velocity_x_top=0.;
const double velocity_x_bottom=0.;

const double velocity_y_top=0.;
const double velocity_y_bottom=0.;

const double velocity_z_top=0.;
const double velocity_z_bottom=0.;



// used. for 0.5 Crank Nickolson, for 1. fully implicit
const double implicit_scheme = 0.;
#endif