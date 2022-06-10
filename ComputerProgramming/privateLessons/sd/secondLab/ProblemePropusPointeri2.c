#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *citire_matrice(int *dim1, int *dim2)
{
  int i, j;
  int *M;
  //citire dimensiuni dorite, dim1 si dim2 sunt deja adrese
  printf("Introduceti numarul de linii: ");
  scanf("%d", dim1);
  printf("Introduceti numarul de coloane: ");
  scanf("%d", dim2);
  //alocare memorie (*dim1) x (*dim2) x 32 biti (int)
  M = (int *)malloc((*dim1)*(*dim2)*sizeof(int));
  if (!M)
  {
    printf("\nMemoria nu a putut fi alocata!");
  }

  printf("\nCitire valori matrice:\n");
  for (i=0; i<*dim1; i++)
    for (j=0; j<*dim2; j++)
    {
      printf("M[%d][%d] = ",i+1,j+1);
      //stocare la adresele M+*dim2*i+j <-> &M[i][j]
      scanf("%d",M+*dim2*i+j);
    }
    // returnare adresa matrice
    return M;
}

void afisare_matrice(int *M, int dim1, int dim2)
{
  int i,j;
  for (i=0; i<dim1; i++)
  {
    for (j=0; j<dim2; j++)
    //continutul de la adresa M+dim2*i+j <-> M[i][j]
    printf("%8d",*(M+dim2*i+j));
    printf("\n");
  }
}

// functia de schimbare de linii folosindu-ne de interschimbare
int *schimbare_linii(int *M, int dim1,int dim2,int lin1, int lin2)
{
  int i;
  int vector_auxiliar[10];
  for(i=0;i<dim2;i++)
  {
    vector_auxiliar[i] = *(M+dim2*(lin1-1)+i); // aux = a
    *(M+dim2*(lin1-1)+i) = *(M+dim2*(lin2-1)+i); // a = b
    *(M+dim2*(lin2-1)+i) = vector_auxiliar[i]; // b = aux
  }

  return M;
}

int main(int argc, char const *argv[]) {

  int dim;
  int *M;

  M = citire_matrice(&dim,&dim);
  afisare_matrice(M,dim,dim);
  printf("\n");
  M = schimbare_linii(M,dim,dim,2,3);
  afisare_matrice(M,dim,dim);

  return 0;
}
