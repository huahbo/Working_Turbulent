

void constr_a (double* a, int* pos, double* precond, double* phi, int n, int m, int l, double ri, double* rj, double rk) ;
int position_oned (int n, int m, int i, int j, int k) ;
double cent_cell_a ( double* phi, double ri, double* rj, double rk, int j) ;
double per_dir_cell_a ( double* phi, double ri, int j) ;
double north_cell_a ( double* phi, double* rj, int j) ;
double south_cell_a ( double* phi, double* rj, int j) ;

#include <iostream>
using namespace std;



void constr_a (double* a, int* pos, double* precond, double*phi, int n, int m, int l, double ri, double* rj, double rk) {

  double centval = 0. ; 

  // Variables showing the positions of the matrices
  int alpha = 0;   // the location (i,j,k) of the main loop, mapped from 3D -> 1D matrix.
  int matind = 0;  // matrix a index (for the off-diagonal elements)
  
  // Flag
  int firstel = 1;  // while this flag remains 1, the first element of the row has not been written yet.
  
  // Starting position for non-diagonal elements in matrix a. (and for the elements that hold the column numbers in the position matrix).
  int N = n*m*l + 2 ;


  // "Dead elements" : they don't include elements of the full-storage matrix, but have key-values to determine the size of the matrix
  a[N-1] = 0. ;
  pos[N-1] = double( n*m*l *7 - 2* n*m ) + 1. ;
  // By the end of the function, these values should not be changed

  for (int k=1 ; k<=l ; k++) {
    for (int j=1 ; j<=m ; j++) {
      for (int i=1 ; i<=n ; i++) {


	// Standard treatment for every element
	// set value in the value matrix
	// if first element of the row
	//   set position in the position matrix
	//   drop the flag for first element (this element, if it exists will always be the first element)
	// set the number of the 2d-matrix column
	// update index for matrices a and pos (that points to their second part) 

	alpha = position_oned(n,m,i,j,k) ;

	centval = 0.;
	firstel = 1 ;
	

	// if close to the fore-ground boundary (k=l), then ADD COEF. of p(i,j,1) which will be the first element of the line
	if (k==l) {
	  a[N + matind] = per_dir_cell_a (phi, rk, j) ;

	  //In this case, if the element is added, it IS the first element of the row
	  pos[alpha] = N + matind ;
	  firstel = 0 ;

	  pos[N + matind] = position_oned(n,m,i,j,1) ;

	  matind ++ ;
	}


	// if not close to the back-ground boundary (k=1), then coef. of p(i,j,k-1)
	if (k!=1) {
	  a[N + matind] = per_dir_cell_a (phi, rk, j) ;

	  if (firstel == 1) {
	    pos[alpha] = N + matind ;
	    firstel = 0;
	  }

	  pos[N + matind] = position_oned(n,m,i,j,k-1) ;

	  matind ++ ;
	}

	// if close to the bottom boundary, (j=1), then ADD VALUE to the center cell
	// else, write coef. of p(i,j-1,k)
	if (j==1)
	  centval += south_cell_a (phi, rj, j) ;
	else {
	  a[N + matind] = south_cell_a (phi, rj, j) ;

	  if (firstel == 1) {
	    pos[alpha] = N + matind ;
	    firstel = 0 ;
	  }
	  
	  pos[N + matind] = position_oned(n,m,i,j-1,k) ;

	  matind ++ ;
	}


	// if close to the right boundary, (i=n), ADD COEF. of p(1,j,k)
	if (i==n) {
	  a[N + matind] = per_dir_cell_a (phi, ri, j) ;

	  if (firstel == 1) {
	    pos[alpha] = N + matind ;
	    firstel = 0 ;
	  }
	  
	  pos[N + matind] = position_oned(n,m,1,j,k) ;

	  matind ++ ;
	}
	
	// if not close to the left boundary (i=1), then write coeff. of p(i-1,j,k)
	if (i!=1) {
	  a[N + matind] = per_dir_cell_a (phi, ri, j) ;

	  if (firstel == 1) {
	    pos[alpha] = N + matind ;
	    firstel = 0;
	  }
	  
	  pos[N + matind] = position_oned(n,m,i-1,j,k) ;

	  matind ++ ;
	}
	
	// CENTER CELL, LEAVE IT FOR THE END

	// if not close to the right boundary (i=n), then write the coeff. of p(i+1,j,k)
	if (i!=n) {
	  a[N + matind] = per_dir_cell_a(phi, ri, j) ;
	  
	  if (firstel == 1) {
	    pos[alpha] = N + matind ;
	    firstel = 0;
	  }

	  pos[N+matind] = position_oned(n,m,i+1,j,k) ;

	  matind ++ ;
	}

	// if close to the left boundary (i=1), ADD COEF. of p(n,j,k)
	if (i==1) {
	  a[N + matind] = per_dir_cell_a(phi,ri, j) ;

	  // If close to the left boundary, then p(i+1,j,k) exists, so it cannot be the first element of the row
	  
	  pos[N + matind] = position_oned(n,m,n,j,k) ;

	  matind ++ ;
	}

	// if close to the top boundary, (j=m),  then ADD VALUE to the center cell
	// else, write coeff. of p(i,j+1,k)
	if (j==m) 
	  centval += north_cell_a ( phi, rj, j) ;
	else {
	  a[N + matind] = north_cell_a ( phi, rj, j) ;

	  // This coefficient cannot be the first one of the row, either the (i+1) or the (i-1) elements will be written first

	  pos[N + matind] = position_oned(n,m,i,j+1, k) ;
	  
	  matind ++ ;
	}
	
       	// if not close to the foreground boundary (k=l), then write coef. of (p(i,j,k+1) )
	if (k!=l) {
	  a[N + matind] = per_dir_cell_a (phi, rk, j) ;

	  // This coefficient cannot be the first one of the row, either the (i+1) or the (i-1) elements will be written first

	  pos[N + matind] = position_oned(n,m,i,j,k+1) ;

	  matind ++ ;
	}

	// if close to the back-ground boundary (k=1), then ADD COEF. p(i,j,l) ;
	if (k==1) {
	  a[N + matind] = per_dir_cell_a (phi, rk, j) ;

	  // This coefficient cannot be the first one of the row, either the (i+1) or the (i-1) elements will be written first

	  pos[N + matind] = position_oned(n,m,i,j,l) ;

	  matind ++ ;
	}

	// TAKE CARE OF THE CENTER CELL
	centval += cent_cell_a (phi, ri, rj, rk, j) ;
	a[alpha] = centval ;
	
	precond[alpha] = centval ;

      }
    }
  }


  if (a[N-1] != 0.) {
    cout << "Error in the stensil construction function, matrix a" << endl ;
    
    for (int i=1 ; i<= n*m*l ; i++ )
      a[i] = 1./0. ;
  }

  if (pos[N-1] != double( n*m*l *7 - 2* n*m ) + 1.) {
    cout << "Error in the stensil construction function, matrix pos" << endl ;

    for (int i=1 ; i<= n*m*l ; i++ )
      a[i] = 1./0. ;
  }
  

}



