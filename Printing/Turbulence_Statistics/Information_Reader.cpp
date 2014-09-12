/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-08-28 11:49:30 mike_georgiou>   
*
*
Information_Reader.cpp -- In this program I will read information regarding the
    geometry of the domain, the grid, the cfl number, the tolerance of the
    Poisson solver etc.
*
* Written on Thursday, 31 July 2014.
********************************************/

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void Information_Reader(int *ldx,int *ldy, int *ldz,
                        double *length_x, double *length_y, double *length_z)

{

  fstream fin("Input_Statistics.man");
  string line;


  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*ldx;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*ldy;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*ldz;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*length_x;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*length_y;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*length_z;
    }


  // Initial information abouth the run
  cout<<"The length of my domain is following, from x to z"<<endl;
  cout<< *length_x<<" "<<*length_y<<" "<<*length_z<<" "<<endl<<endl;
  cout<<"The number of solution points follows from x to z"<<endl;
  cout<< *ldx<<" "<<*ldy<<" "<<*ldz<<" "<<endl<<endl;


}
