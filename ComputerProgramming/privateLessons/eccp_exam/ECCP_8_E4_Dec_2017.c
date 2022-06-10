#include <stdio.h>
#include <math.h>

typedef struct Triunghi{
  float a,b,c;
}Triunghi;

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d",&n);

  int i;
  Triunghi t[100];

  for(i = 0;i < n; i++){
    scanf("%f %f %f",&t[i].a,&t[i].b,&t[i].c);
  }

  float aux = 0;
  float max = 0;
  float perimetru = 0;
  float arie = 0;
  int index;

  for(i = 0; i < n; i++){

    if(t[i].a + t[i].b < t[i].c || t[i].c + t[i].a < t[i].b || t[i].b + t[i].c < t[i].a) // nu se poate
    {
      continue;
    }
    if(t[i].a == t[i].b || t[i].a == t[i].c || t[i].b == t[i].c) // isoscel
    {
      continue;
    }
    if(pow(t[i].a,2) + pow(t[i].b,2) == pow(t[i].c,2) || pow(t[i].a,2) + pow(t[i].c,2) == pow(t[i].b,2) || pow(t[i].b,2) + pow(t[i].c,2) == pow(t[i].a,2) ) // dreptunghic
    {
      continue;
    }

    perimetru = t[i].a + t[i].b + t[i].c;
    arie = sqrt((perimetru/2)*(perimetru/2 - t[i].a)*(perimetru/2 - t[i].b)*(perimetru/2 - t[i].c));
    aux = arie/perimetru;

    if(max < aux){
      max = aux;
      index = i;
    }
  }

  printf("%d %f\n",index,max);


  return 0;
}
