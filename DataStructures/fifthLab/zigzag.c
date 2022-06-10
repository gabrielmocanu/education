#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nod {
  int val;
  struct nod *left;
  struct nod *right;
} Nod;


Nod *newNode(int x){

    Nod *new = (Nod *)malloc(sizeof(Nod));
    new -> val = x;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}

// Sau cu Nod *aux = *root;
void insert(Nod **root, int x){

    Nod *new = newNode(x);

    if((*root) == NULL){
      *root = new;
      return ;
    } else if(x < (*root) -> val) {
      insert(&((*root) -> left), x);
    } else {
      insert(&((*root) -> right) ,x);
    }
}

// Facuta de noi
int findM(Nod *root, int x){
  if(root == NULL)
    return -1;

  if(x == root -> val){
    return 1;
  }else if(x < root->val){
    findM(root->left, x);
  } else {
    findM(root->right, x);
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

int find(Nod *root, int x){
  
  if(root == NULL)
    return -1;

  if(root -> val == x)
    return 1;

  if(root -> val > x)
    find(root -> left, x);
  else
    find(root -> right, x);

}

Nod *find_nod(Nod *root, int x){
  
  if(root == NULL)
    return NULL;

  if(root -> val == x)
    return root;

  if(root -> val > x)
    find(root -> left, x);
  else
    find(root -> right, x);
}

// Facuta de noi
void postOrderV2(Nod *root){
  if(root == NULL)
    return;

  postOrderV2(root->left);
  postOrderV2(root->right);
  printf("%d\n", root->val);
}

// Inorder = (left, root, right)
// Preorder = (root, left, right)
// Postordine = (left, right, root)

void inorder(Nod *root){

  if(root == NULL)
    return;

  inorder(root -> left);
  printf("%d\n", root->val);
  inorder(root -> right);

}

void preorder(Nod *root){

  if(root == NULL)
    return ;

  printf("%d\n", root->val);
  preorder(root -> left);
  preorder(root -> right);

}

void postorder(Nod *root){

  if(root == NULL)
    return;

  postorder(root -> left);
  postorder(root -> right);
  printf("%d\n", root->val);

}


Nod *deleteNode(Nod **root, int key){

  Nod *succesor;
  Nod *temp;
  Nod *aux = *root;
  if( aux == NULL ) 
    return aux;

  if(key < aux -> val)
    aux -> left = deleteNode(&(aux -> left), key);
  else if( key > aux -> val)
    aux -> right = deleteNode(&(aux -> right), key);
  else {
    
    // Pentru cazul cand avem 1 copil
    if( aux -> left == NULL){
      temp = aux -> right;
      free(aux);
      return temp;
    }
    else if( aux -> right == NULL) {
      temp = aux -> left;
      free(aux);
      return temp;
    }

    // Pentru cazul cand avem 2 copii
    // De la linia 174 - 176 => GetSuccesor care ne da cel mai mic numar mai
    // mare decat numarul pe care noi vrem sa il stergem.
    succesor = aux -> right;
    while( succesor -> left != NULL)
      succesor = succesor -> left;

    aux -> val = succesor -> val;
    aux -> right = deleteNode(&(aux -> right), succesor -> val);
  }
}

// TBD - MIN VALUE
// TBD - MAX VALUE
// TBD - NR ELEMENTE


int minValue(Nod *root){
  if(root == NULL)
    return -1;
  else if(root -> left != NULL){
    minValue(root->left);
  } else {
    return root->val;
  }
}

int maxValue(Nod *root){
  if(root == NULL)
    return -1;
  else if(root -> right != NULL){
    maxValue(root->right);
  } else {
    return root->val;
  }
}

int nrNodes(Nod *root){

  if(root == NULL)
    return 0;

  return 1 + nrNodes(root->left) + nrNodes(root->right);
}

int height(Nod *root){

  if(root == NULL)
    return 0;
  else {

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
      return (leftHeight + 1);
    else
      return (rightHeight + 1);
  }
}

void printOddLevel(Nod *root, int h){

  if(root == NULL)
    return ;

  if(h == 1)
    printf("%d ", root->val);
  else if(h > 1){
    printOddLevel(root->left, h - 1);
    printOddLevel(root->right, h - 1);
  }
}

void printEvenLevel(Nod *root, int h){

  if(root == NULL)
    return ;

  if(h == 1)
    printf("%d ", root->val);
  else if(h > 1){
    printEvenLevel(root->right, h - 1);
    printEvenLevel(root->left, h - 1);
  }
}


void printZigZag(Nod *root)
{

  int h = height(root);
  for(int i = 1; i <= h; i++){
    if(i % 2 == 1)
      printOddLevel(root, i);
    else
      printEvenLevel(root, i);
  }
}

void bfs(Nod *root){

  int h = height(root);
  for(int i = 1; i <= h; i++){
    printOddLevel(root, i);
  }
}

int main(){

  Nod *tree = NULL;
  insert(&tree, 10);
  insert(&tree, 20);
  insert(&tree, 5);
  insert(&tree, 30);
  insert(&tree, 29);
  insert(&tree, 81);
  insert(&tree, 1);
  insert(&tree, 0);
  insert(&tree, 40);
  insert(&tree, -40);
  insert(&tree, 17);
  insert(&tree, 13);
  insert(&tree, -5);

  print2D(tree, 0);

  printZigZag(tree);
  printf("\n");
  bfs(tree);

}
