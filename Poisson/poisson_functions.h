#ifndef POISSON_FUNCTIONS_H
#define POISSON_FUNCTIONS_H

void BCSG(double *sL, int *ijL, double *X, double *D, double *Pre,
          double error, int L, int N, int& flag, ofstream *output_file);

void BCSG_new(double *sL, int *ijL, double *X, double *D, double *Pre,
                   double error, int L, int N, int& flag);


void Vector_Constructor(double *s_A, double *Precond_A, int *ij_A,
                        double Coefficients_Z[4], double Coefficients_X[4], double *dy,
                        int ldz, int ldy, int ldx, int Nze);


void Right_Hand_Side_Poisson(double* rhs, double*** velocity_x,
                             double*** velocity_y, double*** velocity_z,
                             double*** rho_new, double*** rho,double*** rho_old,
                             double dx, double* dy, double dz,
                             double dt,
                             int ldx, int ldy, int ldz);
void constr_a (double* a, int* pos, double* precond, double*phi,
               int n, int m, int l, double ri, double* rj, double rk);



#endif
