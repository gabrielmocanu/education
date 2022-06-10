#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  int i,j;

  int matr[100][100];
  int matr2[100][100];
  for(i = 0;i < n; i++){
    for(j = 0;j < m; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  for(i = 0; i < n;i ++){
    for(j = 0; j < m; j++){
      matr2[i][j] = matr[i][j] * 0.9 + 2;
    }
  }


  for(i = 0; i < n;i ++){
    for(j = 0; j < m; j++){
      matr2[i][j] = matr2[i][j] - matr[i][j];
    }
  }

  float sum = 0;
  for(i = 0; i < n;i ++){
    for(j = 0; j < m; j++){
      sum = sum + matr2[i][j];
    }
  }

  sum = (float)sum/(m*n);

  //
  //
  // for(i = 0; i < n; i++){
  //   for(j = 0; j < m;j++){
  //     printf("%d ",matr2[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("%f\n",sum);


  return 0;
}
