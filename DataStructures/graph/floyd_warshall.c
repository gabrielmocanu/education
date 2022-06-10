#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Edge {
  int src;
  int dest;
  int cost;
} Edge;


typedef struct {
  int n, m;
  int **matr;
} Graf;

void initG(Graf *g, int n){

  int i;
  g->n = n;
  g->m = 0;

  g->matr = (int **) malloc((n+1)*sizeof(int*));
  for(int i = 0; i < n; i++)
    g->matr[i] = (int *)calloc( (n+1), sizeof(int));
}

void addArc(Graf *g, int x, int y, int val){

  g->matr[x][y] = val;
  g->matr[y][x] = val;
  g->m++;
}

int arc(Graf g, int x, int y){
  return g.matr[x][y];
}

void delArc(Graf *g, int x, int y){
  g->matr[x][y] = 0;
  g->m--;
}

void delNod(Graf *g, int x){

  int i;
  for(i = 0; i < g -> n; i++){
    delArc(g, x, i);
    delArc(g, i, x);
  }
}

void printGraph(Graf g){
  for(int i = 0; i < g.n; i++){
    for(int j = 0; j < g.n; j++){
      printf(" %d ",g.matr[i][j]);
    }
    printf("\n");
  }
}


int **floyd_warshall(Graf g){

  int i,j,k;

  // Alocam memorie
  int **dist = malloc(g.n*sizeof(int *));
  for(i = 0; i < g.n; i++)
    dist[i] = malloc(g.n*sizeof(int));

  // Copiem
  for(i = 0; i < g.n; i++)
    for(j = 0; j < g.n; j++)
      dist[i][j] = g.matr[i][j];

  // Verificare
  for(int i = 0 ; i < g.n ; i++){
    for(int j = 0; j < g.n; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }


  for(k = 0; k < g.n; k++)
    for(i = 0; i < g.n; i++)
      for(j = 0; j < g.n; j++)
        if(dist[i][k] + dist[k][j] < dist[i][j])  // Daca distanta de la i la k + distanta de la k la j este mai mica decat distanta pe care noi deja o cunoastem ca fiind posibila de la i la j.
          dist[i][j] = dist[i][k] + dist[k][j]; // Distanta de la i la j va fi noua suma de mai sus.

  return dist;
}

int main(){

  int n;
  int m;
  int src, dest, val;
  Graf g;
  FILE *fptr;
  if ((fptr = fopen("input.txt", "r")) == NULL) {
      printf("Error! opening file");
       // Program exits if file pointer returns NULL.
       exit(1);
  }
  fscanf(fptr, "%d\n", &n);
  fscanf(fptr, "%d\n", &m);

  initG(&g, n);
  printGraph(g);


  for(int i = 0 ; i < m; i++){
      fscanf(fptr, "%d %d %d\n", &src, &dest, &val);    
      addArc(&g, src, dest, val);
  }

  printGraph(g);

  for(int i = 0; i < g.n; i++)
    for(int j = 0; j < g.n; j++)
      if(g.matr[i][j] == 0)
        g.matr[i][j] = 1000000;

  int **dist = floyd_warshall(g);
 
  for(int i = 0 ; i < g.n ; i++){
    for(int j = 0; j < g.n; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }


  return 0;
}
