#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {


  int n;
  int v[100];
  int i;

  scanf("%d",&n);
  for(i = 0; i < n ; i++){
    scanf("%d",&v[i]);
  }

  int zero[100];
  int nrZeroMax = 0;
  int nrZero = 0;

  int nrCurent = 0;
  int nrBiti = 0;

  for(i = 0 ; i < n; i++){

    nrCurent = v[i];
    nrZero = 0;
    nrBiti = 0;
    while(nrCurent != 0){
      if(nrCurent % 2 == 0){
        nrZero++;
      }
      nrCurent = nrCurent / 2;
      nrBiti++;
    }
    
    nrZero = nrZero + 8 - nrBiti;
    zero[i] = nrZero;
    if(nrZeroMax < nrZero){
      nrZeroMax = nrZero;
    }
  }

  for(i = 0 ;i < n ; i++){
    if(zero[i] == nrZeroMax){
      printf("%d\n",v[i]);
    }
  }

  return 0;
}
