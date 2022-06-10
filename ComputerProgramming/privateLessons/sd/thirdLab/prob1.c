#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produs
{
  int id;
  char denumire[30];
  double pret;
};

struct Produs creare_produs()
{
  struct Produs aux;
  printf("Introdu id-ul produsului:");
  scanf("%d",&aux.id);
  printf("Introdu denumirea produsului:");
  scanf("%s",aux.denumire);
  printf("Introdu pretul produsului:");
  scanf("%lf",&aux.pret);

  return aux;
}

struct Produs afla_pret_maxim(struct Produs lista[10])
{
  struct Produs pret_maxim;
  int i;

  for(i=0;i<10;i++)
  {
    if(lista[i].pret > pret_maxim.pret)
    {
      pret_maxim = lista[i];
    }
  }
  return pret_maxim;

}

int main(int argc, char const *argv[]) {

  struct Produs a,b;

  a=creare_produs();
  b=creare_produs();

  if(a.pret > b.pret)
  {
    printf("Pretul %s este mai mare ca %s\n",a.denumire,b.denumire);
  }
  else
  {
    printf("Pretul %s este mai mare ca %s\n",b.denumire,a.denumire);
  }


  struct Produs lista[10];

  lista[0] = creare_produs();
  lista[1] = creare_produs();
  lista[2] = creare_produs();

  struct Produs pret_maxim;

  pret_maxim = afla_pret_maxim(lista);

  printf("Pretul maxim este al produsului: %s\n",pret_maxim.denumire);

  return 0;
}
