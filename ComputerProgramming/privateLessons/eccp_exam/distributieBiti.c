#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);

  int i;
  char v[100];
  for(i = 0;i < n; i++){
    scanf("%c",&v[i]);
  }

  int nr00 = 0;
  int nr01 = 0;
  int nr10 = 0;
  int nr11 = 0;

  for(i = 0; i < n; i+=2){

    if(v[i] == '0' && v[i+1] == '0'){
      nr00++;
    }
    if(v[i] == '0' && v[i+1] == '1'){
      nr01++;
    }
    if(v[i] == '1' && v[i+1] == '0'){
      nr10++;
    }
    if(v[i] == '1' && v[i+1] == '1'){
      nr11++;
    }
  }


  int max = 0;
  int min = 999;

  if(nr00 > max)
    max = nr00;
  if(nr01 > max)
    max = nr01;
  if(nr10 > max)
    max = nr10;
  if(nr11 > max)
    max = nr11;

  if(nr00 < min)
    min = nr00;
  if(nr01 < min)
    min = nr01;
  if(nr10 < min)
    min = nr10;
  if(nr11 < min)
    min = nr11;


  float rez1 = (float)max/min;

  int nrBiti1 = 0;
  int nrBiti0 = 0;

  for(i = 0; i < n; i ++){
    if(v[i] == '1')
      nrBiti1++;
    else
      nrBiti0++;
  }

  float rez2 = (float)nrBiti1/nrBiti0;

  printf("%f %f\n",rez1,rez2);

  if(rez1 > 1.10 || rez2 > 1.10){
    printf("0\n");
  }else{
    printf("1\n");
  }


  return 0;
}
