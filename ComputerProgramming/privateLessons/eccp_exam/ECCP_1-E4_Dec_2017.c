#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Data{
  int luna;
  int zi;
}Data;

int main(int argc, char const *argv[]) {

  Data date[100];

  char s[100];
  char s2[100];
  int n;
  int i;
  int ok = 1;
  Data aux;
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d-%d",&date[i].zi,&date[i].luna);
  }

  while(ok == 1){
    ok = 0;
    for(i = 0; i < n-1; i++){
      if(date[i].luna > date[i+1].luna){
        aux = date[i];
        date[i] = date[i+1];
        date[i+1] = aux;
        ok = 1;
      }else if(date[i].luna == date[i+1].luna){
        if(date[i].zi > date[i+1].zi){
          aux = date[i];
          date[i] = date[i+1];
          date[i+1] = aux;
          ok = 1;
        }
      }
    }
  }

  for(i = 0 ; i < n; i++){
    if( (date[i].luna != date[i+1].luna) || (date[i].zi != date[i+1].zi) ){

      if(date[i].luna <= 9 && date[i].zi <= 9)
        printf("0%d-0%d\n",date[i].zi,date[i].luna);

      if(date[i].luna <= 9 && date[i].zi > 9)
        printf("%d-0%d\n",date[i].zi,date[i].luna);

      if(date[i].zi <= 9 && date[i].luna > 9)
        printf("0%d-%d\n",date[i].zi,date[i].luna);

      if(date[i].zi > 9 && date[i].luna > 9)
        printf("%d-%d\n",date[i].zi,date[i].luna);
    }
  }


  // for(i = 0; i < n; i++){   -> Citire veche
  //   scanf("%s",s);
  //   if(s[0] == '0'){
  //     strncpy(s2,s+1,2);
  //     date[i].zi = atoi(s2);
  //   }else{
  //     strncpy(s2,s,2);
  //     date[i].zi = atoi(s2);
  //   }
  //   if(s[3] == '0'){
  //     strncpy(s2,s+4,2);
  //     date[i].luna = atoi(s2);
  //   }else{
  //     strncpy(s2,s+3,2);
  //     date[i].luna = atoi(s2);
  //   }
  // }

  // while(ok){
  //   ok = 0;
  //   for(i = 0;i < n-1; i ++){
  //     if(date[i].luna > date[i+1].luna){
  //       aux = date[i+1];
  //       date[i+1] = date[i];
  //       date[i] = aux;
  //       ok = 1;
  //     }
  //     if(date[i].luna == date[i+1].luna){
  //       if(date[i].zi > date[i+1].zi){
  //         aux = date[i+1];
  //         date[i+1] = date[i];
  //         date[i] = aux;
  //         ok = 1;
  //       }
  //     }
  //   }
  //
  // }

  // for(i = 0; i < n; i++){
  //   if(date[i].zi != date[i+1].zi || date[i].luna != date[i+1].luna){
  //     if(date[i].zi < 10 && date[i].luna < 10)
  //       printf("0%d-0%d\n",date[i].zi,date[i].luna);
  //     else if(date[i].zi < 10)
  //       printf("0%d-%d\n",date[i].zi,date[i].luna);
  //     else if(date[i].luna < 10)
  //       printf("%d-0%d\n",date[i].zi,date[i].luna);
  //     else
  //       printf("%d-%d\n",date[i].zi,date[i].luna);
  //   }
  // }
  return 0;
}
