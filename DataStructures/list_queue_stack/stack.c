#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nod {
  int val;
  struct nod *next;
} Nod;


void initLinkedList(Nod **head) {
  *head = NULL;
}

// Fix acelasi lucru cu addFirst de la liste
void push(Nod **head, int x){
  Nod *new = (Nod *)malloc(sizeof(Nod));
  new -> val = x;
  new -> next = *head;

  *head = new;
}

void printStack(Nod *head){

  Nod *aux = head;
  while(aux != NULL){
    printf("%d ", aux->val);
    aux = aux -> next;
  }
  printf("\n");
}

// deleteFirst de la liste
int pop(Nod **head){
  
  int ret = (*head) -> val;
  Nod *aux = *head;
  *head = (*head) -> next;
  free(aux);
  aux = NULL;

  return ret;
}

int peek(Nod *head){
  return head->val;
}
