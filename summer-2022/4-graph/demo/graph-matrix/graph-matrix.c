#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int n, m;
  int **matr;
} Graf;

void initG(Graf *g, int n){

  int i;
  g->n = n;
  g->m = 0;

  g->matr = (int **) malloc((n+1)*sizeof(int*));
  for(int i = 1; i <= n; i++)
    g->matr[i] = (int *)calloc( (n+1), sizeof(int));
}

void addArc(Graf *g, int x, int y, int cost){
  g->matr[x][y] = cost;
  g->matr[y][x] = cost;
  g->m++;
}

int arc(Graf g, int x, int y){
  return g.matr[x][y];
}

void delArc(Graf *g, int x, int y){
  g->matr[x][y] = 0; 
  g->matr[y][x] = 0; 
  g->m--;
}

void delNod(Graf *g, int x){

  int i;
  for(i = 1; i <= g -> n; i++){
    if(arc(*g, x, i) != 0)
      delArc(g, x, i);
  }
  g->n--;
}

void printGraph(Graf g){
  for(int i = 1; i <= g.n; i++){
    for(int j = 1; j <= g.n; j++){
      printf("%d ",g.matr[i][j]);
    }
    printf("\n");
  }
}

int main(){

  Graf g;
  initG(&g, 10);

  printGraph(g);

  printf("\n");
  addArc(&g, 1, 2, 3);
  addArc(&g, 4, 5, 6);
  addArc(&g, 3, 2, 9);
  addArc(&g, 8, 5, 12);
  addArc(&g, 3, 7, 15);
  printGraph(g);

  printf("\n");
  delArc(&g, 3, 2);
  printGraph(g);

  printf("\n");
  delNod(&g, 10);
  printGraph(g);

  return 0;
}
