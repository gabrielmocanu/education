/* Eu am avut cv cu emailuri. Sa le ordonezi descrescator. Sa cauti un email dupa un cuvant cheie Si odata
gasit, sa il stergi Si apoi sa afisezi .Si trebuia sa introduci de la tastatura nr de mailuri si cuvantu cheie
dupa care cauti */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NOD
{
  char nume[20];
  struct NOD *NOD_urmator;
  struct NOD *NOD_anterior;
};

struct NOD *lista_mail = NULL;

struct NOD* creare_nod()
{
  struct NOD* nod;
  nod = (struct NOD *)malloc(sizeof(struct NOD));

  if(nod == NULL)
  {
    printf("Eroare: memoria nu a putut fi alocata!\n");
    return NULL;
  }

  printf("Mailul este: ");
  scanf("%s",nod->nume);

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
    printf("%s \n",nod_curent->nume);
    nod_curent = nod_curent->NOD_urmator;
  }
}

/* functie adaugare cuvant la sfarsitul listei */
struct NOD *adaugare_nod_sfarsit_lista(struct NOD *prim)
{
  struct NOD *nod_curent, *nod_nou;
  if (prim==NULL)
  {
    nod_nou = creare_nod();
    printf("Mailul a fost adaugat.\n");
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
      printf("Mailul a fost adaugat.\n");
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
    printf("Atentie: lista are un singur nod si va fi stearsa complet.\n");
    printf("A fost sters mailul %s\n",prim->nume);
    free(prim);
    printf("Cuvantul a fost sters.\n");
    return NULL;
  }
  else
  {
    nod_sters=prim; // nod_sters indica spre primul nod
    prim=prim->NOD_urmator; // primul nod devine urmatorul
    printf("A fost sters mailul %s\n",nod_sters->nume);
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
    printf("Mailul a fost sters.\n");
    return NULL;
  }
  nod_curent = prim;
  while(nod_curent->NOD_urmator != NULL)
  {
    nod_curent = nod_curent->NOD_urmator;
  }

  nod_curent->NOD_anterior->NOD_urmator=NULL; // nodul curent devine ultimul
  printf("A fost sters mailul %s\n",nod_curent -> nume);
  free(nod_curent);
  printf("Mailul a fost sters.\n");
  return prim;
}

struct NOD *Cauta(struct NOD *prim, char nume_cautat[20])
{
  struct NOD *nod_curent = prim;
  struct NOD *sters = prim;

  while(strcmp(sters->nume,nume_cautat) && sters -> NOD_urmator != NULL)
  {
    sters = sters -> NOD_urmator;
  }

  if(sters -> NOD_urmator == NULL )
  {
    printf("Mailul nu a putut fi gasit!\n");
    return prim;
  }

  if(sters -> NOD_anterior == NULL)
    return stergere_primul_nod_lista(prim);

  if(sters -> NOD_urmator == NULL)
    return stergere_ultimul_nod_lista(prim);

  nod_curent = sters -> NOD_anterior;

  nod_curent -> NOD_urmator = sters -> NOD_urmator;
  sters -> NOD_urmator -> NOD_anterior = nod_curent;

  printf("A fost sters si cautat mailul : %s\n",sters->nume);
  free(sters);

  return prim;

}

struct NOD *Inverseaza(struct NOD *prim)
{
  struct NOD *temp = NULL;
  struct NOD *curent = prim;

  while( curent !=  NULL )
  {
      temp = curent->NOD_anterior;
      curent->NOD_anterior = curent->NOD_urmator;
      curent->NOD_urmator = temp;

      curent = curent->NOD_anterior;
  }

  if(temp != NULL)
    prim = temp -> NOD_anterior;

  return prim;
}

struct NOD *Interschimbare(struct NOD* prim, int poz1, int poz2)
{
  struct NOD *p1 = prim;
  struct NOD *p2 = prim;

  struct NOD *pre1 = prim;
  struct NOD *pre2 = prim;

  struct NOD *post1 = prim;
  struct NOD *post2 = prim;

  int i;

  for(i=1;i<poz1;i++)
    p1 = p1 -> NOD_urmator;

  for(i=1;i<poz2;i++)
    p2 = p2 -> NOD_urmator;



  pre1 = p1->NOD_anterior;
  pre2 = p2->NOD_anterior;

  post1 = p1->NOD_urmator;
  post2 = p2->NOD_urmator;

  if(poz1 == 1)
  {
    //post1 = p1->NOD_urmator;
    //pre2 = p2 -> NOD_anterior;

    p1 -> NOD_anterior = pre2;
    p1 -> NOD_urmator -> NOD_anterior = p2; // sau post1-> NOD_anterior = p2

    p1 -> NOD_urmator = p2 ->NOD_urmator;

    pre2 -> NOD_urmator = p1;
    p2 -> NOD_anterior = NULL;
    p2 -> NOD_urmator = post1;
    return p2;
  }

  if(poz2 - poz1 == 1)
  {

    p1->NOD_urmator = post2;
    p1->NOD_anterior = p2;
    post2 -> NOD_anterior = p1;

    pre1 -> NOD_urmator = p2;
    p2 -> NOD_anterior = pre1;
    p2 -> NOD_urmator = p1;

    return prim;
  }

  pre1 -> NOD_urmator = p2;
  p2 -> NOD_anterior = pre1;
  p2 -> NOD_urmator = p1 ->NOD_urmator;

  pre2 -> NOD_urmator = p1;
  p1 -> NOD_urmator = post2;
  p1 -> NOD_anterior = pre2;

  return prim;
}

int main(int argc, char const *argv[]) {

  char nume_cautat[20];
  int nr;
  int i;

  printf("Introduceti numarul de mailuri dorite:");
  scanf("%d",&nr);

  for(i=0;i<nr;i++)
  {
    lista_mail = adaugare_nod_sfarsit_lista(lista_mail);
  }
  //
  // printf("Introduceti mailul cautat: ");
  // scanf("%s",nume_cautat);
  //
  // lista_mail = Cauta(lista_mail,nume_cautat);
  //
  // afisare_lista(lista_mail);


  // printf("Afiseaza lista inversata: \n");
  //
   // lista_mail = Inverseaza(lista_mail);
   // afisare_lista(lista_mail);

  lista_mail = Interschimbare(lista_mail,1,3);
  afisare_lista(lista_mail);

   return 0;
}
