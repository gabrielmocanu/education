#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n,k;
  int v[1000];
  int i,j;
  scanf("%d %d",&n,&k);
  int cifre[1000][1000];
  int v_cifre[100];


  for(i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }

  int c = 0;
  int l;
  int nr = 0;
  int max = 0;
  int aux = 0;
  int swap = 0;
  for(i = 0; i < n; i++){

    aux = 0;
    c = 0;
    nr = 0;
    while(v[i] != 0){ // transformare  vector cifre
      cifre[i][c] = v[i] % 10;
      v[i] = v[i] / 10;
      c++;
    }
    v_cifre[i] = c;

    // Intoarcere

    for(j = 0 ; j < c/2 ;j++)
    {
        swap = cifre[i][c-j-1];
        cifre[i][c-j-1] = cifre[i][j];
        cifre[i][j] = swap;
    }


    for(l = 0; l < k; l++){ // k transformari

      for(j = 0; j < v_cifre[i]-1; j++){
        cifre[i][j] = abs(cifre[i][j] - cifre[i][j+1]);
      }
      cifre[i][v_cifre[i]-1] = 0;
      v_cifre[i] = v_cifre[i] - 1;

      for(j = aux; j < v_cifre[i]; j++)
      {
        printf("%d",cifre[i][j]);
      }
      printf("\n");

      for(j = aux; j < v_cifre[i]; j++)
      {
        if(cifre[i][j] == 0)
        {
          aux++;
        }
        else
        {
          break;
        }
      }


      for(j = 0; j < v_cifre[i]; j++){
        nr += pow(10,j) * cifre[i][v_cifre[i]-j-1];
      }

      printf("nr = %d\n",nr);

    }

    if(nr > max){
      max = nr;
    }

  }

  printf("%d\n",max);

  return 0;
}
