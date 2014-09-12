#ifndef FILTERING_ALPHAS_H
#define FILTERING_ALPHAS_H

inline void Filtering(double ***value, double ***filtered_value,
                      int i, int j, int k)
{

    filtered_value[k][j][i]=

    value[k][j][i]/4.

    +(value[k][j][i+1]+ value[k][j][i-1]
      +value[k+1][j][i]+value[k-1][j][i])/8.

    +(value[k+1][j][i+1]+value[k-1][j][i+1] 
      +value[k+1][j][i-1] +value[k-1][j][i-1])/16.; 

}

#endif
