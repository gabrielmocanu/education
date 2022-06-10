#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparam 2 arbori si vedem daca sunt egali.
//   1      1
// 2   3  2   3
//              6 

typedef struct nod {
  int val;
  struct nod *left;
  struct nod *right;
} Nod;

// Facut de noi
int sameTree(Nod *p, Nod *q){

  if(p == NULL && q == NULL) 
    return 1;
  if(p == NULL || q == NULL) 
    return 0;
  if(p -> val != q -> val) 
    return 0;

  return sameTree(p->left, q->left) && sameTree(p->right, q->right);

}

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

int isSameTree(Nod *p, Nod *q) {

  if( p == NULL && q == NULL) return 1;

  if( p == NULL || q == NULL) return 0;

  if(p -> val != q -> val) return 0;
  return isSameTree(p -> right, q -> right) &&
        isSameTree(p -> left, q -> left);

}


int main(){

  Nod *tree = NULL;
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 5);
  insert(&tree, 30);

  Nod *tree_2 = NULL;
  insert(&tree_2, 10);
  insert(&tree_2, 20);
  insert(&tree_2, 5);
  insert(&tree_2, 30);

  print2D(tree, 0);
  print2D(tree_2, 0);

  int sameTreeVar = sameTree(tree, tree_2);
  printf("%d\n",sameTreeVar);

}
