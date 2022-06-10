#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {


  char stea[100] = "******************************************************************************";
  char sir[200];
  int n;
  char cuvinte[100][100];
  int i;
  char *s;

  scanf("%[^\n]",sir);
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%s",cuvinte[i]);
  }

  s = sir;

  for(i = 0; i < n; i++){

    while(strstr(sir,cuvinte[i]) != NULL){
      s = strstr(sir,cuvinte[i]);
      strncpy(s,stea,strlen(cuvinte[i]));
    }  
  }

  printf("%s\n",sir);

  return 0;
}
