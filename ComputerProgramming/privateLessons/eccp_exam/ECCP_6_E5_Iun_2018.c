#include <stdio.h>


int main(int argc, char const *argv[]) {

  int v[6];
  int i;

  for(i = 0 ; i < 6 ; i++){
    scanf("%d",&v[i]);
  }

  int n;
  scanf("%d",&n);

  int miscare;
  int rotatii;
  int pozitie = 0;

  for(i = 0; i < n; i++){
    scanf("%d",&miscare);
    scanf("%d",&rotatii);

    if(miscare == 1)
    {
      pozitie += rotatii;
    }else{
      pozitie -= rotatii;
    }

  }

  printf("%d\n",v[rotatii%6]);

  return 0;
}
