#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);

  int i = 1;
  int v[100];
  int vizitat[100] = {0};

  while(1){
    int res = scanf("%d ",&v[i]);
    if(res != 1)
      break;
    i++;
  }

  int nr = i-1;

  for(i = 1;i <= nr; i++){
    vizitat[v[i]] = 1;
  }

  int sum = 0;
  for(i = 1; i <= n; i++){
    if(vizitat[i] == 0){
      sum = sum + i;
    }
  }
  printf("%d\n",sum);

  return 0;
}
