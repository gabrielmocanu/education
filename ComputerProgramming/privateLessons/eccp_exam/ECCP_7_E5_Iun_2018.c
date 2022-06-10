#include <stdio.h>
#include <math.h>

typedef struct Fruct{
  int tip;
  int masa;
  int r,g,b;
}Fruct;


int main(int argc, char const *argv[]) {

  int n,k,m,r,g,b;
  int i;
  Fruct fructe[100];

  scanf("%d",&n);
  scanf("%d",&k);
  scanf("%d",&m);
  scanf("%d",&r);
  scanf("%d",&g);
  scanf("%d",&b);


  for(i = 0 ; i < n; i++){
    scanf("%d",&fructe[i].tip);
    scanf("%d",&fructe[i].masa);
    scanf("%d",&fructe[i].r);
    scanf("%d",&fructe[i].g);
    scanf("%d",&fructe[i].b);
  }

  float dist_min = 99999999;
  float dist_aux = 0;
  int tip = 0;

  for(i = 0;i < n; i++){
    dist_aux = sqrt(pow(m-fructe[i].masa,2) + pow(r-fructe[i].r,2) + pow(g-fructe[i].g,2) + pow(b-fructe[i].b,2));
    if(dist_aux < dist_min){
      dist_min = dist_aux;
      tip = fructe[i].tip;
    }
  }

  printf("%d\n",tip);

  return 0;
}
