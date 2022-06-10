#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  int i,j;
  int matr[100][100];
  int fr[10] = {0};


  for(i = 0 ;i < n; i++){
    for(j = 0; j < m; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  for(i = 0 ;i < n; i++){
    for(j = 0; j < m; j++){
      fr[matr[i][j]]++;
    }
  }

  float sum = 0;
  float d = 0;
  for( i = 0; i < 10; i++){
    sum += fr[i];
  }
  float medie = (float)sum/10;

    for( i = 0; i < 10 ; i++){
      d += pow((fr[i] - medie),2);

    }
    d = (float)d/10;
    d = sqrt(d);


  int nr = 0;
  for(i = 0; i < 10;i++){
    if(fr[i] > d){
      nr++;
    }
  }

  printf("%d\n",nr);
  return 0;
}
