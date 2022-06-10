#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct elev
{
  char nume[100];
  float nota1,nota2,nota3,nota4;
}Elev;



int main()
{

  Elev elevi[100];
  char sir[100];
  char *token;
  int i = 0;

  // scanf("%[^\n]",&v[i][j]);
  // getchar();

  scanf("%[^\n]", sir); 
  getchar();
    strcpy(elevi[i].nume,strtok(sir,","));

    elevi[i].nota1 = atof(strtok(sir,","));
    elevi[i].nota2 = atof(strtok(sir,","));
    elevi[i].nota3 = atof(strtok(sir,","));
    elevi[i].nota4 = atof(strtok(sir,","));

    i++;



  // Cum citesti fara spatii o linie ?
  // Cum convertesti sirul intr-un numar float(cu virgula)

  printf("%s %f %f %f %f\n",elevi[0].nume, elevi[0].nota1,elevi[0].nota2,elevi[0].nota3,elevi[0].nota4 );

}
