#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct agenda
{
  char nume[20];
  char prenume[20];
  char numarTelefon[10];
  char Prefix[4];
};

// Functia de cautare in agenda 
struct agenda Cauta(struct agenda a[10],int nr,char nume[20],char prenume[20])
{
  int i;
  for(i=0;i<nr;i++)
  {
    if(!strcmp(a[i].nume,nume) && !strcmp(a[i].prenume,prenume))
    {
      return a[i];
    }
  }
  printf("Nu am putut gasi niciun astfel de nume.\n");
}

int main(int argc, char const *argv[]) {

  struct agenda a[10];
  int nr;
  int i;
  printf("Introdu numarul de persoane:");
  scanf("%d",&nr);

  char nume[20],prenume[20],numarTelefon[10],Prefix[4];
  for(i=0;i<nr;i++)
  {
    printf("Introdu numele: ");
    scanf("%s",nume);
    printf("Introdu prenume: ");
    scanf("%s",prenume);

    printf("Introdu numarul de telefon: ");
    scanf("%s",numarTelefon);
    printf("Introdu prefixul: ");
    scanf("%s",Prefix);

    strcpy(a[i].nume,nume);
    strcpy(a[i].prenume,prenume);
    strcpy(a[i].numarTelefon,numarTelefon);
    strcpy(a[i].Prefix,Prefix);
  }

  char numeCautat[20],prenumeCautat[20];


  printf("Introdu numele cautat: ");
  scanf("%s",numeCautat);
  printf("Introdu prenumele cautat ");
  scanf("%s",prenumeCautat);

  cautata = Cauta(a,nr,numeCautat,prenumeCautat);

  printf("Am gasit persoana cu nr telefon %s si prefixul %s\n",cautata.numarTelefon,cautata.Prefix);


  return 0;
}
