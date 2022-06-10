#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipul de structura utilizata
struct structura_laptop
{
  char denumire[20];
  int pret;
};

// Functie de creare laptop
struct structura_laptop functieAdaugare(char denumire[], int pret)
{
  struct structura_laptop y;
  strcpy(y.denumire,denumire);
  y.pret = pret;
  return y;
}

// functie stergere laptop
void functieStergere(int poz,struct structura_laptop *y,int *nr_laptopuri)
{
  int i;
  for(i=poz-1;i<*nr_laptopuri;i++)
  {
    y[i] = y[i+1];
  }
  (*nr_laptopuri)--;

}

int main(int argc, char const *argv[]) {

  struct structura_laptop x[20];

  int pret_auxiliar;
  char denumire_auxiliara[20];

  int i;
  int nr_laptopuri;
  printf("Introduceti numarul de laptopuri: ");
  scanf("%d",&nr_laptopuri);

  for(i=0;i<nr_laptopuri;i++)
  {
    printf("\n Denumire laptop: ");
    scanf("%s",denumire_auxiliara);
    printf("\n Pret laptop: ");
    scanf("%d",&pret_auxiliar);
    x[i] = functieAdaugare(denumire_auxiliara,pret_auxiliar);
  }

    functieStergere(1,x,&nr_laptopuri);
    functieStergere(4,x,&nr_laptopuri);


  for(i=0;i<nr_laptopuri;i++)
  {
    printf("denumire = %s si pret = %d\n",x[i].denumire,x[i].pret);
  }

  return 0;
}
