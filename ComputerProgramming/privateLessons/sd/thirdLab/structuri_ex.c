/* Să se realizeze un program ce permite stocarea imaginilor unei secvenţe video. Fiecare imagine
va conţine următoarele informaţii: o matrice de dimensiune m x n de valori pe 4 biţi (imagine),
un şir de caractere de maxim 10 elemente (nume) şi histograma imaginii (numărul de apariţii
ale fiecărei valori din matrice). */


#include <stdio.h>
#include <stdlib.h>
/* Declarare structura */
struct imagine
{
  int *matrice;
  char nume[10];
  int hist[16];
};

  /* Declarare vector de structuri */
  struct imagine *secventa_video;

  /* Alocarea si citirea unei imagini cu dimensiunile acesteia */
  int *citire_matrice(int *dim1, int *dim2)
  {
    int i, j;
    int *M;
    /* Se citesc dimensiunile imaginii */
    if ((*dim1 == 0) && (*dim2 == 0))
    {
      printf("Introduceti numarul de linii: ");
      scanf("%d", dim1);
      printf("Introduceti numarul de coloane: ");
      scanf("%d", dim2);
    }

    /* Alocare dinamica memorie *dim1 x *dim2 x 1 byte */
    M = (int *)malloc((*dim1)*(*dim2)*sizeof(int));
    if (!M)
    {
      printf("\nMemoria nu a putut fi alocata!");
    }
    
    printf("Citire valori matrice:\n");
    for (i=0; i<*dim1; i++)
      for (j=0; j<*dim2; j++)
      {
        printf("M[%d][%d] = ", i+1, j+1);
        scanf("%d", M+*dim2*i+j);
      }

      // Returnare pointer la memoria alocata
      return M;
}

/* Afisare imagine */
void afisare_matrice(int *M, int dim1, int dim2)
{
  int i,j;
  for (i=0; i<dim1; i++)
  {
    for (j=0; j<dim2; j++)
    printf("%3d", *(M+dim2*i+j));
    printf("\n");
  }
}

/* Calcul histograme imagini */
void calcul_histograme(struct imagine *secventa_video, int nr_imagini, int dim1, int dim2)
{
  int k, i, j;
  int *matrice;
  for (k=0; k<nr_imagini; k++)
  {
    /* Preluare pointer la imaginea curenta */
    matrice = (secventa_video+k)->matrice;
    /* Initializare cu 0 */
    for (j=0; j<16; j++)
      (secventa_video+k)->hist[j] = 0;
/* Incrementeaza valoarea de la pozitia indicata de
valoarea elementului matricei */
  for (i=0; i<dim1; i++)
    for (j=0; j<dim2; j++)
      (secventa_video+k)->hist[*(matrice+i*dim2+j)]++;
    }
}

/* Eliberare memorie */
void eliberare_structura(struct imagine *secventa_video)
{
  // verificare daca structura a fost alocata
  if (secventa_video!=NULL)
    free(secventa_video);
}
int main()
{
  /* Declarare variabile */
  int nr_imagini, dim1=0, dim2=0, k;
  /* Citire numar de imagini */
  printf("\nIntroduceti numarul de imagini din secventa video: ");
  scanf("%d", &nr_imagini);
  /* Alocare dinamica a spatiului de memorie pentru structura */
  secventa_video = (struct imagine *)malloc(nr_imagini*sizeof(struct imagine));

  /* Citire nume si matrice imagini */
  for (k=0; k<nr_imagini; k++)
  {
    printf("\nIntroduceti date imagine %d:\n", k+1);
    printf("Nume imagine: ");
    scanf("%s", (secventa_video+k)->nume);
    printf("Matrice:\n");
    (secventa_video+k)->matrice = citire_matrice(&dim1,&dim2);
  }

  /* Afisare matrice */
  for (k=0; k<nr_imagini; k++)
  {
    printf("\nMatricea %d este:\n", k+1);
    afisare_matrice((secventa_video+k)->matrice, dim1, dim2);
  }

  /* Calcul histograme */
  calcul_histograme(secventa_video, nr_imagini, dim1, dim2);
  /* Afisare histograme */
  for (k=0; k<nr_imagini; k++)
  {
    printf("\nHistograma pentru imaginea %s este:\n",(secventa_video+k)->nume);
    afisare_matrice((secventa_video+k)->hist, 1, 16);
  }
/* Eliberare memorie */
  eliberare_structura(secventa_video);
  printf("\n");
  return 0;
}
