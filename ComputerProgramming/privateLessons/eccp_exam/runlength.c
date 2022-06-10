#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  char v[100];
  int i;
  int nr[100] = {0};

  scanf("%d\n",&n);
  for(i = 0; i < n; i++){
    scanf("%c",&v[i]);
  }

  int aux = 0;
  int max = 0;

  for(i = 0;i < n; i++){
    if(v[i] == '1'){
      aux = 0;
      while(v[i] == '1'){
        aux++;
        i++;
      }
      nr[aux]++;
    }
    if(max < aux){
      max = aux;
    }
  }

  for(i = 1;i <= max;i++){
    printf("%d ",nr[i]);
  }
  printf("\n");

  int ok = 1;
  for(i = 1; i <= max; i++){
    if(nr[i] < nr[i+1]){
      ok = 0;
      break;
    }
  }

  printf("%d\n",ok);

  return 0;
}
