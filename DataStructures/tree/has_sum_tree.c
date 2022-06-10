#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Suma pana la frunza de x

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

int hasPathSum(Nod *root, int sum)
{
  int leftSum;
  int ret = 0;
  if(root == NULL){
    return ret;
  } else {

    leftSum = sum - root->val;
    if( leftSum == 0 && root->left == NULL && root->right == NULL )
      return 1;

    if( root -> left != NULL )
      ret = ret || hasPathSum(root -> left, leftSum);

    if( root -> right != NULL )
      ret = ret || hasPathSum(root -> right, leftSum);

    return ret;
  }
}

int main(){

  Nod *tree = NULL;
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 5);
  insert(&tree, 30);
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

  int hasPath = hasPathSum(tree, 99);
  printf("%d\n",hasPath);

}
