#include<stdio.h>
#include<stdlib.h>
/* definire structura arbore */
struct NOD
{
  int data;
  struct NOD *NOD_stanga;
  struct NOD *NOD_dreapta;
};

/* functie creare nod nou */
struct NOD *creare_nod(int data)
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
  nod_nou->data=data;
  nod_nou->NOD_stanga=NULL;
  nod_nou->NOD_dreapta=NULL;
  return nod_nou;
}

/* inserare nod in arbore */
struct NOD *inserare_nod(struct NOD *prim, int data)
{
  struct NOD *nod_nou, *nod_curent, *nod_parinte;
  nod_nou=creare_nod(data);
  if (prim==NULL)
  {
    /* arborele este vid */
    prim=nod_nou;
    printf("A fost adaugat primul nod: %d. \n", prim->data);
    return prim;
  }
  else
  {
    /* pozitionare in arbore pe parintele nodului nou */
  nod_curent=prim;
  while (nod_curent!=NULL)
  {
      nod_parinte=nod_curent;
    if (data<nod_curent->data) /* parcurgere spre stanga */
      nod_curent=nod_curent->NOD_stanga;

    else /* parcurgere spre dreapta */
      nod_curent=nod_curent->NOD_dreapta;
  }
  /* creare legatura nod parinte cu nodul nou */
  if (data<nod_parinte->data)
  {
    /* se insereaza la stanga nodului parinte */
    nod_parinte->NOD_stanga=nod_nou;
    printf("Nodul %d a fost inserat la stanga nodului %d. \n",data, nod_parinte->data);
  }

  else
  {
  /* se insereaza la dreapta nodului parinte */
  nod_parinte->NOD_dreapta=nod_nou;
  printf("Nodul %d a fost inserat la dreapta nodului %d.\n", data, nod_parinte->data);
  }
  return prim;
  }
}

/* parcurgere arbore in preordine */
void afisare_preordine(struct NOD *prim, int *i, int v[])
{
  if (prim!=NULL)
  {
  /* parcurgere radacina, stanga, dreapta */

  prim->data = v[*i];
  printf("data = %d v = %d i = %d\n", prim->data,v[*i],*i);
  *i = *i + 1;
  afisare_preordine(prim->NOD_stanga,i,v);
  afisare_preordine(prim->NOD_dreapta,i,v);
  }
}

void afisare_preordine2(struct NOD *prim)
{
  if (prim!=NULL)
  {
  /* parcurgere radacina, stanga, dreapta */
  printf("%d \n", prim->data);
  afisare_preordine2(prim->NOD_stanga);
  afisare_preordine2(prim->NOD_dreapta);
  }
}

/* parcurgere arbore in inordine */
void afisare_inordine(struct NOD *prim)
{
  if (prim!=NULL)
  {
  /* parcurgere stanga, radacina, dreapta */
  afisare_inordine(prim->NOD_stanga);
  printf("%d \n", prim->data);
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
  printf("%d \n", prim->data);
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
struct NOD *cauta_nod(struct NOD *tmp, int data)
{
  if (tmp!=NULL)
  {
    if (data==tmp->data)
    {
      printf("Nodul a fost gasit. \n");
      return tmp;
    }
    else if (data<tmp->data)
      return cauta_nod(tmp->NOD_stanga, data);
    else
      return cauta_nod(tmp->NOD_dreapta, data);
  }
  else
  {
    printf("Nodul dorit nu edataista in arbore.\n");
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

int cauta_nerecursiv(struct NOD* prim, int data)
{
  struct NOD *nod_curent = prim;
  while( nod_curent != NULL)
  {
    if( data > nod_curent->data )
    {
      nod_curent = nod_curent -> NOD_dreapta;
    }
    else if(data < nod_curent->data)
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

  int i;
  for(i=0;i<100;i++)
 {
   prim = inserare_nod(prim,0);
}

  i = 0;
  int v[100];
  for(i=0;i<100;i++)
    v[i] = i;

  i = 0;
  afisare_preordine(prim,&i,v);

  printf("Numar noduri frunza = %d\n",nr_noduri_frunza(prim));

  printf("Numar noduri = %d\n",numar_noduri(prim));
  afisare_preordine2(prim);

//  int n;
//  scanf("%d",&n);
//  printf("Cautat = %d",cauta_nerecursiv(prim,n));

}
