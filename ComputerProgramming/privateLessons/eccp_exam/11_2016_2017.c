#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char s[1000];
  gets(s);

  char v1[1000];
  char v2[1000];
  int i,j;

  for(i = 0;i <= 62; i++){
    scanf("%c,%c ",&v1[i],&v2[i]);
  }

  for(i = 0;i < strlen(s); i++){
    for(j = 0; j < 62; j++){
      if(s[i] == v1[j]){
        s[i] = v2[j];
        break;
      }
    }
  }

  printf("%s\n",s);

  return 0;
}
