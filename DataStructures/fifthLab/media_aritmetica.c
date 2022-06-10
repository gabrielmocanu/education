#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
  int val;
  struct Node *next;
  struct Node *prev;
} Nod;


void initDoubleLinkedList(Nod **head) {
  *head = NULL;
}

void addFirst(Nod **head, int x) {
  Nod *new = (Nod *)malloc(sizeof(Nod));
  new -> val = x;
  new -> next = *head;
  new -> prev = NULL;

  *head = new;
}

void addLast(Nod **head, int x) {
  Nod *new = (Nod *)malloc(sizeof(Nod));
  new -> val = x;
  new -> next = NULL;

  Nod *aux = *head;

  if(aux == NULL){
    new -> prev = NULL;
    *head = new;
    return ;
  }

  while(aux -> next != NULL){
    aux = aux -> next;
  }

  aux -> next = new;
  new -> prev = aux;
}

void printDoubleLinkedList(Nod *head){
  
  Nod *aux = head;
  while(aux != NULL){
    printf("%d ", aux -> val);
    aux = aux -> next;
  }

  printf("\n");
}

void medieAritmeticav2(Nod **head){

  int medie;
  Nod *aux = *head;

  while(aux != NULL && aux -> next != NULL){

    medie = (aux -> val + aux -> next -> val) / 2;
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new -> val = medie;
 
    new -> next = aux -> next;
    new -> prev = aux;
    aux -> next = new;
    aux -> next -> prev = new;

    aux = aux -> next -> next;
  }

}


void deleteFirst(Nod **head){
  
  Nod *aux = *head;
  *head = (*head) -> next;
  (*head) -> prev = NULL;
  free(aux);
  aux = NULL;
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

void deleteLast(Nod **head){

  Nod *aux = *head;
  Nod *del;
  if(getSize(*head) == 0){
    return;
  } else if (getSize(*head) == 1) {
    free(*head);
    *head = NULL;
  } else {
    while(aux -> next -> next != NULL){
      aux = aux -> next;
    }

    del = aux -> next;
    aux -> next = NULL;
    free(del);
    del = NULL;
  }
}

void mediaAritmetica(Nod **head){

  Nod *aux = *head;
  int nr = 1;
  int nrElements = getSize(*head);
  int medie;

  while(nr < nrElements) {

    medie = (aux -> val + aux -> next ->val) / 2;
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new -> val = medie;

    new -> next = aux -> next;
    new -> prev = aux;
    aux -> next = new;
    aux -> next -> prev = new;

    nr++;
    aux = aux -> next -> next;
  }


}

void addNode(Nod **head, int pos, int x){

  Nod *new = (Nod *) malloc(sizeof(Nod));
  new -> val = x;

  Nod *aux = *head;
  if(pos < 0 || pos > getSize(*head))
    return;

  if(pos == 0) {
    addFirst(head, x);
    return ;
  }

  if(pos == getSize(*head)) {
    addLast(head, x);
    return;
  }

  while(pos != 1){
    aux = aux -> next;
    pos--;
  }

  new -> next = aux -> next;
  aux -> next -> prev = new;
  aux -> next = new;
  new -> prev = aux;


  return ;
}

void deleteNode(Nod **head, int pos) {

  Nod *aux = *head;
  Nod *del;

  if(pos < 0 || pos > getSize(*head))
    return;

  if(pos == 0) {
    deleteFirst(head);
    return ;
  }

  if(pos == getSize(*head)) {
    deleteLast(head);
    return;
  }

  while(pos != 1){
    aux = aux -> next;
    pos--;
  }

  del = aux -> next;
  aux -> next = del -> next;
  del -> next -> prev = aux;
  free(del);
  del = NULL;

  return;
}

int main(){

  Nod *doubleLinkedList;
  initDoubleLinkedList(&doubleLinkedList);
  addFirst(&doubleLinkedList, 10);
  addFirst(&doubleLinkedList, 20);
  addFirst(&doubleLinkedList, 30);
  addFirst(&doubleLinkedList, 40);
  
  printDoubleLinkedList(doubleLinkedList);

  mediaAritmetica(&doubleLinkedList);
  printDoubleLinkedList(doubleLinkedList);

  return 0;
}
