#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nod {
  int cost;
  int dest;
  struct nod *next;
} Nod;

typedef struct Graph {
  int n;
  int m;
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

int main(){

    Graph g;
    initG(&g, 10);
    printGraph(g);

    addArc(&g, 1, 2, 3);
    addArc(&g, 4, 5, 6);
    addArc(&g, 3, 2, 9);
    addArc(&g, 8, 5, 12);
    addArc(&g, 3, 7, 15);
    printGraph(g);

    printf("\n");
    delArc(&g, 3, 2);
    printGraph(g);

    // n * n - n = n*(n-1)/2 
    // 9 + 8 + .... 

    return 0;
}


