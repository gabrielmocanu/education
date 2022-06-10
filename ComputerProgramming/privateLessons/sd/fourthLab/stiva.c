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
      printf("Cuvantul a fost adaugat.\n");
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}

/* functie stergere ultimul cuvant din lista */
struct NOD *stergere_ultimul_nod_lista(struct NOD *prim)
{
  struct NOD *nod_curent, *nod_sters;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  /* verificare daca este singurul nod */
  if (prim->NOD_urmator==NULL)
  {
    printf("Atentie: lista are un singur cuvant si va fi stearsa complet.\n");
    free(prim);
    printf("Cuvantul a fost sters.\n");
    return NULL;
  }
  nod_curent = prim;

  while(nod_curent->NOD_urmator->NOD_urmator != NULL)
  {
    nod_curent = nod_curent -> NOD_urmator;
  }
  nod_sters = nod_curent -> NOD_urmator;

  nod_curent->NOD_urmator=NULL; // nodul curent devine ultimul
  free(nod_sters);
  printf("Cuvantul a fost sters.\n");
  return prim;
}

int extrage_valoare_ultimului_nod(struct NOD *prim)
{
  struct NOD *curent;
  curent = prim;
  while(curent -> NOD_urmator != NULL)
  {
    curent = curent -> NOD_urmator;
  }

  return curent -> valoare;
}

int stergere_extragere_valoare_nod(struct NOD **prim)
{
  int valoare;
  struct NOD *curent = *prim;
  struct NOD *sters;

  if(curent -> NOD_urmator == NULL)
  {
    valoare = curent -> valoare;
    free(curent);
    return valoare;
  }

  while(curent -> NOD_urmator -> NOD_urmator != NULL)
  {
    curent = curent -> NOD_urmator;
  }

  valoare = curent -> NOD_urmator -> valoare;
  sters = curent -> NOD_urmator;
  curent -> NOD_urmator = NULL;

  free(sters);

  return valoare;
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
  int main(int argc, char const *argv[])
  {
    lista = adaugare_nod_sfarsit_lista(lista);
    lista = adaugare_nod_sfarsit_lista(lista);
    lista = adaugare_nod_sfarsit_lista(lista);
    lista = adaugare_nod_sfarsit_lista(lista);

    afisare_lista(lista);

    lista = stergere_ultimul_nod_lista(lista);

    printf("\n");
    afisare_lista(lista);

    //int n = extrage_valoare_ultimului_nod(lista);
    printf("\n val = %d\n",extrage_valoare_ultimului_nod(lista));

    afisare_lista(lista);

    printf("\n val2 = %d\n",stergere_extragere_valoare_nod(&lista));

    afisare_lista(lista);

    int v[10];
    int i;

    for(i=0;i<2;i++)
    {
      v[i] = stergere_extragere_valoare_nod(&lista);
    }

    for(i=0;i<2;i++)
    {
      printf("%d ", v[i]);
    }

    return 0;
  }
