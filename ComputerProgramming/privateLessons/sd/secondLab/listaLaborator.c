#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  char cuvant[20];
  struct NOD *NOD_urmator;
};

struct NOD *lista_cuvinte = NULL;

struct NOD* creare_nod(int i)
{
  struct NOD* nod;
  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    printf("Eroare: memoria nu a putut fi alocata!\n");
    return NULL;
  }
  printf("%d: ",i);
  scanf("%s",nod->cuvant);

  nod->NOD_urmator = NULL;

  return nod;
}

struct NOD *creare_lista()
{
  struct NOD *prim;
  prim=creare_nod(1);
  return prim;
}

void populare_lista(struct NOD *prim, int n)
{
  int i;
  struct NOD *nod_nou, *nod_curent;

  if(prim == NULL)
  {
    printf("Atentie: lista este goala.\n");
    return;
  }

  nod_curent = prim;
  for(i=2;i<=n;i++)
  {
      nod_nou = creare_nod(i);
      if(nod_nou == NULL)
        return;

      nod_curent->NOD_urmator = nod_nou;
      nod_curent=nod_nou;
  }
}

void afisare_lista(struct NOD *prim)
{
  int i=0;
  struct NOD *nod_curent;

  if(prim == NULL)
  {
    printf("Atentie: lista este goala.\n");
    return;
  }

  nod_curent = prim;

  while(nod_curent != NULL )
  {
    i++;
    printf("%d: %s\n",i,nod_curent->cuvant);
    nod_curent = nod_curent->NOD_urmator;
  }
}

/* functie adaugare cuvant la inceputul listei */
struct NOD *adaugare_nod_inceput_lista(struct NOD *prim)
{
  struct NOD *nod_nou;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  nod_nou=creare_nod(1);
  /* noul nod devine primul nod in lista */
  nod_nou->NOD_urmator=prim;
  printf("Cuvantul a fost adaugat.\n");
  return nod_nou;
}
/* functie adaugare cuvant la sfarsitul listei */
struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim)
{
  int i=0;
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    printf("Atentie: lista este goala.\n");
    return NULL;
  }
  /*parcurge lista element cu element pentru a ajunge la ultimul nod*/
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
    i++;
    if (nod_curent->NOD_urmator==NULL)
    {
      /* creare si inserare nod nou in lista */
      nod_nou=creare_nod(i+1);
      nod_curent->NOD_urmator=nod_nou;
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
    printf("Atentie: lista este goala.\n");
    return NULL;
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
    nod_nou=creare_nod(poz);
    nod_nou->NOD_urmator=nod_curent->NOD_urmator;
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
    nod_sters = nod_curent->NOD_urmator;
  }
  nod_curent->NOD_urmator=NULL; // nodul curent devine ultimul
  free(nod_sters);
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
    free(nod_sters); // eliberare memorie nod
    printf("Cuvantul a fost sters.\n");
    return prim;
  }
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
  nod_curent = prim;

  while(strcmp(nod_curent->cuvant,denumire) && nod_curent != NULL )
  {
    i++;
    nod_curent = nod_curent -> NOD_urmator;
  }
  if(nod_curent == NULL)
  {
    printf("Cuvantul nu a putut fi gasit! \n");
    return prim;
  }
  if(i == 0)
  {
    return stergere_primul_nod_lista(prim);
  }
  if(nod_curent -> NOD_urmator == NULL)
  {
    return stergere_ultimul_nod_lista(prim);
  }
  nod_sters = prim;
  while(nod_sters -> NOD_urmator != nod_curent)
  {
    nod_sters = nod_sters -> NOD_urmator;
  }

  nod_sters -> NOD_urmator = nod_curent -> NOD_urmator;
  free(nod_curent);
  return prim;
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

int main()
{
  int operatie, n=0;
  char cuvant[20];
  printf("MENIU:\n");
  printf("[1] Introducerea numarului de cuvinte dorit \n");
  printf("[2] Popularea listei\n");
  printf("[3] Afisarea cuvintelor din lista\n");
  printf("[4] Adaugarea unui cuvant la inceputul listei\n");

  printf("[5] Adaugarea unui cuvant la finalul listei\n");
  printf("[6] Adaugarea unui cuvant in lista, pe o pozitie specificata de utilizator\n");
  printf("[7] Stergerea primului cuvant din lista\n");
  printf("[8] Stergerea ultimului cuvant din lista\n");
  printf("[9] Stergerea unui cuvant din lista, aflat pe o pozitie specificata de utilizator\n");
  printf("[10] Stergerea listei\n");
  printf("[11] Sterge un cuvant pe care il specifici \n");
  printf("[0] Iesire din program\n");
  do
  {
      printf("\nIntroduceti operatie: ");
      scanf("%d", &operatie);
      if (operatie==1)
      {
        printf("\nIntroducerea unui numar de cuvinte specificat in lista: ");
        do
        {
          scanf("%d", &n);
          if ((n<0) || (n>10))
            printf("\nNumarul trebuie sa fie cuprins in intervalul [0, 10]. Reintroduceti: ");
        } while((n<0) || (n>10));
        printf("Numar salvat.\n");
      }
      else if (operatie==2)
      {
        printf("\nPopularea listei\n");
        if (n==0)
          printf("Eroare: numarul de cuvinte este 0");
        else
        {
          stergere_lista(lista_cuvinte);
          lista_cuvinte=creare_lista();
          populare_lista(lista_cuvinte, n);
        }
      }
      else if (operatie==3)
      {
        printf("\nAfisarea cuvintelor din lista\n");
        afisare_lista(lista_cuvinte);
      }
      else if (operatie==4)
      {
        printf("\nAdaugarea unui cuvant la inceputul listei\n");
        lista_cuvinte=adaugare_nod_inceput_lista(lista_cuvinte);
      }
      else if (operatie==5)
      {
        printf("\nAdaugarea unui cuvant la finalul listei\n");
        lista_cuvinte=adaugare_nod_sfarsit_lista(lista_cuvinte);
      }
      else if (operatie==6)
      {
        printf("\nAdaugarea unui cuvant in lista, pe o pozitie specificata de utilizator\n");
        lista_cuvinte=adaugare_nod_lista(lista_cuvinte);
      }
      else if (operatie==7)
      {
        printf("\nStergerea primului cuvant din lista\n");
        lista_cuvinte=stergere_primul_nod_lista(lista_cuvinte);
      }
      else if (operatie==8)
      {
        printf("\nStergerea ultimului cuvant din lista\n");
        stergere_ultimul_nod_lista(lista_cuvinte);
      }
      else if (operatie==9)
      {
        printf("\nStergerea unui cuvant din lista, aflat pe o pozitie specificata de utilizator\n");
        lista_cuvinte=stergere_nod_lista(lista_cuvinte);
      }
      else if (operatie==10)
      {
        printf("\nStergerea listei\n");
        lista_cuvinte=stergere_lista(lista_cuvinte);
      }
      else if(operatie == 11)
      {
        printf("\n Sterge un cuvant pe care il specifici \n");
        lista_cuvinte=stergere_specificare_cuvant(lista_cuvinte);
      }
      else if (operatie==0)
      {
        printf("\nIesire din program\n");
        lista_cuvinte=stergere_lista(lista_cuvinte);
        break;
      }
      else
      printf("\nNumar invalid.\n");
    } while(1);

return 0;
}
