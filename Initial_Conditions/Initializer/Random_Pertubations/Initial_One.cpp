/*  Last Modified Time-stamp: <2014-08-15 09:50:26 mike_georgiou> */
/*
  This Function gives to all the elements of the
  array the value 0
*/


void Initial_One( double ***data,
                   int ldx, int ldy, int ldz,
                   int lx, int rx,
                   int ly, int ry,
                   int lz, int rz)
{

  for (int k=-lz; k<ldz+rz; k++){
    for (int j=-ly; j<ldy+ry; j++){
      for (int i=-lx; i<ldx+rx; i++){

        data[k][j][i] =1.0;


      }
    }
  }

}
