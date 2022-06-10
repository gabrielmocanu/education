#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Edge {
  int src;
  int dest;
  int cost;
} Edge;

typedef struct subset
{
    int parent;
    int rank;
}subset;

typedef struct {
  int n, m;
  int **matr;
} Graf;

int find(subset *subsets, int i) 
{
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 

    return subsets[i].parent; 
}

void Union(struct subset subsets[], int x, int y) 
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    }
}

int myComp(const void* a, const void* b) 
{
    Edge* a1 = (Edge*)a; 
    Edge* b1 = (Edge*)b; 
    return a1->cost > b1->cost;
}

void initG(Graf *g, int n){

  int i;
  g->n = n;
  g->m = 0;

  g->matr = (int **) malloc((n)*sizeof(int*));
  for(int i = 0; i < n; i++)
    g->matr[i] = (int *)calloc( (n), sizeof(int));
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
  g->matr[y][x] = 0;
  g->m--;
}

void delNod(Graf *g, int x){

  int i;
  for(i = 0; i < g -> n; i++){
    delArc(g, x, i);
  }
}


void kruskhal(Graf g)
{
  int k = 0;
  int i = 0;
  int e = 0;

  subset *subsets = (subset*) malloc( g.n * sizeof(struct subset)); // fiecare nod o sa apartina unui subset ( o sa aiba un parinte si un rank )
  Edge *edges = malloc(g.m * sizeof(Edge));  // tinem toate muchiile si le vom sorta in ordine crescatoare 
  Edge *result = malloc((g.n - 1)  * sizeof(Edge)); // tinem toate muchiile din spanning tree
  for(int i = 0; i < g.n; i++)
    for(int j = i + 1; j < g.n; j++){
      if(g.matr[i][j] != 0) {
        edges[k].src = i;
        edges[k].dest = j;
        edges[k].cost = g.matr[i][j]; 
        k++;
      }
    }

  qsort(edges, g.m, sizeof(edges[0]), myComp);

  for (int i = 0; i < g.n; i++)
  {
      subsets[i].parent = i;
      subsets[i].rank = 0;
  }

    while (e < g.n - 1 && i < g.m)
    {

        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // Nu formeaza ciclu, dar daca x = y ar trebui sa sarim peste acea
        // muchie
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    for (i = 0; i < e; ++i) 
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
                                                 result[i].cost); 
    return;
  

}

void printGraph(Graf g){
  for(int i = 0; i < g.n; i++){
    for(int j = 0; j < g.n; j++){
      printf("%d ",g.matr[i][j]);
    }
    printf("\n");
  }
}

int main(){

  int n;
  int m;
  int src, dest, val;
  Graf g;
  FILE *fptr;
  if ((fptr = fopen("input_kruskal.txt", "r")) == NULL) {
      printf("Error! opening file");
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

  kruskhal(g);
  return 0;
}
