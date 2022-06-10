#include<stdio.h>
#include<stdlib.h>

typedef struct nod {
	int val;
	struct nod *next;
} Nod;


void pushHead(Nod **head, int data)
{
	Nod *current = (Nod *)malloc(sizeof(Nod));
	current -> val = data;
	current -> next = (*head);
	(*head) = current;
}

void appendLast(Nod **head, int data)
{
	Nod *current = (Nod *)malloc(sizeof(Nod));
	Nod *last = *head;
	current -> val = data;
	current -> next = NULL;
	if( *head == NULL )
	{
		*head = current;
		return;
	}

	while(last -> next != NULL)
		last = last -> next;

	last -> next = current;
	return;
}


void printList(Nod* list) {

	Nod *current = list;

	while(current != NULL)
	{
		printf("%d ",current -> val);
		current = current -> next;
	}

}

int isEmpty(Nod *list) {

	if(list -> next == NULL)
		return 1;
	else
		return 0;
}


int length(Nod *list) {
	int l = 0;
	Nod *current = list;
	while(current != NULL)
	{
		l++;
		current = current -> next;
	}
	return l;

}


void AddAtPosition(int pos,char *operation,Nod **head)
{
	int i;
	Nod *temp = (Nod *)malloc(sizeof(Nod));
	Nod *temp1;
	Nod *temp2;
	temp1 = *head;
	for(i=0;i<pos-2;i++)
		temp1 = temp1 -> next;
	temp -> next = temp1 -> next;
	temp1 -> next = temp;
	if(temp -> next != NULL )
	{
		temp2 = temp -> next;
	}
}


void InsertMid(Nod **head,int data)
{
	int l=0;
	int position;
	Nod *newNode = (Nod *)malloc(sizeof(Nod));
	newNode -> val = data;
	newNode -> next = NULL;
	Nod *current = *head ;
	while(current != NULL)
	{
		l++;
		current = current -> next;
	}

	if(l%2 == 0)
		position = l/2;
	else
		position = l/2 + 1;

	current = *head;
	while(position > 1)
	{
		position--;
		current = current -> next;
	}
	newNode -> next = current -> next;
	current -> next = newNode;
}

void exercitiul3(int p,int l,Nod **head,int data)
{
	if(p==0)
		pushHead(head,data);
	else
	if(p<l)
		InsertMid(head,data);
	else
		appendLast(head,data);

}

void delHead(Nod **head)
{
	Nod *current = *head;
	*head = current -> next;
	free(current);
	return;
}

int extractHead(Nod *head)
{
	return head -> val;
}

void delMid(Nod **head)
{
    Nod *pre_ptr = *head;
    Nod *post_ptr = *head;
    Nod *prev;
    while (post_ptr != NULL && post_ptr->next != NULL)
    {
        post_ptr = post_ptr->next->next;
        prev = pre_ptr;
        pre_ptr = pre_ptr->next;
    }
    prev->next = pre_ptr->next;
    free(pre_ptr);
}

void delLast(Nod **head)
{
	Nod *current = *head;
	Nod *t;
  	while(current->next != NULL)
  	{
    	t=current;
    	current=current->next;
  	}
  	free(t->next);
  	t->next=NULL;

}

void exercitiul4(int p,int l,Nod **head)
{
	if(p==0)
		delHead(head);
	else
	if(p<l)
		delMid(head);
	else
		delLast(head);

}

int find(Nod **head,int x)
{
	int pos = 1;
	Nod *current = *head;
	while(current != NULL)
	{
		if(current -> val == x)
			return pos;
		pos++;
		current = current -> next;
	}
	return -1;
}

void MoveNode(Nod **destinatie, Nod **sursa)
{
	Nod *newNode = *sursa;
	*sursa = newNode -> next;
	newNode ->  next = *destinatie;
	*destinatie = newNode;
}



int main(int argc, char const *argv[])
{

		Nod *head = NULL;
		pushHead(&head, 7);
		appendLast(&head,6);
  	pushHead(&head, 1);
  	appendLast(&head, 4);
  	InsertMid(&head,10);
  	int a = extractHead(head);
  	printf("%d\n",a);
 /* int len = length(head);
  	exercitiul3(0,len,&head,15);
  	//delHead(&head);
  	//delMid(&head);
  	len = length(head);
  	printList(head);
  	printf("\n");
  	exercitiul4(2,len,&head);
   	printList(head);
   //	printf("\n\n%d",find(&head,111));


   	Nod *a = NULL;
   	Nod *b = NULL;

   	appendLast(&a,1);
   	appendLast(&a,4);
   	appendLast(&a,7);
   	appendLast(&b,2);
   	appendLast(&b,3);
   	appendLast(&b,5);

   	Nod *res =NULL;

   	printf("\n");
   	printList(a);
   	printf("\n");
   	printList(b);

   	res = SortedMergeRec(a,b);
   	printf("\n");
   	printList(res); */

	return 0;
}
