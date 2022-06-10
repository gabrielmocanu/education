#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);
  int i;
  float v[100];
  float prag;

  for(i = 0; i < n; i++){
    scanf("%f",&v[i]);
  }
  scanf("%f",&prag);

  for(i = 0;i < n; i++){
    if(v[i]>= prag)
      v[i] = 1;
    else
      v[i] = 0;
  }

  int nr = 0;
  int ok = 0; // fie sunt pe secventa de 0 fie sunt pe secventa de 1

  for(i = 0;i < n; i++){

    // la inceput ok imi zice pe ce secventa sunt
    if(v[i] == 1 && ok == 0){ // verific
      nr++;
      ok = 1;
    }

    if(v[i] == 0){
      ok = 0;
    }

  }

  printf("%d\n",nr);

  return 0;
}
