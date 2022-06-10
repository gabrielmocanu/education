#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  int i,j,k;
  int matr[100][100];
  int matr2[100][100];

  for(i = 0; i <n ;i++){
    for(j = 0; j < m; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  int ok = 1;
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){

      ok = 1;
      for(k = 2; k < matr[i][j]; k++){
        if(matr[i][j] % k == 0){
          ok = 0;
          break;
        }
      }

      if(ok)
        matr2[i][j] = 0;
      else
        matr2[i][j] = 1;
    }
  }

  int sum = 0;

  for(i = 0 ; i < n; i++){
    for(j = 0; j < m; j++){
      sum += matr2[i][j];
    }
  }

  printf("%d\n",sum);

  return 0;
}
