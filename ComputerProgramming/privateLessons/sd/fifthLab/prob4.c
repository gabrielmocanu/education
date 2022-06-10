// verificare

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

/* functie stergere primul cuvant din lista */
struct NOD *stergere_primul_nod_lista(struct NOD *prim)
{
  struct NOD *nod_sters;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  /* verificare daca este singurul nod */
  if (prim->NOD_urmator==NULL)
  {
    printf("Atentie: lista are un singur nod si va fi stearsa complet.\n");
    free(prim);
    printf("Cuvantul a fost sters.\n");
    return NULL;
  }
  else
  {
    nod_sters=prim; // nod_sters indica spre primul nod
    prim=prim->NOD_urmator; // primul nod devine urmatorul
    free(nod_sters); // se elibereaza memoria
    printf("Cuvantul a fost sters.\n");
    return prim;
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

struct NOD *Verifica(struct NOD *prim, int x)
{
  int i = 0;
  struct NOD *curent = prim;
  struct NOD *sters = prim;
  while(sters != NULL)
  {
    if(sters -> valoare < x)
    {
      curent = prim;
      while(curent -> NOD_urmator != sters && curent -> NOD_urmator != NULL)
      {
        curent = curent -> NOD_urmator;
      }

      if(curent -> NOD_urmator == NULL)
      {
        curent = sters;
      }

      if(curent == sters)
      {
        sters = curent -> NOD_urmator;
        free(curent);
        prim = sters;
        continue;
      }

      curent -> NOD_urmator = sters -> NOD_urmator;
      free(sters);

      sters = curent -> NOD_urmator;
      continue;
    }
    sters = sters -> NOD_urmator;
  }

  return prim;
}

int main(int argc, char const *argv[])
{

  int nr;
  int i;
  printf("Introdu numarul de numere:");

  scanf("%d",&nr);

  for(i=0;i<nr;i++)
  {
      lista = adaugare_nod_sfarsit_lista(lista);
  }

  printf("Introdu marja: ");
  int marja;

  scanf("%d",&marja);

  lista = Verifica(lista,marja);

  printf("\n");
  afisare_lista(lista);

  return 0;
}
