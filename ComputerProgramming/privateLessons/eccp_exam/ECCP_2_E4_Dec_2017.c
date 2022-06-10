#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);
  float v[100];
  int i;

  for(i = 0; i < n; i++){
    scanf("%f",&v[i]);
  }

  int nr = 0; // cate elemente sunt intr-o subsecventa
  int nrMax = 0; // cate elemente sunt in subsecventa maxima
  int index = 0; // indexul subsecventei actuale
  int indexMax = -1; // indexul subsecventei maxime
  float sumCur = 0; // suma subsecventei actuale
  float sumMax = 0; // suma subsecventei maxime

  for(i = 0; i < n;i++){

    if(v[i] > 0) // intra pe numere pozitive
    {
      if(nr == 0) // retine doar indexul primului element
        index = i;

      nr++;
      sumCur += v[i];
    }else{ // cand gaseste un numar negativ
      nr = 0;
      sumCur = 0;
    }

    if(nr > nrMax){
      nrMax = nr;
      indexMax = index;
      sumMax = sumCur;
    }else if(nr == nrMax){
      if(sumCur > sumMax){
        indexMax = index;
        sumMax = sumCur;
      }
    }
  }

  printf("%d\n%d\n",indexMax,nrMax);


  return 0;
}
