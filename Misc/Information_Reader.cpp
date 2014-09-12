/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-02 16:37:12 mike_georgiou>   
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
#include <string>


using namespace std;

void Information_Reader(int *ldx,int *ldy, int *ldz,
                        double *length_x, double *length_y, double *length_z,
                        double *cfl, double *tolerance, int *iterations,
                        double *time_total, double *time_end, 
                        double *time_statistics,
                        int *printing_variable,
                        string *filename)
{

  fstream fin("Input_Main.man");
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


  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*cfl;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*tolerance;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*iterations;
    }

  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*time_total;
    }


  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*time_end;
    }


  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*time_statistics;
    }


  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, line);
      stringstream(line)>>*printing_variable;
    }


  //Reading the filename of the inputs
  getline(fin, line);
  if(line[0] == '#')
    {
      getline(fin, *filename);

    }



  // Initial information abouth the run
  cout<<"The length of my domain is following, from x to z"<<endl;
  cout<< *length_x<<" "<<*length_y<<" "<<*length_z<<" "<<endl<<endl;
  cout<<"The number of solution points follows from x to z"<<endl;
  cout<< *ldx<<" "<<*ldy<<" "<<*ldz<<" "<<endl<<endl;

  cout<< "The simulation starts from time "<< *time_total;
  cout<<", starts averaging (through time) at "<<*time_statistics;
  cout<<" and finishes at "<<*time_end<<endl<<endl;
  
  cout<<"The cfl number is "<<*cfl<<endl<<endl;

  cout<<"The tolerance of the bcstab solver is "<<*tolerance;
  cout<<" and the maximum no. of iterations that it can do is "<<*iterations<<endl<<endl;
  cout<<"The code saves data  every "<<*printing_variable<<" steps"<<endl;




}
