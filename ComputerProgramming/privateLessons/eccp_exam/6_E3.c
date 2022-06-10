#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);

  int i,j;
  int matr[100][100] = {0};

  int matr2[100][100] = {0};
  int v[5];

  for(i = 1; i <= n; i++){
    for(j = 1; j <= m; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  int ok = 1;
  int aux;
  int k;

  for(i = 1; i <= n; i++){
    for(j = 1; j <= m; j++){

      ok = 1;
      v[0] = matr[i][j];
      v[1] = matr[i-1][j];
      v[2] = matr[i][j-1];
      v[3] = matr[i][j+1];
      v[4] = matr[i+1][j];

      while(ok){
        ok = 0;
        for(k = 0; k < 4;k++){
          if(v[k] > v[k+1]){
            aux = v[k];
            v[k] = v[k+1];
            v[k+1] = aux;
            ok = 1;
          }
        }
      }

      matr2[i][j] = v[2];

    }
  }

  for(i = 1; i <= n;i++){
    for(j = 1 ; j <= m; j++){
      printf("%d ",matr2[i][j]);
    }
    printf("\n");
  }


  return 0;
}
