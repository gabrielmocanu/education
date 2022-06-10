#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elev{

  char nume[20];
  char prenume[20];
  double medie;
};

double cauta(char nume[20],char prenume[20], struct Elev a[20], int nr)
{
  int i;

  for(i=0;i<nr;i++)
  {
    if(!strcmp(nume,a[i].nume) && !strcmp(prenume,a[i].prenume))
    {
      return a[i].medie;
    }
  }
}

double medie_generala(struct Elev a[20], int nr)
{
  int i;
  double sum;

  for(i=0;i<nr;i++)
  {
    sum = sum + a[i].medie;
  }

  return sum/nr;
}
int main(int argc, char const *argv[]) {


  struct Elev a[20];
  int nr;
  printf("Introdu nr de elevi: ");
  scanf("%d",&nr);

  int i;
  for(i=0;i<nr;i++)
  {
    printf("Introdu numele elevului: ");
    scanf("%s",a[i].nume);
    printf("Introdu prenumele elevului: ");
    scanf("%s",a[i].prenume);
    printf("Introdu media elevului: ");
    scanf("%lf",&a[i].medie);
  }

  char nume[20],prenume[20];

  printf("Introdu numele cautat: ");
  scanf("%s",nume);
  printf("Introdu prenumele cautat: ");
  scanf("%s",prenume);

  printf("Media elevului cautat este %lf \n",cauta(nume,prenume,a,nr));

  printf("Media generala a tuturo copiilor este %lf \n",medie_generala(a,nr));



  return 0;
}
