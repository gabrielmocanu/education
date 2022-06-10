#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Carte{
  int nr;
  int pagini;
}Carte;

int main(int argc, char const *argv[]) {

  Carte c[100];
  int D,k;
  scanf("%d %d",&D,&k);

  int i;
  for(i = 0;i < k; i++){
    scanf("%d %d",&c[i].nr,&c[i].pagini);
  }

  Carte aux;
  int ok = 1;
  while(ok){
    ok = 0;
    for(i = 0;i < k-1; i++){
      if(c[i].pagini < c[i+1].pagini){
        aux = c[i];
        c[i] = c[i+1];
        c[i+1] = aux;
        ok = 1;
      }
    }
  }


  int nrCarti = 0;
  for(i = 0; i < k; i++){
    nrCarti += c[i].nr;
  }

  int nrCartiRaft = 0;
  int v[100];
  int Dtemp = D;

  while(nrCarti > 0){


    Dtemp = D;
    nrCartiRaft = 0;
    for(i = 0; i < k; i++){
      if(Dtemp - c[i].pagini >= 0 && c[i].nr > 0){
        c[i].nr--;
        Dtemp = Dtemp - c[i].pagini;
        nrCarti--;
        v[nrCartiRaft] = i;
        nrCartiRaft++;
        i--;
      }
    }

    for(i = 0; i < nrCartiRaft; i++){
      printf("%d ",c[v[i]].pagini);
    }
    printf("\n");

  }

  return 0;
}
