#include <math.h>
#include <stdio.h>
#include <math.h>

typedef struct Copil{
  char nume[100];
  int x1,y1,x2,y2;
  int arie;
}Copil;

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);
  Copil c[100];
  int i;

  for(i  = 0; i < n; i++){
    scanf("%s %d %d %d %d\n",c[i].nume,&c[i].x1,&c[i].y1,&c[i].x2,&c[i].y2);
    c[i].arie = abs(c[i].x1-c[i].x2)*abs(c[i].y1-c[i].y2);
  }

  int index;
  int arieMax = 0;

  for(i = 0; i < n; i++){
    if(arieMax < c[i].arie){
      arieMax = c[i].arie;
      index = i;
    }
  }

  printf("%s %d %d %d %d %d\n",c[index].nume,c[index].x1,c[index].y1,c[index].x2,c[index].y2,c[index].arie);

  return 0;
}
