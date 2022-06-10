#include <stdio.h>
#include <math.h>

typedef struct Lot{
  int nr;
  int tranzistoare;
  int rezistenta;
  int condensatoare;
}Lot;

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);
  char c;

  int i,j;
  Lot l[100];
  for(i = 0 ;i < n ;i++){
    scanf("%d\n",&l[i].nr);
    for(j = 0; j < l[i].nr; j++){
      scanf("%c ",&c);
      if(c == 'C')
        l[i].condensatoare++;
      if(c == 'T')
        l[i].tranzistoare++;
      if(c == 'R')
        l[i].rezistenta++;
    }
  }

  int utile = 0;

  for(i = 0 ;i < n;i++){
    if(l[i].condensatoare >= l[i].tranzistoare && l[i].rezistenta >= l[i].condensatoare && l[i].condensatoare >= 1 && l[i].rezistenta >= 1 && l[i].tranzistoare >= 1)
      utile++;
  }

  int max = 0;
  for(i = 0; i < n; i++){
    if(max < l[i].nr){
      max = l[i].nr;
    }
  }

  printf("%d %d\n",utile,max);


  return 0;
}
