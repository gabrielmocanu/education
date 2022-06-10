#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  char cuvant[20];
  struct NOD *NOD_urmator;
};

struct NOD *lista_cuvinte = NULL;

// Functia de creare nod
struct NOD* creare_nod(char comanda[])
{
  struct NOD* nod;

  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    return NULL;
  }
  strcpy(nod->cuvant,comanda);

  nod->NOD_urmator = NULL;

  return nod;
}

// Adaugare nod la inceput
struct NOD *adaugare_nod_inceput_lista(struct NOD *prim, char comanda[])
{
  struct NOD *nod_nou;
  if (prim==NULL)
  {
    return NULL;
  }
  nod_nou=creare_nod(comanda);
  /* noul nod devine primul nod in lista */
  nod_nou->NOD_urmator=prim;
  return nod_nou;
}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim, char comanda[])
{
  int i=0;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    struct NOD *prim;
    prim=creare_nod(comanda);
    return prim;
  }
  /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
    i++;
    if (nod_curent->NOD_urmator==NULL)
    {
      /* creare si inserare nod nou in lista */
      nod_nou=creare_nod(comanda);
      nod_curent->NOD_urmator=nod_nou;
      return prim;
    }
    nod_curent=nod_curent->NOD_urmator;
  }
}
/* functie adaugare cuvant in lista pe o pozitie */
struct NOD *adaugare_nod_lista(struct NOD *prim, char comanda[])
{
  int i=0, poz;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    return NULL;
  }
  scanf("%d", &poz);
  if (poz==1)
    return adaugare_nod_inceput_lista(prim,comanda);
  /* parcurgere lista cu for */
  for (nod_curent=prim; nod_curent!=NULL;nod_curent=nod_curent->NOD_urmator)
  {
    i++;
    if(i==(poz-1))
      break;
  }

  /* adaugare nod dupa cel curent*/
  if (nod_curent->NOD_urmator==NULL)
  // ultimul nod
    return adaugare_nod_sfarsit_lista(prim,comanda);
    else
    {
      nod_nou=creare_nod(comanda);
      nod_nou->NOD_urmator=nod_curent->NOD_urmator;
      nod_curent->NOD_urmator=nod_nou;
      return prim;
    }
}


void afisare_lista(struct NOD *prim)
{
  int i=0;
  struct NOD *nod_curent;

  if(prim == NULL)
  {
    return;
  }

  nod_curent = prim;

  while(nod_curent != NULL )
  {
    i++;
    printf("%d: %s\n",i,nod_curent->cuvant);
    nod_curent = nod_curent->NOD_urmator;
  }
  printf("\n");
}
/* functie stergere ultimul cuvant din lista */
struct NOD *stergere_ultimul_nod_lista(struct NOD *prim)
{
  struct NOD *nod_curent, *nod_sters;
  if (prim==NULL)
  {
    return NULL;
  }
  /* verificare daca este singurul nod */
  if (prim->NOD_urmator==NULL)
  {
    free(prim);
    return NULL;
  }
  /* parcurgere lista cu for pana la penultimul element */
  for (nod_curent=prim; nod_curent->NOD_urmator->NOD_urmator!=NULL;nod_curent=nod_curent->NOD_urmator);
    nod_sters=nod_curent->NOD_urmator; // nod_sters indica catre ultimul nod
  nod_curent->NOD_urmator=NULL; // nodul curent devine ultimul
  free(nod_sters);
  return prim;
}

struct NOD* stergere_primul_nod_lista(struct NOD *prim)
{
  struct NOD *nod_sters;
  if (prim==NULL)
  {
  return NULL;
  }
  /* verificare daca este singurul nod */
  if (prim->NOD_urmator==NULL)
  {
    free(prim);
    return NULL;
  }
  else
  {
    nod_sters=prim; // nod_sters indica spre primul nod
    prim=prim->NOD_urmator; // primul nod devine urmatorul
    free(nod_sters); // se elibereaza memoria
    return prim;
  }
}


int main(int argc, char const *argv[]) {

  char ultima_comanda[20];
  char comanda[20];
  int nr;
  scanf("%d",&nr);
  while(nr)
  {
    scanf("%s",comanda);
    if(!strcmp(comanda,"livreaza") || !strcmp(comanda,"strange"))
    {
      lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte,comanda);
    }
    if(!strcmp(comanda,"afiseaza"))
    {
      afisare_lista(lista_cuvinte);
    }
    if(!strcmp(comanda,"executa"))
    {
      strcpy(ultima_comanda,lista_cuvinte->cuvant);
      lista_cuvinte = stergere_primul_nod_lista(lista_cuvinte);
    }
    if(!strcmp(comanda,"anuleaza"))
    {
      lista_cuvinte = adaugare_nod_inceput_lista(lista_cuvinte,ultima_comanda);
    }
    nr--;
  }
  return 0;
}
