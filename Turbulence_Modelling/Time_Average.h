#ifndef TIME_AVERAGE_H
#define TIME_AVERAGE_H



#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

using namespace std;

void Print_Binary_Stats(double ***A,
                  int ldx, int ldy, int ldz,
                  int left_x,int right_x,
                  int left_y, int right_y,
                  int left_z, int right_z,
                  int time_index,const char *mike);


void File_Opener(const char* name, const char *a,
                 int time_index, ofstream* file);

#endif
