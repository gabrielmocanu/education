#include <stdio.h>
#include <stdlib.h>

int *alocare(int n)
{
  int *p;

  p = (int *)malloc(n*sizeof(int));

  return p;

}

int determinare_maxim(int *v, int nr)
{
  int i;
  int max = -9999;

  for(i=0;i<nr;i++)
  {
    if(max < *(v+i))
    {
      max = *(v+i);
    }
  }

  return max;
}

int main(int argc, char const *argv[]) {

  int i;
  int nr;
  int *v;

  printf("Introdu numarul de numere: ");
  scanf("%d",&nr);

  v = alocare(nr);

  for(i=0;i<nr;i++)
  {
    scanf("%d",(v+i));
  }

  int max = determinare_maxim(v,nr);
  printf("Maximul vectorului este: %d\n",max);


  return 0;
}
