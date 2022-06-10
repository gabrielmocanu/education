// Sortare - Bubble Sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct masina
{
  char *nume;
  float pret;
};

struct masina *Citire(struct masina *v, int nr)
{
  int i;

  for(i=0;i<nr;i++)
  {
    printf("Introdu numele masinii: ");
    v[i].nume = (char *)malloc(10*sizeof(char));
    scanf("%s",v[i].nume);

    printf("Introdu pretul masinii: ");
    scanf("%f",&v[i].pret);
  }

  return v;
}

struct masina *Ordonare(struct masina *v, int nr)
{
  struct masina m;
  m.nume = (char *)malloc(10*sizeof(char));
  int i,j;
  for(i=0;i<nr;i++)
  {
    for(j=0;j<nr-i-1;j++)
    {
      if(v[j].pret > v[j+1].pret)
      {
        m.pret = v[j].pret;
        v[j].pret = v[j+1].pret;
        v[j+1].pret = m.pret;

        strcpy(m.nume,v[j].nume);
        strcpy(v[j].nume,v[j+1].nume);
        strcpy(v[j+1].nume,m.nume);

      }
    }
  }

  return v;
}

void Afisare(struct masina *v,int nr)
{
  int i;
  for(i=0;i<nr;i++)
  {
    printf("Nume = %s Pret = %f\n",v[i].nume,v[i].pret);
  }

}

int main(int argc, char const *argv[]) {

  int nr;
  printf("Introdu numarul de masini: ");
  scanf("%d",&nr);

  struct masina *v;
  v = (struct masina *)malloc(nr*sizeof(struct masina));

  v = Citire(v,nr);

  v = Ordonare(v,nr);

  Afisare(v,nr);


  return 0;
}
