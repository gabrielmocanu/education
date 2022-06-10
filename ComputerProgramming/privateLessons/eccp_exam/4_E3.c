#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {


  int n;
  scanf("%d",&n);

  int matr[20][20];

  int matr2[20][20];
  int i,j,k,l;
  float sum[20] = {0};


  for(i = 0; i < n; i++){
    for(j = 0; j < 10; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  for(int x = 0; x <= 2; x++){

    // Construim semnalele intarziate k - > linia pe care ne aflam in matricea semnalelor originale/semnalelor intarziate; x -> delta D l -> merge pe coloane i -> reprezinta coloana din matricea semnalelor originale
    for(k = 0; k < n; k++){

      for(l = 0; l < k*x; l++){
      matr2[k][l] = 0;
    }

    i = 0;
    for(l=k*x; l <10; l++){
      matr2[k][l] = matr[k][i];
      i++;
    }
  }

  // Suma pe coloane a matricei semnalelor intarziate
  for(i = 0; i < n; i++){
    for(j = 0; j < 10; j++){
      sum[j] += matr2[i][j];
    }
  }

/*  for(i = 0; i < n; i++){
    for(j = 0; j < 10; j++){
      printf("%d ",matr2[i][j]);
    }
    printf("\n");
  } */

  for(j = 0;j < 10; j++){
    sum[j] = (float)sum[j]/n;
  }

  for(j = 0;j < 10; j++){
    printf("%.2f ",sum[j]);
    sum[j] = 0;
  }
  printf("\n");


}

  return 0;
}
