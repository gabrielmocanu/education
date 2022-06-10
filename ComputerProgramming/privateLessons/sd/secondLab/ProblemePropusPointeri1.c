#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char *sir1,*sir2;
  sir1 = (char *)malloc(20*sizeof(char));
  sir2 = (char *)malloc(20*sizeof(char));

  printf("Introdu primul sir:");
  scanf("%s",sir1);
  printf("Introdu al doilea sir:");
  scanf("%s",sir2);

  // Toate celelalte functii le-am explicat si le-am pus in comentariu

  //int nr_litere;
  //nr_litere = strlen(sir1);
  //printf("Numarul de litere al primului sir %d:\n",nr_litere);
  //nr_litere = strlen(sir2);
  //printf("Numarul de litere al celui de-al doilea sir %d:\n",nr_litere);


   strcat(sir1,sir2);

//  strcpy(sir1,sir2);

//  int rezultat;

//  rezultat = strcmp(sir1,sir2);

//  printf("%d\n",rezultat);
  //puts(sir1);
  //puts(sir2);
  printf("%s\n",sir1);

  return 0;
}
