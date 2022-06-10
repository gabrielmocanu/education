#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);

  int i;
  float v[100];
  float medie = 0;
  float dispersie = 0;
  int nr = 0;
  float medieVal = 0;

  for(i = 0 ; i < n; i++){
    scanf("%f",&v[i]);
  }

  for(i = 0 ; i < n; i++){
    medie = medie + v[i];
  }

  medie = (float)medie/n;

  for(i = 0;i < n ; i++){
    dispersie = dispersie + pow(medie - v[i],2);
  }

  dispersie = (float)dispersie/n;
  dispersie = sqrt(dispersie);

  for(i = 0;i < n; i++){
    if(v[i] >= medie - dispersie && v[i] <= medie + dispersie)   // DIFERENTA !!! (float)nr/n (float)(nr/n)
      nr++;
  }

  medieVal = ((float)nr/n)*100.0; // 100 -> int 100.0 -> float
  printf("%f\n",medieVal);

  return 0;
}
