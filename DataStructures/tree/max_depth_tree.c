#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Adancimea maxima intr-un arbore

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

int maxDepth(Nod *root)
{
  if(root == NULL)
    return 0;
  else {

    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    if(lDepth > rDepth)
      return lDepth+1;
    else
      return rDepth+1;

  }
}

int main(){

  Nod *tree = NULL;
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 5);
  insert(&tree, 30);
  print2D(tree, 0);


  int max = maxDepth(tree);
  printf("%d\n", max);

}
