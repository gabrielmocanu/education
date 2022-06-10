#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Concert{
  char nume[100];
  int zi,luna,pret,distanta;
}Concert;


int main(int argc, char const *argv[]) {

  int n;
  int i;
  scanf("%d",&n);

  float Pb,Cm;
  scanf("%f %f",&Pb,&Cm);

  int Zi,Zf,Li,Lf;
  scanf("%d %d %d %d",&Zi,&Li,&Zf,&Lf);

  Concert concerte[100];
  for(i = 0; i < n; i++){
    scanf("%s %d %d %d %d",concerte[i].nume,&concerte[i].zi,&concerte[i].luna,&concerte[i].pret,&concerte[i].distanta);
  }

  float pretMin = 9999;
  int indexMin;
  for(i = 0; i < n; i++){
    if(concerte[i].zi < Zi && concerte[i].luna < Li || concerte[i].zi > Zf && concerte[i].luna > Lf){ // nu e bine conditia aici(Rezolvam impreuna)
      float pret = concerte[i].pret + (float)(2*concerte[i].distanta*Pb*Cm)/3;
      printf("%f\n",pret);
      if(pret < pretMin){
        pretMin = pret;
        indexMin = i;
      }
    }
  }


  printf("%s %f\n",concerte[indexMin].nume,pretMin);

  return 0;
}
