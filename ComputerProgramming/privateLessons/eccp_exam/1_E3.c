#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {


  int n;
  int i;
  scanf("%d",&n);
  int v[100];

  for(i = 0;i < n;i++){
    scanf("%d",&v[i]);
  }

  int f[100] = {0};

  for(i = 0;i < n; i++){
    
    if(v[i] <= 9)
      f[0]++;
    if(v[i] > 9 && v[i] <= 99)
      f[1]++;
    if(v[i] > 99 && v[i] <= 999)
      f[2]++;
    if(v[i] > 999 && v[i] <= 9999)
      f[3]++;
    if(v[i] > 9999 && v[i] <= 99999)
      f[4]++;
    if(v[i] > 99999 && v[i] <= 999999)
      f[5]++;
    if(v[i] > 999999 && v[i] <= 9999999)
      f[6]++;
    if(v[i] > 9999999 && v[i] <= 99999999)
      f[7]++;
    if(v[i] > 99999999 && v[i] <= 999999999)
      f[8]++;
  }

  for(i = 0; i < 9; i++){
    if(f[i] != 0)
      printf("%d %d\n",i+1,f[i]);
  }

  return 0;
}
