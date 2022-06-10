#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  int i,j;

  scanf("%d",&n);
  int last;
  int nr;
  int final = 0;
  int zeroNr = 0;
  int v[100][100];
  int masura[100];

  for(i = 0;i < n; i++){
    j = 0;
    while(
      scanf("%d",&v[i][j]) != - 1 && getchar() != '\n')
    {
      j++;
    }
    masura[i] = j+1;
  }


  for(i = 0 ;i < n; i++){

    final = 0;
    for(j = 0; j < masura[i]; j++){
      zeroNr = 0;
    if(v[i][j] != 0){
      last = v[i][j];
      j++;
      if(j == masura[i] )
      {
        final = 1;
      }
      while(v[i][j] == 0 && j < masura[i]){
        j++;
        zeroNr++;
        if(j == masura[i] )
        {
          final = 1;
        }
      }

      if(final == 0)
      {
        if(zeroNr == 0)
          printf("%d,",last);
        else
          printf("(%d,%d),",last,zeroNr);
      }
      else
      {
        if(zeroNr == 0)
          printf("%d",last);
        else
          printf("(%d,%d)",last,zeroNr);
      }


      j--;
    }
  }
  printf("\n");
}

  return 0;
}
