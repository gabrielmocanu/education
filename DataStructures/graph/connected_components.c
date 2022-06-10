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


void dfs(int v, int *visited, Graf g){
    visited[v] = 1;
    printf("%d ",v);
    for(int i = 0; i < g.n; i++){
      if(g.matr[v][i] != 0 && !visited[i])
        dfs(i, visited, g);
    }
}

void conectedComponents(Graf g){

  int i;
  int visited[g.n];
  // Initializarea cu 0
  for(i = 0; i < g.n; i++)
    visited[i] = 0;

  for(i = 0; i < g.n; i++){
    if(visited[i] == 0){
      dfs(i, visited, g);
      printf("\n");
    }
  }
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

  conectedComponents(g);
  return 0;
}