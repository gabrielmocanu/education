/* Sa se creeze o lista liniara dublu inlantuita cu noduri care sa contina:
- campul info numar intreg ;
- campurile prec si urm care sa contina informatii de legatura spre nodul anterior, respectiv urmator din lista.
a) Sa se afiseze lista in ambele sensuri
b) Sa se stearga toate nodurile din lista cu exceptia primului si a ultimului nod. */


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
    printf("%d \n",nod_curent->valoare);
    nod_curent = nod_curent->NOD_urmator;
  }
}

void afisare_lista_invers(struct NOD *prim)
{
  struct NOD *nod_curent = prim ;


  while(nod_curent -> NOD_urmator != NULL)
  {
    nod_curent = nod_curent -> NOD_urmator;
  }

  while(nod_curent != NULL)
  {
    printf("%d \n",nod_curent->valoare);
    nod_curent = nod_curent->NOD_anterior;
  }
}

/* functie adaugare cuvant la sfarsitul listei */
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
  if (prim->NOD_urmator==NULL && prim->NOD_anterior == NULL)
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

/* functie stergere ultimul cuvant din lista */
struct NOD *stergere_ultimul_nod_lista(struct NOD *prim)
{
  struct NOD *nod_curent;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  /* verificare daca este singurul nod */
  if (prim->NOD_urmator==NULL && prim->NOD_anterior==NULL)
  {
    free(prim);
    return NULL;
  }
  nod_curent = prim;
  while(nod_curent->NOD_urmator != NULL)
  {
    nod_curent = nod_curent->NOD_urmator;
  }

  nod_curent->NOD_anterior->NOD_urmator=NULL; // nodul curent devine ultimul
  free(nod_curent);
  return prim;
}


/* functie stergere cuvant din lista dupa valoare */
struct NOD *stergere_nod_lista(struct NOD *prim, int poz)
{
  int i=0;
  struct NOD *nod_curent, *nod_sters;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  /* daca este primul nod, se apeleaza functia anterioara */
  if (poz==1)
    return stergere_primul_nod_lista(prim);

  nod_curent = prim;
  while(nod_curent != NULL)
  {
    i++;
    if (i==poz-1) // pozitia inainte de cea dorita
      break; // memoreaza nodul de la aceasta pozitie
    nod_curent = nod_curent -> NOD_urmator;
  }

  /* daca este utimul nod, se apeleaza functia anterioara */
  if (nod_curent->NOD_urmator==NULL)
    return stergere_ultimul_nod_lista(prim);
  else
  {
    // nod_sters indica catre nodul urmator care va fi sters
    nod_sters=nod_curent->NOD_urmator;
    // nodul curent indica catre nodul urmator
    nod_curent->NOD_urmator=nod_curent->NOD_urmator->NOD_urmator;
    nod_curent->NOD_urmator->NOD_anterior = nod_curent;
    free(nod_sters); // eliberare memorie nod
    return prim;
  }
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
  printf("\n");
  afisare_lista(lista);
  printf("\n");
  afisare_lista_invers(lista);
  printf("\n");
  int noduri = nr_noduri(lista);

  for(i=0;i<noduri-2;i++)
  {
    lista = stergere_nod_lista(lista,2);
  }

  afisare_lista(lista);

  return 0;
}