#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  char sir[100];
  int n;
  int i;
  int v[100];
  scanf("%[^\n]s",sir); // sau cu gets gets(sir);
  scanf("%d",&n);
  for(i = 0;i < n; i++){
    scanf("%d",&v[i]);
  }

  int j = 0;
  for(i = 0;i < strlen(sir); i++){

    if(sir[i] >= 65 && sir[i] <= 90){
      sir[i] = sir[i] + v[j%n];

      if(sir[i] > 90)
        sir[i] = 65 + sir[i] % 90 - 1; // 'A' == 65

      if(sir[i] >= 122) // 'z' == 122
        sir[i] = 65 + sir[i] % 122 - 1;

      j++;
    }

    if(sir[i] >= 97 && sir[i] <= 122){
      sir[i] = sir[i] + v[j%n];

      if(sir[i] > 122)
        sir[i] = 65 + sir[i] % 122 - 1;

      j++;
    }

  }

  printf("%s\n",sir);


  return 0;
}
