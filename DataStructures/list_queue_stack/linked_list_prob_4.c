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

void reverseListInPlace(Nod **head){

  Nod *prev = NULL;
  while( (*head) != NULL ) {
    Nod *next = (*head) -> next;
    (*head) -> next = prev;
    prev = (*head);
    (*head) = next;
  }

  (*head) = prev;
}

int checkPalindrom(Nod *head) {

  Nod *fast = head;
  Nod *slow = head;

  while(fast != NULL && fast -> next != NULL){
    fast = fast -> next -> next;
    slow = slow -> next;
  }

  reverseListInPlace(&slow);
  fast = head;

  while(slow != NULL && fast != NULL){
    if(slow -> val != fast -> val)
      return -1;
    
    slow = slow -> next;
    fast = fast -> next;
  }

  return 1;
}

int main(){
	
	Nod *linkedList_1;
	initLinkedList(&linkedList_1);
	addLast(&linkedList_1, 1);
	addLast(&linkedList_1, 2);
	addLast(&linkedList_1, 3);
	addLast(&linkedList_1, 3);
	addLast(&linkedList_1, 2);
	addLast(&linkedList_1, 1);
	printLinkedList(linkedList_1);

  Nod *linkedList_2;
  initLinkedList(&linkedList_2);
  addFirst(&linkedList_2, 1);
  addFirst(&linkedList_2, 3);

  int check_1 = checkPalindrom(linkedList_1);
  int check_2 = checkPalindrom(linkedList_2);

  printf("%d\n", check_1);
  printf("%d\n", check_2);


}