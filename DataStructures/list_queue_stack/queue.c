#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nod {
	int val;
	struct nod *next;
} Nod;


void initQueue(Nod ** head) {
	*head = NULL;
}

void addLast(Nod **head, int x){
	Nod *new = (Nod *) malloc(sizeof(Nod));
	new -> val = x;
	new -> next = NULL;

	Nod *aux = *head;
	
	if(aux == NULL){
		*head = new;
    return ;
	}

	while(aux -> next != NULL){
		aux = aux -> next;
	}

	aux -> next = new;
}

void printQueue(Nod *head){
	
	Nod *aux = head;
	while(aux != NULL){
		printf("%d ", aux -> val);
		aux = aux -> next;
	}
	printf("\n");
}

int deleteFirst(Nod **head){
  
  int res = (*head) -> val;
  Nod *aux = *head;
  *head = (*head) -> next;
  free(aux);

	return res;
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

