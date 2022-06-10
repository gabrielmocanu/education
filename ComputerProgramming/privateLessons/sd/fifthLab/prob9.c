
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  int valoare;
  struct NOD *NOD_urmator;
  struct NOD *NOD_anterior;
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
  nod->NOD_anterior = NULL;

  return nod;
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

struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim)
{
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou = creare_nod();
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
      nod_nou->NOD_anterior = nod_curent;
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}

void AfisarePerechi(struct NOD *prim, int nr)
{
  int i;
  struct NOD *curent = prim;
  struct NOD *ultim = prim;

  while(ultim -> NOD_urmator != NULL)
    ultim = ultim -> NOD_urmator;

  for(i=0;i<nr/2;i++)
  {
    printf("(%d,%d) ",curent->valoare,ultim->valoare);
    curent = curent -> NOD_urmator;
    ultim = ultim -> NOD_anterior;
  }

  if(nr % 2 == 1 ) // sau != 0
    printf("%d",curent->valoare);

  printf("\n");


}

int nr_noduri(struct NOD *prim)
{
  struct NOD* curent;
  curent = prim;

  int nr = 0;
  while(curent != NULL)
  {
    nr++;
    curent = curent -> NOD_urmator;
  }

  return nr;
}

int main(int argc, char const *argv[]) {


    int nr;
    int i;
    printf("Introdu numarul de numere:");

    scanf("%d",&nr);

    for(i=0;i<nr;i++)
    {
        lista = adaugare_nod_sfarsit_lista(lista);
    }
    afisare_lista(lista);

    int n = nr_noduri(lista);

    AfisarePerechi(lista,nr);

    return 0;
}
