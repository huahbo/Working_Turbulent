/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-09-12 11:47:21 mike_georgiou>   
*
*
Print_Output.cpp -- This function  will write the data into a
    format that will be ready for initialiation for another run. 
*
* Written on Thursday, 28 August 2014.
********************************************/




#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

void Print_Output(double ***rho, double ***u, double***v,
                  double ***w, double***p, double***t,
                  int ldx, int ldy, int ldz)
{

  typedef std::numeric_limits< double > dbl;

  ofstream output_file;
  output_file.open("output_data_random1.dat");

  //obtaining full precision of for my quantities
  // output_file.precision(dbl::digits10);
   output_file.precision(17);


  // I am saving the files in a specific format.
  // rho u v w p t

  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){

        output_file<<fixed<<rho[k][j][i]<<" ";
        output_file<<fixed<<u[k][j][i]<<" ";
        output_file<<fixed<<v[k][j][i]<<" ";
        output_file<<fixed<<w[k][j][i]<<" ";
        output_file<<fixed<<p[k][j][i]<<" ";
        output_file<<fixed<<t[k][j][i]<<" ";
        output_file<<endl;    
      }

    }	    
  }   





}
