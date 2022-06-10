#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int m,n;
  int matr[100][100];
  int i, j;

  scanf("%d",&m);
  scanf("%d",&n);

  for( i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      scanf("%d",&matr[i][j]);
    }
  }

  int v1[1000];
  int nrElem = 0;

  for(i = 0;i < m; i++){
    for(j = 0; j < n ;j++){
      v1[nrElem] = matr[i][j];
      nrElem++;
    }
  }

  int aparitii[1000] = {0};
  int dim1 = m * n;
  int dim2 = 0;

  for(i = 0; i < nrElem; i++){
    aparitii[v1[i]]++;
  }

  // aparitii[i] = .. -> de cate ori apare elementul i

  for(i = 0; i < 1000; i++){
    if(aparitii[i] != 0){
      dim2++;

    }
  }

  dim2 = dim2 * 2;
  printf("%d\n",dim1-dim2);

  return 0;
}
