#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int k,m;
  int perm = 1;
  int ok = 1;
  int i;
  scanf("%d %d",&k,&m);
  int n = k;


  while(ok){
    perm = 1;
    for(i = n-k+1; i <= n;i++){
      perm = perm * i;
    }
    if( perm > m){
      break;
    }else{
      n++;
    }
  }

  if(n-1 == k-1)
    printf("0\n");
  else
    printf("%d\n",n-1);

  return 0;
}
