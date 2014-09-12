#ifndef TURBULENCE_STRUCTURE_H
#define TURBULENCE_STRUCTURE_H

 struct turbulence_statistics{

  double ***velocity_x, ***velocity_y, ***velocity_z,
    ***velocity_x_square, ***velocity_y_square, ***velocity_z_square,
    ***velocity_x_y, ***velocity_x_z, ***velocity_y_z;

};  

typedef struct turbulence_statistics stats;

 struct Domain{
  
  int ldx,  ldy, ldz;
  double length_x, length_y, length_z;
   
};
typedef struct Domain domain;



struct Outputs{

  double
  *mean_x, *mean_y, *mean_z,
    *rms_x, *rms_y, *rms_z,
    *uv_prime, *uw_prime, *vw_prime;

};
typedef struct Outputs output;

#endif
