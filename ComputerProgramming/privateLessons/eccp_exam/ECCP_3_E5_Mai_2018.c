#include <stdio.h>
#include <math.h>

typedef struct Culoare{
  int r,g,b;
}Culoare;

int main(int argc, char const *argv[]) {

  int m,n,s;
  scanf("%d",&m);
  scanf("%d",&n);
  scanf("%d",&s);
  int i,j;
  Culoare matr[30][30];
  for(i = 0; i < m; i++){
    for(j = 0;j < n; j++){
      scanf("%d %d %d",&matr[i][j].r,&matr[i][j].g,&matr[i][j].b);
    }
  }

  int interval = 256/s;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      matr[i][j].r = matr[i][j].r / interval;
      matr[i][j].g = matr[i][j].g / interval;
      matr[i][j].b = matr[i][j].b / interval;
    }
  }

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      printf("%d %d %d\n",matr[i][j].r,matr[i][j].g ,matr[i][j].b );
    }
  }

  return 0;
}
