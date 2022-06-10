#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int m,n,p;
  int matr1[100][100];
  int matr2[100][100];
  int v[100];
  int i,j;

  scanf("%d %d %d",&m,&n,&p);

  for(i = 0;i < m; i++){
    for(j = 0; j < n ; j++){
      scanf("%d",&matr1[i][j]);
    }
  }

  for(i = 0;i < n; i++){
    for(j = 0; j < p ; j++){
      scanf("%d",&matr2[i][j]);
    }
  }

  for(i = 0;i < m; i++){
    scanf("%d",&v[i]);
  }

  int s[100];
  int y[100];


  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      s[i] += v[j]*matr1[j][i];
    }
  }

  for(i = 0; i < p; i++){
    for(j = 0; j < n; j++){
      y[i] += s[j]*matr2[j][i];
    }
  }

  int max = 0;
  int index = 0;
  for(i = 0; i < p; i++){
    if(max < y[i]){
      max = y[i];
      index = i;
    }
  }

  printf("%d\n",index+1);


  return 0;
}
