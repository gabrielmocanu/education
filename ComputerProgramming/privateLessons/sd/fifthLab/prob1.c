/* La nr 1- vector de structuri, fiecare structura sa contina un sir de caractere alocat dinamic-numele unui
student, un float-media, si un int- dimensiunea vectorului. Plus o functie de citire si o functie sa afiseze
ce elevi au media peste 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  char *nume;
  float media;
  int dimensiune;
};

struct student *citire(struct student *a, int nr)
{
  int i;
  for(i=0;i<nr;i++)
  {
    printf("Introdu numele studentului:");
    a[i].nume = (char *)malloc(10*sizeof(char));
    scanf("%s",a[i].nume);

    printf("Introdu media elevului:");
    scanf("%f",&a[i].media);

    a[i].dimensiune = nr;
  }
  return a;
}

void AfisareMedie(struct student *a, int nr)
{
  int i;
  for(i=0;i<nr;i++)
  {
    if(a[i].media > 5)
    {
      printf("%s ",a[i].nume);
    }
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  struct student *lista;
  int nr;

  printf("Introdu numarul de studenti: ");
  scanf("%d",&nr);
  lista = (struct student *)malloc(nr*sizeof(struct student));

  lista = citire(lista,nr);

  AfisareMedie(lista,nr);

  return 0;
}
