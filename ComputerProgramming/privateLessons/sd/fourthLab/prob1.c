#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  int valoare;
  struct NOD *NOD_urmator;
};

struct NOD *lista_cuvinte = NULL;

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

struct NOD* creare_nod2(int val)
{
  struct NOD* nod;

  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    printf("Eroare: memoria nu a putut fi alocata!\n");
    return NULL;
  }

  nod -> valoare = val;
  //scanf("%d",&nod->valoare);

  nod->NOD_urmator = NULL;

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
    printf("%d\n",nod_curent->valoare);
    nod_curent = nod_curent->NOD_urmator;
  }
}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim, int val)
{
  int i=0;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou=creare_nod2(val);
    return nod_nou;
  }
  /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
    i++;
    if (nod_curent->NOD_urmator==NULL)
    {
      /* creare si inserare nod nou in lista */
      nod_nou=creare_nod2(val);
      nod_curent->NOD_urmator=nod_nou;
      printf("Cuvantul a fost adaugat.\n");
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}
/* functie adaugare cuvant la inceputul listei */
struct NOD *adaugare_nod_inceput_lista(struct NOD *prim, int val)
{
  struct NOD *nod_nou;
  if (prim==NULL)
  {
      nod_nou=creare_nod2(val);
      return nod_nou;
  }
  nod_nou=creare_nod2(val);
  /* noul nod devine primul nod in lista */
  nod_nou->NOD_urmator=prim;
  printf("Cuvantul a fost adaugat.\n");
  return nod_nou;
}

/* functie adaugare cuvant in lista pe o pozitie */
struct NOD *adaugare_nod_lista(struct NOD *prim, int poz, int val)
{
  int i=0;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou=creare_nod2(val);
    return nod_nou;
  }
  if (poz==1)
    return adaugare_nod_inceput_lista(prim,val);
  nod_curent = prim;
  while(nod_curent != NULL)
  {
    i++;
    if (i==(poz-1)) // pozitia inainte de cea dorita
      break; // pozitionare pe nodul de la aceasta pozitie
    nod_curent = nod_curent -> NOD_urmator;
  }
  /* adaugare nod dupa cel curent*/
  if (nod_curent->NOD_urmator==NULL) // ultimul nod
    return adaugare_nod_sfarsit_lista(prim, val);
  else
  {
    nod_nou=creare_nod2(val);
    nod_nou->NOD_urmator=nod_curent->NOD_urmator;
    nod_curent->NOD_urmator=nod_nou;
    printf("Cuvantul a fost adaugat.\n");
    return prim;
  }
}

struct NOD *SchimbaNumerePare(struct NOD *prim)
{
  int i = 1;
  struct NOD *curent = prim;
  while(curent != NULL)
  {
    if(curent -> valoare % 2 == 0)
    {
      prim = adaugare_nod_lista(prim,i,curent->valoare);
      curent -> valoare = curent -> valoare * 2;
      i++;
    }
    i++;
    curent = curent -> NOD_urmator;
  }
  return prim;
}

int main(int argc, char const *argv[]) {

  lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte,10);
  lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte,3);
  lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte,16);
  lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte,17);

  afisare_lista(lista_cuvinte);

  lista_cuvinte = SchimbaNumerePare(lista_cuvinte);

  afisare_lista(lista_cuvinte);

  return 0;
}
