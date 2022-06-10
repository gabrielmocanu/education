#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);

  int i,j,k;
  int v[100];
  for(i = 0;i < n; i++){
    scanf("%d",&v[i]);
  }

  int arie = 0;

  for(i = 0; i < n; i++){
    for(j = i+1; j < n; j++){
      for(k = j+1; k < n; k++){
        if( pow(v[i],2)+pow(v[j],2) == pow(v[k],2))
          arie = arie + v[i]*v[j]/2;

        if(pow(v[k],2)+pow(v[i],2) == pow(v[j],2))
          arie = arie + v[k]*v[i]/2;

        if(pow(v[j],2)+pow(v[k],2) == pow(v[i],2))
          arie = arie + v[j]*v[k]/2;

      }
    }
  }


  printf("%d\n",arie);

  return 0;
}
