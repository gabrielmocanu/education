/* a) Sa se creeze cate o lista liniara simplu inlantuita pentru memorarea elementelor din fiecare dintre cele 2 multimi.
b) Sa se creeze o lista liniara simplu inlantuita care se memoreze reuniunea celor 2 multimi.
c) Sa se creeze o lista liniara simplu inlantuita care se memoreze intersectia celor 2 multimi.
Rezolvare */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  int valoare;
  struct NOD *NOD_urmator;
};

struct NOD *lista = NULL;

struct NOD* creare_nod()
{
  struct NOD* nod;

  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    printf("Eroare: memoria nu a putut fi alocata!\n");
    return NULL;
  }

  scanf("%d",&nod->valoare);

  nod->NOD_urmator = NULL;

  return nod;
}

struct NOD* creare_nod_argument(int x)
{
  struct NOD* nod;

  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    printf("Eroare: memoria nu a putut fi alocata!\n");
    return NULL;
  }

  nod->valoare = x;

  nod->NOD_urmator = NULL;

  return nod;
}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim)
{
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou=creare_nod();
    return nod_nou;
  }
  /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
    if (nod_curent->NOD_urmator==NULL)
    {
      /* creare si inserare nod nou in lista */
      nod_nou=creare_nod();
      nod_curent->NOD_urmator=nod_nou;
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}

struct NOD *adaugare_nod_sfarsit_lista_parametru(struct NOD *prim, int x)
{
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou=creare_nod_argument(x);
    return nod_nou;
  }
  /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
    if (nod_curent->NOD_urmator==NULL)
    {
      /* creare si inserare nod nou in lista */
      nod_nou=creare_nod_argument(x);
      nod_curent->NOD_urmator=nod_nou;
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}

void afisare_lista(struct NOD *prim)
{
  struct NOD *nod_curent;

  if(prim == NULL)
  {
    printf("Atentie: lista este goala.\n");
    return;
  }

  nod_curent = prim;

  while(nod_curent != NULL )
  {
    printf("%d ",nod_curent->valoare);
    nod_curent = nod_curent->NOD_urmator;
  }
  printf("\n");
}

struct NOD *Reuniune(struct NOD* lista1, struct NOD *lista2)
{
  struct NOD *curent1 = lista1;
  struct NOD *curent2 = lista2;
  struct NOD *curent3;
  struct NOD *reuniune;

  while(curent1 != NULL)
  {
    reuniune = adaugare_nod_sfarsit_lista_parametru(reuniune,curent1->valoare);
    curent1 = curent1 -> NOD_urmator;
  }

  while(curent2 != NULL)
  {

    curent3 = reuniune;
    while(curent3 != NULL)
    {
      if(curent2 -> valoare == curent3 ->valoare)
      {
        break;
      }
      curent3 = curent3 -> NOD_urmator;
    }

    if(curent3 == NULL )
    {
      reuniune = adaugare_nod_sfarsit_lista_parametru(reuniune,curent2->valoare);
    }

    curent2 = curent2 -> NOD_urmator;
  }

  return reuniune;
}

struct NOD *intersectia(struct NOD *lista1, struct NOD* lista2)
{
  struct NOD *curent1 = lista1;
  struct NOD *curent2 = lista2;
  struct NOD *intersectia;

  while(curent1 != NULL)
  {
    curent2 = lista2;
    while(curent2 != NULL)
    {
      if(curent1 -> valoare == curent2 -> valoare)
      {
        intersectia = adaugare_nod_sfarsit_lista_parametru(intersectia,curent2->valoare);
        break;
      }
      curent2 = curent2 -> NOD_urmator;
    }
    curent1 = curent1 -> NOD_urmator;
  }
  return intersectia;
}


int main(int argc, char const *argv[]) {

  int nr1,nr2;
  int i;

  struct NOD *lista1 = NULL;
  struct NOD *lista2 = NULL;

  struct NOD *lista_reuniune = NULL;
  struct NOD *lista_intersectia = NULL;

  printf("Introdu numarul de numere din prima multime: ");
  scanf("%d",&nr1);

  for(i=0;i<nr1;i++)
    lista1 = adaugare_nod_sfarsit_lista(lista1);

  printf("Introdu numarul de numere din a doua multime: ");
  scanf("%d",&nr2);

  for(i=0;i<nr2;i++)
    lista2 = adaugare_nod_sfarsit_lista(lista2);

    afisare_lista(lista1);
    afisare_lista(lista2);

    lista_reuniune = Reuniune(lista1,lista2);

    afisare_lista(lista_reuniune);

    lista_intersectia = intersectia(lista1,lista2);

    afisare_lista(lista_intersectia);

    return 0;
}
