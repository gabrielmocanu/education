#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n1;
  scanf("%d",&n1);
  int v1[100];
  int i;
  for(i = 0;i < n1; i++){
    scanf("%d",&v1[i]);
  }

  int n2;
  scanf("%d",&n2);
  int v2[100];
  for(i = 0;i < n2; i++){
    scanf("%d",&v2[i]);
  }

  int v3[100];
  for(i = 0; i < n1; i++){
    v3[i] = v1[i];
  }

  for(i = 0; i < n2; i++){
    v3[n1+i] = v2[i];
  }

  int ok = 1;
  int aux;
  while(ok){
    ok = 0;
    for(i = 0; i < n1+n2-1; i++){
      if(v3[i] > v3[i+1]){
        aux = v3[i];
        v3[i] = v3[i+1];
        v3[i+1] = aux;
        ok = 1;
      }
    }
  }

  int sum = 0;
  for(i = 5; i < n1+n2; i++){
    sum = sum + v3[i];
  }
  float medie = (float)sum/(n1+n2-5);

  printf("%.2f\n",medie);

  return 0;
}
