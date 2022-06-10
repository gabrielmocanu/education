#include <stdio.h>
#include <math.h>

typedef struct cfr{
  int milisecunde;
  int senzor;
}cfr;

int main()
{
  int n;
  scanf("%d\n",&n);
  cfr v1[100];
  cfr v2[100];
  int index1 = 0;
  int index2 = 0;
  int miscare = 0; // 0 S-D 1 D-S
  int timp = 0;
  int viteza[100];
  int i, j;

  for(i = 0;i < n; i++ )
  {
    scanf("%d %d\n",&v1[i].milisecunde,&v1[i].senzor);
  }

  for(i = 0;i < n; i++ )
  {
    scanf("%d %d\n",&v2[i].milisecunde,&v2[i].senzor);
  }

  // Parcurgem primul vector si vedem cand apare primul 1 -> index1
  for(i = 0; i < n;i++)
  {
    if(v1[i].senzor == 1)
    {
      index1 = i;
      break;
    }
  }
  // Parcurgem al doilea vector si vedem cand apare primul 1 -> index2
  for(i = 0; i < n;i++)
  {
    if(v2[i].senzor == 1)
    {
      index2 = i;
      break;
    }
  }
  // Comparam cele doua valori si daca prima e mai mica ca trenul se misca S-D
  if(index1 < index2)
  {
    miscare = 0;
  }else
  {
    miscare = 1;
  }

  int nr = 0;
  for(i = 0; i < n; i++)
  {
    if(v1[i].senzor == 1)
      nr++;
  }

  int nr2 = 0;
  index1 = 0;
  index2 = 0;


  while(1)
  {
    while(v1[index1].senzor != 1){
      index1++;
    }

    while(v2[index2].senzor != 1){
      index2++;
    }

    if(miscare == 0)
    {
      timp = v2[index2].milisecunde - v1[index1].milisecunde;
    }else
    {
      timp = v1[index1].milisecunde - v2[index2].milisecunde;
    }


    viteza[nr2] = 7200/timp;
    nr2++;

    index1++;
    index2++;

    if(nr2 == nr)
      break;

  }

  int sum = 0;
  for(i = 0; i < nr; i++)
  {
    sum += viteza[i];
  }
  float medie = (float)sum/nr;

  int index = 0;
  int ok = 0;

  for(i = 0; i < n; i++)
  {
    if( (v1[i].senzor == 1) && (ok == 0))
    {
      index++;
      ok = 1;
    }
    if(v1[i].senzor == 0)
      ok = 0;
  }

  if(miscare == 1)
    printf("%f %d\n",medie*(-1),index);
  else
    printf("%f %d\n",medie,index);

  // Parcurgem fiecare vector in parte si ne luam 2 variabile pentru a numara cate secventa de 1 sunt in fiecare


  return 0;
}
