#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);
  int i,j;
  int v[100];
  char sir[100];
  const char s[2] = " "; // delimitatorul
  char *token;
  int sum = 21;
  int sumFinala = 0;
  int sumVector = 0;
  int lungime = 0;

  for(i = 0;i < n; i++){


    sumVector = 0;
    scanf("%[^\n]\n",sir);
    token = strtok(sir, s);
    j = 0;

    while( token != NULL ){
       v[j] = atoi(token);
       j++;
       token = strtok(NULL, s);
    }
    lungime = j;

    for(j = 0;j < lungime; j++){
      sumVector = sumVector + v[j];
    }

    for(j = 0; j < 6; j++){
      v[j] = 0;
    }
    sumFinala = sumFinala + (sum - sumVector);
  }

  printf("%d\n",sumFinala);

  return 0;
}
