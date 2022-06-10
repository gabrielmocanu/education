#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct codBare{
  char cod[100];
  char tip;
  float valoare;
}codBare;


int main(int argc, char const *argv[]) {

  int n,k;
  int i, j;
  scanf("%d",&n);
  scanf("%d",&k);

  codBare v[100];
  char cod[100];
  int frec[100];

  float total = 0;

  for(i = 0; i < n; i++){
    scanf("%s %c %f",v[i].cod,&v[i].tip,&v[i].valoare);
  }

  for(i = 0; i < k; i++){
    scanf("%s",cod);


    for(j = 0; j < n; j++){
      if(!strcmp(cod,v[j].cod)){
        if(v[j].tip == 'p')
          total = total + v[j].valoare;
        else{
          frec[j]++;
        }
      }
      // printf("%s %s\n",cod,v[j].cod);
    }
  }

  for(i = 0 ; i < n ;i++){
    if(frec[i] != 0){
      total = total * (100.0 - v[i].valoare)/100.0;
    }
  }

  printf("%f\n",total);

  return 0;
}
