#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Carte{
  int numar;
  char tip[100];
}Carte;


int main(int argc, char const *argv[]) {

  int n;
  int i,j;
  scanf("%d\n",&n);
  Carte carte[100];

  for(i = 0; i < n; i++){
    scanf("%d %s\n",&carte[i].numar,carte[i].tip);
  }

  int ok = 1;
  int index = 0;
  int nr = 0;
  for(i = 0 ;i < n; i++){
    nr = 0;

    for(j = 0; j <= i; j++){
      if(carte[i].numar == carte[j].numar && !(strcmp(carte[i].tip,carte[j].tip))){
        nr++;
      }
    }

    if(nr >= 3){
      ok = 0;
      index = i;
      break;
    }
  }

  if(ok == 1)
    printf("JOC OK\n");
  else
    printf("%d %s\n",carte[index].numar,carte[index].tip);

  return 0;
}
