#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);

  int i,j;
  float v[100] = {0};
  float v2[100] = {0};
  float medie = 0;
  float sum =0;

  for(i = 0;i < n; i++){
    scanf("%f",&v[i]);
  }

  int w;
  scanf("%d",&w);
  int grupe;

  if(n%w == 0){
    grupe = n/w - 1;
  }else{
    grupe = n/w;
  }


  int nrSemn = 0;
  int nrLastGroup;
  for(i = 0; i <= grupe; i++){
    sum = 0;
    medie = 0;

    if(i == grupe){
      if(n%w == 0)
      {
        nrLastGroup = w;
      }else
      {
        nrLastGroup = n - (grupe-1)*w;
      }

      for(j = 0; j < nrLastGroup; j++){
        sum = sum + v[i*w+j];
      }
      medie = (float)sum/w;
      for(j = 0 ; j < nrLastGroup; j++){
        v2[i*w+j] = v[i*w+j] - medie;
      }

    }else{


    for(j = 0; j < w; j++){
      sum = sum + v[i*w+j];
    }
    medie = (float)sum/w;
    for(j = 0 ; j < w; j++){
      v2[i*w+j] = v[i*w+j] - medie;
    }
  
  }
}

for(i = 0; i <= grupe; i++){

  nrSemn = 0;
  if(i == grupe){
    for(j = 0;j < nrLastGroup-1; j++){
      if(v2[i*w+j] * v2[i*w+j+1] < 0)
        nrSemn++;
    }

  }else{
    for(j = 0;j < w-1; j++){
      if(v2[i*w+j] * v2[i*w+j+1] < 0){
        nrSemn++;
      }
    }

  }
  printf("%d\n",nrSemn);

}

  return 0;
}