int position_oned (int n, int m, int i, int j, int k) {

  return ( (k-1)*m + (j-1) )*n + (i-1) + 1 ;

}



double cent_cell_a ( double* phi, double ri, double* rj, double rk, int j) {

  double terma, termb, termc, termd ;


  //Shifting the j's in order because i am using 0:ldy-1 notation
  j-=1;

  terma = - phi[j] /2. /ri /ri ;

  termb = - ( phi[j+1] + phi[j] ) /2. /(2.*rj[j]) /(rj[j]+rj[j+1]) ;

  termc = - ( phi[j] + phi[j-1] ) /2. /(2.*rj[j]) /(rj[j]+rj[j-1]) ;

  termd = - phi[j] /2. /rk /rk ;
  
  return terma + termb + termc + termd ;

}


double per_dir_cell_a ( double* phi, double ri, int j) {

  return phi[j] /4. /ri /ri ;

}

double north_cell_a ( double* phi, double* rj, int j) {

  //Shifting the j's in order because i am using 0:ldy-1 notation
  j-=1;


  return ( phi[j+1] + phi[j] ) /2. /(2.*rj[j]) /(rj[j]+rj[j+1]) ;
  
}

double south_cell_a ( double* phi, double* rj, int j) {

  //Shifting the j's in order because i am using 0:ldy-1 notation
  j-=1;
  
  return ( phi[j-1] + phi[j] ) /2. /(2.*rj[j]) /(rj[j]+rj[j-1]) ;
  
}


