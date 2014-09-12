#ifndef BC_FUNCTIONS_H
#define BC_FUNCTIONS_H


void BC_Single(double ***data,
               int ldx, int ldy, int ldz,
               int lx, int rx,
               int ly, int ry,
               int lz, int rz,
               int index,
               double bc_top, double bc_bottom,
               double *dy);



void BC_Tilda(double*** velocity_x_tilda, double*** velocity_y_tilda,
              double*** velocity_z_tilda,
              int ldx, int ldy, int ldz,
              int lx, int rx,
              int ly, int ry,
              int lz, int rz);

void BC_Velocities(double*** velocity_x,
                   double*** velocity_y,
                   double*** velocity_z,
                   int ldx, int ldy, int ldz,
                   int lx, int rx,
                   int ly, int ry,
                   int lz, int rz,
                   int index,
                   double bc_x_top, double bc_x_bottom,
                   double bc_y_top, double bc_y_bottom,
                   double bc_z_top, double bc_z_bottom,
                   double *dy,double dx, double time);





#endif
