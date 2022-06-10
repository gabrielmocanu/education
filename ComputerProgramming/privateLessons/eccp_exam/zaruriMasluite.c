#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);
  int v[100];
  int fr[10] = {0};
  int i;
  int prag = n/10;
  int max = 0;
  int min = 99999;
  int diferenta = 0;

  for(i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }

  // Vectorul de frecventa; // fr[1] = de cate ori a picat 1
  for(i = 0; i< n; i++){
    fr[v[i]]++;
  }


  for(i = 1; i < 7; i++){
    if(fr[i] > max){
      max = fr[i];
    }

    if(fr[i] < min){
      min = fr[i];
    }

  }

  diferenta = max - min;

  if(diferenta > prag)
    printf("1\n");
  else
    printf("0\n");


  return 0;
}
