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


int minValue(int *values, int *visited, int n){

  int min_index = 0;
  int min = 100000;
  for(int i = 0; i < n; i++) {
    if(visited[i] == 0 && values[i] < min) {
      min = values[i];
      min_index = i;
    }
  }

  return min_index;
}


int *prim(Graf g){

  int node;
  int visited[g.n]; // ne spune daca nodul la care vrem sa mergem a fost vizitat sau nu Daca a fost vizitat nu il mai parcurgem
  int values[g.n]; // Vectorul de distante pentru fiecare nod
  int *parent = malloc(g.n * sizeof(int));

  for(int i = 0; i < g.n; i++){
    values[i] = 100000;
    visited[i] = 0;
  }

  values[0] = 0;
  parent[0] = -1;

  for(int i = 0; i < g.n - 1; i++){
    node = minValue(values, visited, g.n);
    visited[node] = 1;

    for(int j = 0; j < g.n; j++){
      if(g.matr[node][j] != 0 && visited[j] == 0 && g.matr[node][j] < values[j])
      {
        parent[j] = node;
        values[j] = g.matr[node][j];
      }
    }

  }

  return parent;
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

  int *parent = prim(g);
  for(int i = 1 ; i < g.n ; i++){
    printf("(%d,%d) with %d val\n", parent[i], i, g.matr[parent[i]][i]);
  }


  return 0;
}
