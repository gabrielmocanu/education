#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Arbore complet

typedef struct nod {
  int val;
  struct nod *left;
  struct nod *right;
} Nod;


void insert(Nod **root, int x){

    Nod *aux = *root;
    Nod *new = (Nod *)malloc(sizeof(Nod));
    new -> val = x;
    new -> left = NULL;
    new -> right = NULL;

    if(aux == NULL){
      *root = new;
      return ;
    } else if(x < aux -> val) {
      insert(&(aux -> left), x);
    } else {
      insert(&(aux -> right) ,x);
    }
}

void print2D(Nod *root, int space){

  if(root == NULL)
    return ;

  space += 5;
  print2D(root -> right, space);

  printf("\n");
  for(int i = 5; i < space; i++){
    printf(" ");
  }
  printf("%d\n", root->val);

  print2D(root -> left, space);
}

int countNodes(Nod *root)
{
  if(root == NULL)
    return 0;

  return (1 + countNodes(root->left) + countNodes(root->right));
}

int isComplete(Nod *root, int index, int nr_nodes)
{

  if(root == NULL)
    return 1;

  if(index >= nr_nodes)
    return 0;

  return (isComplete(root->left, 2*index + 1, nr_nodes) &&
          isComplete(root->right, 2*index + 2, nr_nodes));
}

int main(){

  Nod *tree = NULL;
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 5);
//  insert(&tree, 30);
//  insert(&tree, 29);
//  insert(&tree, 81);
//  insert(&tree, 1);
//  insert(&tree, 0);
//  insert(&tree, 40);
//  insert(&tree, -40);
//  insert(&tree, 17);
//  insert(&tree, 13);
//  insert(&tree, -5);

  print2D(tree, 0);

  int complete = isComplete(tree, 0, countNodes(tree));
  printf("%d\n",complete);

}
