// permutare

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
    printf("%d\n",nod_curent->valoare);
    nod_curent = nod_curent->NOD_urmator;
  }
}

struct NOD *Permutare(struct NOD *prim, int nr)
{
  int i;

  for(i=0;i<nr;i++)
  {
    struct NOD *ultim = prim;
    struct NOD *penultim = prim;

    while(ultim -> NOD_urmator != NULL)
    {
      ultim = ultim -> NOD_urmator;
    }

    while(penultim -> NOD_urmator -> NOD_urmator != NULL)
    {
      penultim = penultim -> NOD_urmator;
    }

    penultim -> NOD_urmator = NULL;
    ultim -> NOD_urmator = prim;

    prim = ultim;
}
  return prim;
}

int main(int argc, char const *argv[]) {
  int permutari;
  int nr;
  int i;
  printf("Introdu numarul de numere:");

  scanf("%d",&nr);

  for(i=0;i<nr;i++)
  {
      lista = adaugare_nod_sfarsit_lista(lista);
  }

  printf("Introdu numarul de permutari: ");
  scanf("%d",&permutari);

  lista = Permutare(lista,permutari);
  afisare_lista(lista);
  return 0;
}
