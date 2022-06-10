#include<stdio.h>
#include<stdlib.h>
/* definire structura arbore */
struct NOD
{
  int x;
  struct NOD *NOD_stanga;
  struct NOD *NOD_dreapta;
};

/* functie creare nod nou */
struct NOD *creare_nod(int x)
{
  struct NOD *nod_nou;
  /* alocare memorie nod*/
  nod_nou=(struct NOD *)malloc(sizeof(struct NOD));
  if (nod_nou==NULL)
  {
    printf("Eroare: Memoria nu a putut fi alocata! \n");
    return NULL;
  }

  /* initializare informatii */
  nod_nou->x=x;
  nod_nou->NOD_stanga=NULL;
  nod_nou->NOD_dreapta=NULL;
  return nod_nou;
}

/* inserare nod in arbore */
struct NOD *inserare_nod(struct NOD *prim, int x)
{
  struct NOD *nod_nou, *nod_curent, *nod_parinte;
  nod_nou=creare_nod(x);
  if (prim==NULL)
  {
    /* arborele este vid */
    prim=nod_nou;
    printf("A fost adaugat primul nod: %d. \n", prim->x);
    return prim;
  }
  else
  {
    /* pozitionare in arbore pe parintele nodului nou */
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
      nod_parinte=nod_curent;
    if (x<nod_curent->x) /* parcurgere spre stanga */
      nod_curent=nod_curent->NOD_stanga;

    else /* parcurgere spre dreapta */
      nod_curent=nod_curent->NOD_dreapta;
  }
  /* creare legatura nod parinte cu nodul nou */
  if (x<nod_parinte->x)
  {
    /* se insereaza la stanga nodului parinte */
    nod_parinte->NOD_stanga=nod_nou;
    printf("Nodul %d a fost inserat la stanga nodului %d. \n",x, nod_parinte->x);
  }

  else
  {
  /* se insereaza la dreapta nodului parinte */
  nod_parinte->NOD_dreapta=nod_nou;
  printf("Nodul %d a fost inserat la dreapta nodului %d.\n", x, nod_parinte->x);
  }
  return prim;
  }
}

/* parcurgere arbore in preordine */
void afisare_preordine(struct NOD *prim)
{
  if (prim!=NULL)
  {
  /* parcurgere radacina, stanga, dreapta */
  printf("%d \n", prim->x);
  afisare_preordine(prim->NOD_stanga);
  afisare_preordine(prim->NOD_dreapta);
  }
}

/* parcurgere arbore in inordine */
void afisare_inordine(struct NOD *prim)
{
  if (prim!=NULL)
  {
  /* parcurgere stanga, radacina, dreapta */
  afisare_inordine(prim->NOD_stanga);
  printf("%d \n", prim->x);
  afisare_inordine(prim->NOD_dreapta);
  }
}
/* parcurgere arbore in postordine */
void afisare_postordine(struct NOD *prim)
{
  if (prim!=NULL)
  {
  /* parcurgere stanga, dreapta, radacina */
  afisare_postordine(prim->NOD_stanga);
  afisare_postordine(prim->NOD_dreapta);
  printf("%d \n", prim->x);
  }
}

/* stergerea unui arbore sau subarbore */
struct NOD *stergere_arbore(struct NOD *tmp)
{
  if (tmp!=NULL)
  {
    stergere_arbore(tmp->NOD_stanga);
    stergere_arbore(tmp->NOD_dreapta);
    free(tmp);
  }
  return NULL;
}

/* cautarea unui nod dorit */
struct NOD *cauta_nod(struct NOD *tmp, int x)
{
  if (tmp!=NULL)
  {
    if (x==tmp->x)
    {
      printf("Nodul a fost gasit. \n");
      return tmp;
    }
    else if (x<tmp->x)
      return cauta_nod(tmp->NOD_stanga, x);
    else
      return cauta_nod(tmp->NOD_dreapta, x);
  }
  else
  {
    printf("Nodul dorit nu exista in arbore.\n");
    return NULL;
  }
}

