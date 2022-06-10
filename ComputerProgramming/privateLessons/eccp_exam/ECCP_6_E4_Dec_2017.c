#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421

int main(int argc, char const *argv[]) {

  int m,n;

  scanf("%d",&m);
  scanf("%d",&n);

  float matr[10][10];
  float matr2[10][10];
  int i,j;
  int k,l;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      scanf("%f",&matr[i][j]);
    }
  }

  float coef1 = 0;
  float coef2 = 0;
  float sum = 0;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){


      sum = 0;
      for(k = 0;k < m; k++){
        for(l = 0; l < n; l++){

          sum += cos(((float)(PI*i)/(2*m))*(2*k+1))*cos(((PI*j)/(2*n))*(2*l+1))*matr[k][l];
        }
      }

      if(i == 0)
        coef1 = (float)1/sqrt(m);
      else
        coef1 = sqrt((float)2/m);

      if(j == 0)
        coef2 = (float)1/sqrt(n);
      else
        coef2 = sqrt((float)2/n);

      matr2[i][j] = coef1 * coef2 * sum;

    }
  }

  for(i = 0;i < m; i++){
    for(j = 0; j < n; j++){
      if(i != 0 || j !=0){
        matr2[i][j] = 0;
      }
    }
  }


  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){

      sum = 0;
      for(k = 0;k < m; k++){
        for(l = 0; l < n; l++){

          if(k == 0)
            coef1 = (float)1/sqrt(m);
          else
            coef1 = sqrt((float)2/m);

          if(l == 0)
            coef2 = (float)1/sqrt(n);
          else
            coef2 = sqrt((float)2/n);


          sum +=  coef1 * coef2 * cos(((float)(PI*k)/(2*m))*(2*i+1))*cos(((PI*l)/(2*n))*(2*j+1))*matr2[k][l];
        }
      }

      matr[i][j] = sum;
    }
  }


  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("%d ",(int)(matr[i][j]+0.000001));
    }
    printf("\n");
  }


  return 0;
}
