#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);
  int i;
  int v[100];

  for(i = 0;i < n; i++){
    scanf("%d",&v[i]);
  }

  int lungime = 0;
  int index = 0;
  int lungimeMax = 0;

  for(i = 0;i < n-1; i++){
    if((v[i] >= 0 && v[i+1] < 0) || (v[i] < 0 && v[i+1] >= 0)){
      lungime++;
    }else{
      if(lungime >= lungimeMax){
        index = i-lungime;
        lungimeMax = lungime;
      }
      lungime = 0;
    }
  }

  printf("%d\n",lungimeMax+1);
  for(i = index; i <index+lungimeMax+1; i++ ){
    printf("%d ",v[i]);
  }
  printf("\n");

  int nrNeg = 0;
  int nrPoz = 0;
  for(i = 0; i < n; i++){
    if(v[i] < 0)
      nrNeg++;
    else
      nrPoz++;
  }

  float nrNegP = (float)nrNeg/n*100;
  float nrPozP = (float)nrPoz/n*100;

  printf("+:%.2f%% -:%.2f%%\n",nrPozP,nrNegP);

  return 0;
}
