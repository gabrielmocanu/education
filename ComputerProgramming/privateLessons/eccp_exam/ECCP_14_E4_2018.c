#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n",&n);

  int i;
  int ok = 1;
  int nrImpare = 0;
  int aux;
  int retin;
  int fr[10]; // vector de frecventa
  int numar[100]; // retin palindromul maxim
  int j = 0;


  int v[100];
  for(i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }

  while(ok){
    ok = 0;
    for(i = 0;i < n-1; i++){
      if(v[i] < v[i+1]){
        aux = v[i+1];
        v[i+1] = v[i];
        v[i] = aux;
        ok = 1;
      }
    }
  }

  for(i = 0 ;i < 10; i++){
    fr[i] = 0; // vector de frecventa
  }

  for(i = 0;i < n; i++){
    fr[v[i]]++; // calculeaza cat de des apare fiecare cifra
  }

  for(i = 0;i < 10; i++){
    if(fr[i] % 2 == 1)
    {
      nrImpare++; // calculez numarul de aparitii impare al cifrelor
      retin = i; // retin ce numar e impar
    }
  }

  if(nrImpare > 1){
    printf("0\n");
  }else if(nrImpare == 1){

    for(i = 0; i < n/2; i++){
      numar[i] = v[j];
      numar[n-i-1] = v[j];
      j = j + 2;
      if(v[j] == retin)
        j++;
    }
    numar[n/2] = retin;

    for(i = 0 ;i < n; i++){
      printf("%d",numar[i]);
    }
    printf("\n");

  }else{

    for(i = 0; i < n/2; i++){
      numar[i] = v[j];
      numar[n-i-1] = v[j];
      j = j + 2;
    }

    for(i = 0 ;i < n; i++){
      printf("%d",numar[i]);
    }
    printf("\n");
  }
  return 0;
}
