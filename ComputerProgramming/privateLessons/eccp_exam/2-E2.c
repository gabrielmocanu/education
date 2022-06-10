#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);
  int i,j;

  char rand[100];
  const char s[2] = ",";
  char *token;
  int a,b;
  int nrVirgule = 0;
  int count = 0;

  for(i = 0; i <n; i++){
    scanf("%s\n",rand);

    count = 0; //
    nrVirgule = 0;
    for(j = 0;j < strlen(rand); j++){
      if(rand[j] == ','){
        nrVirgule++;
      }
    }

    token = strtok(rand, s);
    count++; // numara cate numere delimitate de virgula sunt
    while(token != NULL){
      if(strlen(token) == 1){
        if(count-1 == nrVirgule)
          printf("%s",token);
        else
          printf("%s,",token);
      }else{
        a = atoi(token+1);
        token = strtok(NULL, s);
        count++;
        b = atoi(token);
        printf("%d,",a);
        if(count-1 == nrVirgule){
          for(j = 0; j < b-1; j++ )
          {
            printf("0,");
          }
          printf("0");
        }else{
          for(j = 0; j < b; j++ )
          {
            printf("0,");
          }
        }
      }
      token = strtok(NULL, s);
      count++;
    }
    printf("\n");
  }

  return 0;
}
