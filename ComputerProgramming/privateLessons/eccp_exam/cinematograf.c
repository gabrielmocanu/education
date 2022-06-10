#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Film{
  int ora;
  int min;
  int cost;
  char nume[100];
}Film;


int main(int argc, char const *argv[]) {

  int n;
  int ora,min;
  int i;
  Film film[100];

  scanf("%d:%d\n",&ora,&min);
  scanf("%d\n",&n);

  for(i = 0; i < n; i++){
    scanf("%d:%d %d %s\n",&film[i].ora,&film[i].min,&film[i].cost,film[i].nume);
  }

  int minim = 9999;
  int dif = 0;
  int index;
  int cost_min = 999;

  for(i = 0;i < n; i++){

    if((ora < film[i].ora) || (ora == film[i].ora && min <= film[i].min)){ // daca filmul incepe dupa
      dif = (film[i].ora - ora)*60 + film[i].min - min;

      if(minim > dif){
        minim = dif;
        index = i;
        cost_min = film[i].cost;
      }

      if(minim == dif){ // daca mai exista un film cu dif minima
        if(film[i].cost < cost_min){
          index = i;
          cost_min = film[i].cost;
        }
      }
    }
  }

  printf("%s\n",film[index].nume);

  return 0;
}
