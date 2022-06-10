#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  char cuvant[20];
  struct NOD *NOD_urmator;
  struct NOD *NOD_anterior;
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

  printf("Cuvantul este: ");
  scanf("%s",nod->cuvant);

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
    printf("%s \n",nod_curent->cuvant);
    nod_curent = nod_curent->NOD_urmator;
  }
}

/* functie adaugare cuvant la inceputul listei */
struct NOD *adaugare_nod_inceput_lista(struct NOD *prim)
{
  struct NOD *nod_nou;
  if (prim==NULL)
  {
    nod_nou = creare_nod();
    return nod_nou;
  }

  nod_nou=creare_nod();
  /* noul nod devine primul nod in lista */
  nod_nou->NOD_urmator=prim;
  prim->NOD_anterior = nod_nou;
  printf("Cuvantul a fost adaugat.\n");
  return nod_nou;
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
      printf("Cuvantul a fost adaugat.\n");
      return prim;
    }
    nod_curent = nod_curent -> NOD_urmator;
  }
}

/* functie adaugare cuvant in lista pe o pozitie */
struct NOD *adaugare_nod_lista(struct NOD *prim)
{
  int i=0, poz;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou = creare_nod();
    return nod_nou;
  }
  printf("Introduceti pozitia: ");
  scanf("%d", &poz);
  if (poz==1)
    return adaugare_nod_inceput_lista(prim);

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
    return adaugare_nod_sfarsit_lista(prim);
  else
  {
    nod_nou=creare_nod();
    nod_nou->NOD_urmator = nod_curent->NOD_urmator;
    nod_nou->NOD_anterior = nod_curent;
    nod_nou->NOD_urmator->NOD_anterior = nod_nou;
    nod_curent->NOD_urmator=nod_nou;
    printf("Cuvantul a fost adaugat.\n");
    return prim;
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
    printf("Atentie: lista are un singur cuvant si va fi stearsa complet.\n");
    free(prim);
    printf("Cuvantul a fost sters.\n");
    return NULL;
  }
  nod_curent = prim;
  while(nod_curent->NOD_urmator != NULL)
  {
    nod_curent = nod_curent->NOD_urmator;
  }

  nod_curent->NOD_anterior->NOD_urmator=NULL; // nodul curent devine ultimul
  free(nod_curent);
  printf("Cuvantul a fost sters.\n");
  return prim;
}

/* functie stergere cuvant din lista dupa valoare */
struct NOD *stergere_nod_lista(struct NOD *prim)
{
  int i=0, poz;
  struct NOD *nod_curent, *nod_sters;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  printf("Introduceti pozitia: ");
  scanf("%d", &poz);
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
    printf("Cuvantul a fost sters.\n");
    return prim;
  }
}

/* functie stergere lista */
struct NOD *stergere_lista(struct NOD *prim)
{
  struct NOD *nod_curent;
  if (prim==NULL)
    return NULL;
  /* parcurgere lista si stergere elemente */
  while (prim!=NULL)
  {
    nod_curent=prim; // nod_curent indica spre primul nod
    prim=prim->NOD_urmator; // primul nod devine urmatorul
    printf("Stergere: %s\n", nod_curent->cuvant);
    free(nod_curent); // se elibereaza memoria
  }
  printf("Lista a fost stearsa.\n");
  return NULL;
}

struct NOD *stergere_specificare_cuvant(struct NOD *prim)
{
  int i = 0;
  char denumire[20];
  struct NOD *nod_curent, *nod_sters;
  if(prim == NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  printf("Introduceti cuvantul pe care vreti sa il stergeti: ");
  scanf("%s",denumire);
  nod_sters = prim;

  while(strcmp(nod_sters->cuvant,denumire) && nod_sters != NULL )
  {
    i++;
    nod_sters = nod_sters -> NOD_urmator;
  }
  if(nod_sters == NULL)
  {
    printf("Cuvantul nu a putut fi gasit! \n");
    return prim;
  }
  if(i == 0)
  {
    return stergere_primul_nod_lista(prim);
  }
  if(nod_sters -> NOD_urmator == NULL)
  {
    return stergere_ultimul_nod_lista(prim);
  }

  nod_curent = prim;
  while(nod_curent -> NOD_urmator != nod_sters)
  {
    nod_curent = nod_curent -> NOD_urmator;
  }

  nod_curent -> NOD_urmator = nod_sters -> NOD_urmator;
  nod_sters->NOD_urmator->NOD_anterior = nod_curent;
  free(nod_sters);
  return prim;
}

struct NOD *InterschimbarePrimUltim(struct NOD *prim)
{
  struct NOD* curent;
  curent = prim;
  char aux[20];

  while(curent -> NOD_urmator != NULL)
  {
    curent = curent -> NOD_urmator;
  }

  strcpy(aux,prim->cuvant);
  strcpy(prim->cuvant,curent->cuvant);
  strcpy(curent->cuvant,aux);

  return prim;

}

struct NOD *InterschimbarePrimUltim2(struct NOD *prim)
{
  struct NOD* ultim;
  struct NOD* aldoilea;
  struct NOD* penultimul;

  ultim = prim;

  while(ultim -> NOD_urmator != NULL)
  {
    ultim = ultim -> NOD_urmator;
  }

  aldoilea = prim -> NOD_urmator;

  penultimul = prim;

  while(penultimul->NOD_urmator -> NOD_urmator != NULL)
  {
    penultimul = penultimul -> NOD_urmator;
  }

  penultimul -> NOD_urmator = prim;
  ultim -> NOD_anterior = NULL;
  ultim -> NOD_urmator = prim -> NOD_urmator;
  //ultim -> NOD_urmator = aldoilea;

  //aldoilea -> NOD_anterior = ultim;
  prim -> NOD_urmator -> NOD_anterior = ultim;
  prim -> NOD_anterior = penultimul;
  prim -> NOD_urmator = NULL;

  return ultim;
}


int main(int argc, char const *argv[]) {

    lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte);
    lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte);
    lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte);
    lista_cuvinte = adaugare_nod_sfarsit_lista(lista_cuvinte);
    afisare_lista(lista_cuvinte);
    printf("\n\n\n");
    lista_cuvinte = InterschimbarePrimUltim2(lista_cuvinte);
    afisare_lista(lista_cuvinte);

  return 0;
}
