#include <stdio.h>
#include <math.h>

typedef struct Punct{
  float x,y;
}Punct;


int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);
  int i;
  Punct v[100];

  for(i = 0 ;i < n ; i++){
    scanf("%f %f",&v[i].x,&v[i].y);
  }

  float dist[100];

  int ok = 1;
  for(i = 0; i < n-1;i++){
    dist[i] = sqrt( pow((v[i].x - v[i+1].x),2) + pow((v[i].y - v[i+1].y),2) );
  }

  dist[n-1] = sqrt( pow((v[0].x - v[n-1].x),2) + pow((v[0].y - v[n-1].y),2) );

  for(i = 0; i < n-1; i++){
    if(dist[i] != dist[i+1]){
      ok = 0;
    }
  }

  if(ok)
    printf("da\n");
  else
    printf("nu\n");

  return 0;
}
