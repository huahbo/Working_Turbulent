#ifndef MISC_FUNCTIONS_H
#define MISC_FUNCTIONS_H


#include <string>
using namespace std;
void Next_Step(Ar* Arr);
void Predictor_To_Corrector(Ar* Arr);

void Maximum_Velocities(double*** velocity_x, double*** velocity_y,
                        double*** velocity_z,
                        double* u_max, double* v_max, double* w_max,
                        int ldx, int ldy, int ldz);


void Information_Reader(int *ldx,int *ldy, int *ldz,
                        double *length_x, double *length_y, double *length_z,
                        double *cfl, double *tolerance, int *iterations,
                        double *time_total, double *time_end, 
                        double *time_statistics,
                        int *printing_variable,
                        string *filename);



void Friction_Velocity_Computation(Ar Arr,
                                   double *friction_velocity,
                                   double Reynolds,
                                   double dx,  double dz,
                                   int ldx, int ldy, int ldz);


int  Convergence_Evaluation(double ***velocity_x,
                            int ldx, int ldy, int ldz);
#endif
