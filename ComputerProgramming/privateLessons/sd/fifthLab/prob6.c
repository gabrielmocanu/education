// Numere duplicate

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

int VerificaDuplicate(struct NOD *prim)
{
  struct NOD *duplicat;
  struct NOD *curent = prim;

  while(curent -> NOD_urmator != NULL)
  {
    duplicat = curent -> NOD_urmator;
    while(duplicat != NULL)
    {
      if(duplicat -> valoare == curent -> valoare)
      {
        return 1;
      }
      duplicat = duplicat -> NOD_urmator;
    }
    curent = curent -> NOD_urmator;
  }

  return 0;
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

  if(VerificaDuplicate(lista) == 1)
  {
    printf("Exista duplicate in lista. \n");
  }
  else
  {
    printf("Nu exista duplicate in lista. \n");
  }

  return 0;
}
