#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);
  int i;
  char figura[100];
  float latura;
  float arie;
  float arieMax = 0;
  char figuraMax[100];
  float latura1,latura2;
  float raza;

  float razaMax;
  float latura1Max,latura2Max;
  float laturaMax;

  for(i = 0;i < n;i++){
    scanf("%s",figura);

    if(!strcmp(figura,"patrat")){
      scanf("%f\n",&latura);
      arie = latura * latura;
    }


    if(!strcmp(figura,"dreptunghi")){
      scanf("%f %f\n",&latura1,&latura2);
      arie = latura1 * latura2;
    }


    if(!strcmp(figura,"cerc")){
      scanf("%f\n",&raza);
      arie = 3.1415 * raza * raza;
    }

    if(arie > arieMax){
      arieMax = arie;
      strcpy(figuraMax,figura);
      if(!strcmp(figura,"cerc"))
        razaMax = raza;
      if(!strcmp(figura,"patrat"))
        laturaMax = latura;
      if(!strcmp(figura,"dreptunghi"))
      {
        latura1Max = latura1;
        latura2Max = latura2;
      }
    }


  }

  if(!(strcmp(figuraMax,"cerc"))){
    printf("cerc ");
    printf("%f\n",razaMax);
  }
  if(!(strcmp(figuraMax,"patrat"))){
    printf("patrat ");
    printf("%f\n",laturaMax);
  }
  if(!(strcmp(figuraMax,"dreptunghi"))){
    printf("dreptunghi ");
    printf("%f\n",latura1Max);
    printf("%f\n",latura2Max);
  }


  return 0;
}
