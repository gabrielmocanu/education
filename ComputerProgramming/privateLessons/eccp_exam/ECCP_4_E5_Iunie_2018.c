#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);

  int i;
  int v[100];
  for(i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }

  float medie;
  float sum = 0;
  float deviatie;
  float raport;
  int ok = 1;
  int vizitat[100] = {0};
  int index;
  float difMax = 0;
  float difCur = 0;
  int nr = 0;
  int numara = 0;

  while(ok){


    sum  = 0;
    for(i = 0;i < n; i++){
      if(vizitat[i] == 0){
        sum = sum + v[i];
      }
    }

    medie = (float)sum/(n-nr);
    sum = 0;

    for(i = 0; i < n; i++){
      if(vizitat[i] == 0)
        sum = sum + pow(v[i]-medie,2);
    }

    deviatie = sqrt(sum/(n-nr));

    raport = (float)deviatie/medie;

//    printf("medie = %f deviatie = %f\n",medie,deviatie);

    if(raport <= 0.1 || numara > 100 ){
      ok = 0;
    }else{

      difCur = 0;
      difMax = 0;

      for(i = 0; i < n; i++){
        if(vizitat[i] == 0){
          difCur = fabsf(v[i] - medie);
          printf("difCur = %f\n",difCur);
          if(difCur > difMax){
            difMax = difCur;
            index = i;
          }
        }
      }

      nr++;
      vizitat[index] = 1;
    }
    numara++;
    // printf("index = %d\n",index);
    printf("medie = %f deviatie = %f raport = %f numar_eliminat = %d\n",medie, deviatie, raport, v[index]);
  }

  printf("%d\n",nr);

  return 0;
}
