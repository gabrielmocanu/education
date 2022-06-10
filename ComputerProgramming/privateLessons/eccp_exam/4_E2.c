#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);

  int i;
  int m[100][100];
  int j = 0;
  char sir[100];
  const char s[2] = " "; // delimitatorul
  char *token;


  for(i = 0;i < n; i++){
    scanf("%[^\n]\n",sir);
    token = strtok(sir, s);
    j = 0;

    while( token != NULL ){
       m[i][j] = atoi(token);
       j++;
       token = strtok(NULL, s);
    }
  }

  int len = j;
  int aux;

  for(i = 0; i < n; i++){ // interschimbare

    for(j = 0; j < len/2; j+=2){
      aux = m[i][j];
      m[i][j] = m[i][j+1];
      m[i][j+1] = aux;
    }

  }

  for(i = 0; i < n; i++){

    for(j = 1; j < len; j++){
      m[i][j] = m[i][j] % 2;
    }

  }

  for(i = 0; i < n; i++){
    for(j = 0; j < len; j++){
      printf("%d ",m[i][j]);
    }
    printf("\n");
  }

  int sum = 0;
  int sumMax = 0;

  for(i = 0; i < n; i++){
    sum = 0;
    for(j = 0; j < len; j++){
      sum += m[i][j];

    }
    if(sumMax < sum)
      sumMax = sum;
  }

  printf("%d\n",sumMax);
  return 0;
}
