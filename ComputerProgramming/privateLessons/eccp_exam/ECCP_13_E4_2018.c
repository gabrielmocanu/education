#include <stdio.h>

typedef struct Student{
  char nume[100];
  char prenume[100];
  int timp;
}student;

int main(){
  // Varianta fara typedef: -> struct Student stud1; struct Student stud[100];

  int n;
  scanf("%d",&n);

  student v[50];
  int barem;
  int nrElevi = 0; // cati elevi au trecut baremul
  int i;

  for(i = 0;i < n;i++){
    scanf("%s %s %d",v[i].nume,v[i].prenume,&v[i].timp); // operator (->)
  }
  scanf("%d",&barem);

  for(i = 0;i < n; i++){
    if(v[i].timp <= barem){
      nrElevi++;
    }
  }
  printf("%d\n",nrElevi);

  student aux;
  int ok = 1;
  while(ok){
    ok = 0;
    for(i = 0;i < n-1; i++){

      if(v[i].timp > v[i+1].timp){
          aux = v[i];
          v[i] = v[i+1];
          v[i+1] = aux;
          ok = 1;
      }
    }
  }

  for(i = 0; i < n; i++){
    if(v[i].timp <= barem){
      printf("%s %s %d\n",v[i].nume,v[i].prenume,v[i].timp);
    }
  }

  return 0;
}
