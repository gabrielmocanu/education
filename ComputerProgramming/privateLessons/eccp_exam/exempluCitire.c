#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char x[100][100];
  char name[100];
  int i = 0;
  while(scanf ("%[^\n]%*c", name) != -1)
  {

    printf("%s\n",name);
    strcpy(x[i],name);
    i++;
  }


  while( scanf("%d",&nr) != -1)
  {
    v[i] = nr;
    i++;

  }
  return 0;
}
