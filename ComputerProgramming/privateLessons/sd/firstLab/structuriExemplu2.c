#include <stdio.h>
#include <stdlib.h>

typedef struct punct{

  int x;
  int *y;
}punct;

int main(int argc, char const *argv[]) {

  punct *p = (punct *)malloc(sizeof(punct));
  int i;

  p->y = (int *)malloc(10*sizeof(int));

  p->x = 10;
  
  (*p).x = 15;



  printf("Valoarea lui x din structura este %d\n",p->x);
  printf("Vectorul y este = ");
  for(i=0;i<10;i++)
  {
    p->y[i] = i;
    printf("%d ",p->y[i]);
  }

  printf("\n");
  return 0;
}
