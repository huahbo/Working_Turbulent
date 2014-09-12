#ifndef VELOCITY_FUNCTIONS2ND_H
#define VELOCITY_FUNCTIONS2ND_H

void Velocity_Update_X2ND(double*** velocity_x, double*** velocity_x_tilda,
                       double*** rho, double*** pressure,
                       double dx, double dt,
                          int ldx, int ldy, int ldz);

void Velocity_Update_Y2ND(double*** velocity_y, double*** velocity_y_tilda,
                          double*** rho, double*** pressure,
                          double* dy, double dt,
                          int ldx, int ldy, int ldz);


void Velocity_Update_Z2ND(double*** velocity_z, double*** velocity_z_tilda,
                          double*** rho, double*** pressure,
                          double dz, double dt,
                          int ldx, int ldy, int ldz);

#endif
