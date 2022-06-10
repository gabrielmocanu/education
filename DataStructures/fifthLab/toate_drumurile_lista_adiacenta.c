#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nod {
  int cost;
  int dest;
  struct nod *next;
} Nod;

typedef struct Graph {
  int n, m;
  Nod **nodes;
} Graph;

void initG(Graph *g, int n){
  g->n = n;
  g->nodes = (Nod **)calloc(n, sizeof( Nod *));
}

void addFirst(Nod **head, int dest, int cost){
	Nod *new = (Nod *) malloc(sizeof(Nod));
	new -> cost = cost;
  new -> dest = dest;
	new -> next = *head;

	*head = new;
}

void printLinkedList(Nod *head){
	
	Nod *aux = head;
	while(aux != NULL){
		printf("(%d, %d) ", aux -> cost, aux -> dest);
		aux = aux -> next;
	}
	printf("\n");
}

void printGraph(Graph g){
  for(int i = 0 ; i <  g.n; i++){
    printf("%d : ", i);
    printLinkedList(g.nodes[i]);
  }
  printf("\n");
}

int arc(Graph g, int x, int y){
  Nod *aux = g.nodes[x];

  while(aux != NULL){
    if(aux->dest == y)
      return aux->cost;

    aux = aux -> next;
  }

  return 0;
}

void deleteFirst(Nod **head){
  
  Nod *aux = *head;
  *head = (*head) -> next;
  free(aux);
}

int getSize(Nod *head){
  
  int size = 0;
  Nod *aux = head;
  while(aux != NULL){
    size++;
    aux = aux -> next;
  }

  return size;
}

void deleteNode(Nod **head, int pos){

  Nod *aux = *head;
  Nod *del;

  if(pos == 0)
  {
    deleteFirst(head);
    return ;
  }

  if(getSize(*head) < pos){
    return ;
  }

  while(aux ->next != NULL && pos != 1) {
    aux = aux -> next;
    pos--;
  }

  del = aux -> next;
  aux -> next = del -> next;
  free(del);

}


void delArc(Graph *g, int x, int y){
  Nod *aux = g -> nodes[x];
  int pos = 0;

  while(aux != NULL)
  {
    if(aux -> dest == y){
      deleteNode(&(g -> nodes[x]), pos);
    }
    pos++;
    aux = aux -> next;
  }

  aux = g -> nodes[y];
  pos = 0;
  while(aux != NULL)
  {
    if(aux -> dest == x){
      deleteNode(&(g -> nodes[y]), pos);
    }
    pos++;
    aux = aux -> next;
  }
  return ;
}

void addArc(Graph *g, int x, int y, int cost)
{
  addFirst(&(g->nodes[x]), y, cost);
  addFirst(&(g->nodes[y]), x, cost);
  return ;
}

Nod *getNode(Nod *head, int pos){
  int i = 0;
  Nod *aux = head;
  while(i < pos){
    aux = aux -> next;
    i++;
  }
  
  return aux;
}



int minDistance(int *values, int *visited, int n){

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


int *dijkstra(Graph g, int src){

  int node;
  int *dist = malloc(g.n*sizeof(int));
  int visited[g.n];

  for(int i = 0; i < g.n; i++){
    dist[i] = 100000;
    visited[i] = 0;
  }

  dist[src] = 0;

  for(int i = 0; i < g.n - 1; i++){
    node = minDistance(dist, visited, g.n);
    visited[node] = 1;

    // dist[node] = distanta de la src la node
    // dist[j] = distanta de la src la j pe care noi o stiam initial ( in
    // principiu e INFINIT )
    for(int j = 0; j < getSize(g.nodes[node]); j++){
      Nod *aux = getNode(g.nodes[node], j);

      if(visited[aux->dest] == 0 && dist[node] + aux->cost < dist[aux->dest] )
      {
        dist[aux->dest] = dist[node] + aux->cost;
      }
    }

  }

  return dist;
}


// path_index la inceput e 0 pentru ca nu avem inca niciun nod in drum
void printAllPaths(Graph g, int n, int source, int destination, int *visited, int *path, int *path_index){

  visited[source] = 1;
  path[*path_index] = source;
  (*path_index)++;

  // Am gasit un drum de la sursa la destinatie
  if(source == destination) {
    for(int i = 0; i < *path_index; i++)
      printf("%d ", path[i]);
    printf("\n");
  }else{
    for(int i = 0; i < getSize(g.nodes[source]); i++){
      Nod *aux = getNode(g.nodes[source], i);

      if(visited[aux->dest] == 0)
        printAllPaths(g, n, aux->dest, destination, visited, path, path_index);
    }
  }

  (*path_index)--;
  visited[source] = 0;
}


int main(){

  int path_index = 0;
  int *visited = malloc(10 * sizeof(int));
  int *path = malloc(10 * sizeof(int));

  for(int i = 0; i < 10; i++){
    visited[i] = 0;
  }

  Graph g;
  initG(&g, 10);

  printGraph(g);

  printf("\n");
  addArc(&g, 1, 2, 3);
  addArc(&g, 1, 3, 6);
  addArc(&g, 3, 2, 9);
  addArc(&g, 5, 7, 12);
  addArc(&g, 7, 2, 15);
  addArc(&g, 1, 5, 15);
  printGraph(g);

  printAllPaths(g, 10, 1, 2, visited, path, &path_index);

  return 0;
}
