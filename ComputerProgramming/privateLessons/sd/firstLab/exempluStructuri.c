#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct{

  char *strada, *oras;
  int numar;
}adresa;

typedef struct{
  char *nume;
  int *cnp;
  adresa detalii;
}persoana;

int main(int argc, char const *argv[]) {

  persoana p;
  p.detalii.strada = (char *)malloc(100*sizeof(char));
  p.detalii.oras = (char *)malloc(100*sizeof(char));

  scanf("%s", p.detalii.strada);
  scanf("%s", p.detalii.oras);
  scanf("%d",&p.detalii.numar);

  printf("Persoana sta pe strada %s in orasul %s la numarul %d\n",p.detalii.strada,p.detalii.oras,p.detalii.numar);

  p.nume = (char *)malloc(100*sizeof(char));
  p.cnp = (int *)malloc(100*sizeof(int));

  scanf("%s",p.nume);
  scanf("%d",p.cnp);

  printf("Persoana se numeste %s si are cnp-ul ",p.nume);

  int i;
  for(i=0;i<20;i++)
  {
    printf("%d",p.cnp[i]);
  }





  return 0;
}
