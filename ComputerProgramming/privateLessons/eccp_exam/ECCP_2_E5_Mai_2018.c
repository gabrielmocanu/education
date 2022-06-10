#include <stdio.h>
#include <math.h>

typedef struct Culoare{
  int r,g,b;
}Culoare;

Culoare func(Culoare matr[][30] , int l, int c, int s)
{
    int i,j;
    int rMax = 0;
    int gMax = 0;
    int bMax = 0;
    for(i = l; i < l + s; i++){
      for(j = c; j < c + s; j++){
        if(matr[i][j].r > rMax)
          rMax = matr[i][j].r;
        if(matr[i][j].g > gMax)
          gMax = matr[i][j].g;
        if(matr[i][j].b > bMax)
          bMax = matr[i][j].b;
      }
    }
    Culoare max;
    max.r = rMax;
    max.g = gMax;
    max.b = bMax;
    return max;
}


int main(int argc, char const *argv[]) {

  int n,s;
  scanf("%d",&n);
  scanf("%d",&s);
  int i,j;
  Culoare matr[30][30];
  Culoare matr2[10][10];

  for(i = 0; i < n; i++){
    for(j = 0;j < n; j++){
      scanf("%d %d %d",&matr[i][j].r,&matr[i][j].g,&matr[i][j].b);
    }
  }

  int linie = 0, coloana = 0;
  for(i = 0; i < n/s; i++){
    coloana = 0;
    for(j = 0; j < n/s; j++){
      matr2[linie][coloana] = func(matr,i*s,j*s,s);
      coloana++;
    }
    linie++;
  }


  for(i = 0; i < linie; i++){
    for(j = 0; j < coloana; j++){
      printf("%d %d %d",matr2[i][j].r,matr2[i][j].g,matr2[i][j].b);
      printf("\n");
    }
  }


  return 0;
}
