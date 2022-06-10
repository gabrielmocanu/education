#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct nod {
	int val;
	struct nod *next;
} Nod;


void initLinkedList(Nod ** head) {
	*head = NULL;
}

void addFirst(Nod **head, int x){
	Nod *new = (Nod *) malloc(sizeof(Nod));
	new -> val = x;
	new -> next = *head;

	*head = new;
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

void printLinkedList(Nod *head){
	
	Nod *aux = head;
	while(aux != NULL){
		printf("%d ", aux -> val);
		aux = aux -> next;
	}
	printf("\n");
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

void deleteLast(Nod **head){
  
  Nod *aux = *head;
  Nod *del;
  
  if(getSize(*head) == 0){
    return ;
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

// pos = 1 sterge al doilea element
// pos = 0 ???
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


int searchValue(Nod **head, int value){
  Nod *aux = *head;

  while(aux != NULL) {
    if(aux -> val == value)
      return 1;
    aux = aux -> next;
  }

  return 0;

}


void addNode(Nod **head, int pos, int x){

  Nod *new = (Nod *) malloc(sizeof(Nod));
  new -> val = x;

  Nod *aux = *head;
  Nod *aux_2;

  if(pos < 0 || pos > getSize(*head))
    return;

  if(pos == 0) {
    addFirst(head, x);
    return ;
  }

  if(pos == getSize(*head)) {
    addLast(head, x);
    return ;
  }


  while(pos != 1) {
    aux = aux -> next;
    pos--;
  }

  aux_2 = aux -> next;
  aux -> next = new;
  new -> next = aux_2;

  return ;
}

void stergeDublev2(Nod **head){
  Nod *aux_2;
  Nod *aux = *head;
  int index = 0;
  int index_2 = 0;

  while(aux != NULL){
    aux_2 = *head;
    index_2 = 0;
    while(aux_2 != NULL){
      if(aux_2 -> val == aux -> val && index != index_2){
        deleteNode(head, index_2);
        index_2--;
      }
      index_2++;
      aux_2 = aux_2 -> next;
    }
    index++;
    aux = aux -> next;
  }
}





void stergeDublele(Nod **head){

  Nod *linkedList;
  initLinkedList(&linkedList);
  Nod *aux = *head;
  int index = 0;

  while(aux != NULL){
    if(searchValue(&linkedList, aux -> val)){
      deleteNode(head, index);
      aux = aux -> next;
    } else {
      addFirst(&linkedList, aux -> val);
      index++;
      aux = aux -> next;
    }
  }

  while(linkedList){
    deleteFirst(&linkedList);
  }

}

int main(){
	
	Nod *linkedList;
	initLinkedList(&linkedList);
	addFirst(&linkedList, 10);
	addFirst(&linkedList, 10);
	addFirst(&linkedList, 10);
	addFirst(&linkedList, 40);
	addLast(&linkedList, 30);
	addLast(&linkedList, 10);
	addLast(&linkedList, 10);
	addLast(&linkedList, 30);

  printLinkedList(linkedList);

  stergeDublev2(&linkedList);
  printLinkedList(linkedList);

}
