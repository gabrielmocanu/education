#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n,k;
  int i;
  int v[100];
  int j;
  int ok = 1;
  int min = 999;

  scanf("%d %d",&n,&k);

  for(i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }

  for(i = 0; i < n ; i++){

    ok = 1;
    for(j = 2; j < v[i]; j++){ // de retinut pentru a afla daca un numar e prim sau nu
      if(v[i] % j == 0){
        ok = 0;
      }
    }

    if(ok == 1){
      if(v[i] < min && v[i] >= k){
        min = v[i];
      }
    }

  }

  if(min == 999)
    printf("-1\n");
  else
    printf("%d\n",min);

  return 0;
}
