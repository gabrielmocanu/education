#include<stdio.h>
#include<math.h>

typedef struct Nava{
  int atac;
  int aparare;
}Nava;

int main(int argc, char const *argv[]) {

  Nava navaProprie;
  scanf("%d %d\n",&navaProprie.aparare,&navaProprie.atac);
  int n;
  scanf("%d\n",&n);
  int i;
  Nava nave[100];
  int nr = 0; // cate nave bat
  for(i = 0; i < n; i++){
    scanf("%d %d",&nave[i].aparare,&nave[i].atac);
  }

  int nrAtac1,nrAtac2; // nrAtac1 -> din cate lovituri m-ar bate nava inamica
                      // nrAtac2 -> din cate lovituri as bate eu nava inamica
  for(i = 0;i < n; i++){
    nrAtac1 = navaProprie.aparare/nave[i].atac + 1;
    nrAtac2 = nave[i].aparare/navaProprie.atac + 1;

    if(nrAtac1 > nrAtac2){
      nr++;
    }
  }

  printf("%d\n",nr);
  return 0;
}
