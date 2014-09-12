
/*******************************************
 *   Author: Michail Georgiou
 * DeAllocator.cpp -- Deallocationg the memory
 *
 * Written on Tuesday, 18 March 2014.
 ********************************************/

#include"Allocator.h"


void DeAllocator_1D( output* out)
{

  delete [] out->mean_x;
  delete [] out->mean_y;
  delete [] out->mean_z;



  delete [] out->rms_x;
  delete [] out->rms_y;
  delete [] out->rms_z;

  delete [] out->uv_prime;
  delete [] out->uw_prime;
  delete [] out->vw_prime;


}