int nr_noduri_frunza(struct NOD* prim)
{
  if(prim == NULL)
    return 0;

  if(prim -> NOD_stanga == NULL && prim -> NOD_dreapta == NULL)
    return 1;
  else
    return nr_noduri_frunza(prim->NOD_stanga) + nr_noduri_frunza(prim -> NOD_dreapta);

}

int numar_noduri(struct NOD* prim)
{
  if(prim == NULL)
    return 0;
  else
    return (numar_noduri(prim->NOD_stanga)+1+numar_noduri(prim->NOD_dreapta));
}

int cauta_nerecursiv(struct NOD* prim, int x)
{
  struct NOD *nod_curent = prim;
  while( nod_curent != NULL)
  {
    if( x > nod_curent->x )
    {
      nod_curent = nod_curent -> NOD_dreapta;
    }
    else if(x < nod_curent->x)
    {
      nod_curent = nod_curent -> NOD_stanga;
    }
    else
    {
      return 1;
    }
  }

  return 0;
}
int main()
{
  struct NOD *prim=NULL, *nod_gasit;

  prim = inserare_nod(prim,10);
  prim = inserare_nod(prim,15);
  prim = inserare_nod(prim,16);
  prim = inserare_nod(prim,8);
  prim = inserare_nod(prim,9);

  afisare_preordine(prim);

  printf("Numar noduri frunza = %d\n",nr_noduri_frunza(prim));

  printf("Numar noduri = %d\n",numar_noduri(prim));

  int n;
  scanf("%d",&n);
  printf("Cautat = %d",cauta_nerecursiv(prim,n));


//   char operatie;
//   int x;
//   printf("MENIU: \n");
//   printf("[1] Inserare nod in arbore \n");
//   printf("[2] Afisare arbore preordine \n");
//   printf("[3] Afisare arbore inordine \n");
//   printf("[4] Afisare arbore postordine \n");
//   printf("[5] Stergere arbore \n");
//   printf("[6] Cautare nod in arbore \n");
//   printf("[0] Iesire din program \n");
//
//   do
//   {
//     printf("\nIntroduceti operatie: ");
//     operatie=getchar();
//     printf("\n");
//     switch (operatie)
//     {
//       case '1':
//       printf("#Inserare nod in arbore# \n");
//       printf("Introduceti valoarea nodului care va fi inserat: ");
//       scanf("%d", &x);
//       prim=inserare_nod(prim, x);
//       break;
//
//       case '2':
//   printf("#Afisare arbore preordine# \n");
//   if (prim==NULL)
//   printf("Atentie: Arborele este gol.");
//   else
//   afisare_preordine(prim);
//   break;
//
//   case '3':
//   printf("#Afisare arbore inordine# \n");
//   if (prim==NULL)
//   printf("Atentie: Arborele este gol.");
//   else
//   afisare_inordine(prim);
//   break;
//
//   case '4':
//   printf("Afisare arbore postordine: \n");
//   if (prim==NULL)
//   printf("Atentie: Arborele este gol.");
//   else
//   afisare_postordine(prim);
//   break;
//
//   case '5':
//   printf("#Stergere arbore# \n");
//   if (prim==NULL)
//     printf("Atentie: Arborele este gol.");
//     else
//     {
//       printf("Introduceti valoarea nodul al carui arbore va fi sters: ");
//       scanf("%d", &x);
//       nod_gasit=cauta_nod(prim, x);
//       if (nod_gasit!=NULL)
//       {
//         nod_gasit->NOD_stanga = stergere_arbore(nod_gasit->NOD_stanga);
//         nod_gasit->NOD_dreapta=stergere_arbore(nod_gasit->NOD_dreapta);
//         printf("Arborele a fost sters. \n");
//       }
//     }
//     break;
//
//     case '6':
//       printf("#Cautare nod in arbore# \n");
//       if (prim==NULL)
//         printf("Atentie: Arborele este gol.");
//       else
//       {
//         printf("Introduceti valoarea nodului: ");
//         scanf("%d", &x);
//         cauta_nod(prim, x);
//       }
//       break;
//
//       case '0':
//       printf("Iesire din program \n");
//       stergere_arbore(prim);
//       return 0;
//       break;
//
//       default:
//       printf("Operatie invalida \n");
//     }
// } while(1);
}
