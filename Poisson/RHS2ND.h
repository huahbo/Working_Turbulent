#ifndef RHS2ND_H
#define RHS2ND_H

double Divergence_X2ND(double*** velocity_x, double*** rho_new,
		    double dx,
                    int i, int j, int k);

double Divergence_Y2ND(double*** velocity_y, double*** rho_new,
		    double* dy,
                    int i, int j, int k);
double Divergence_Z2ND(double*** velocity_z, double*** rho_new,
		    double dz,
                    int i, int j, int k);


#endif
