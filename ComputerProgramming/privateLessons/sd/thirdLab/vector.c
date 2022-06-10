#include <stdio.h>
#include <stdlib.h>

int prim(int a)
{
  int i;
  if(a == 1 || a == 0)
    return 0;


  for(i=2;i<=a/2;i++)
  {
    if(a%i == 0)
      return 0;
  }
  return 1;
}

int main(int argc, char const *argv[]) {

  int *v;
  int modul;
  int n,i;

  printf("Introdu numarul de numere: ");
  scanf("%d",&n);

  v = (int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
    scanf("%d",v+i);  // &v[i] <-> (v+i)
  }

  for(i=0;i<n;i++)
  {
    modul = abs(*(v+i));
    if(prim(modul))
    {
      printf("%d ",*(v+i));
    }
  }



  return 0;
}
