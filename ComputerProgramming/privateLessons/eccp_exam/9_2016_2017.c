#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Echipa
{
    char Nume[100];
    int nrPuncte;
    int NrGoluriInscrise;
    int NrGoluriPrimite;
}Echipa;

int main(int argc, char const *argv[]) {

  int n,k;
  scanf("%d\n",&k);
  scanf("%d\n",&n);
  Echipa echipa[k];
  char echipa1[100];
  char echipa2[100];
  int nrGol1;
  int nrGol2;
  int nrEchipe = 0;
  int ok = 0;

  for(int i = 0; i < k; i++)
  {
    echipa[i].nrPuncte = 0;
    echipa[i].NrGoluriInscrise = 0;
    echipa[i].NrGoluriPrimite = 0;
  }

  int index1;
  int index2;

  for(int i = 0; i < n; i++)
  {
    scanf("%s %d - %d %s\n",echipa1,&nrGol1,&nrGol2,echipa2);

    ok = 0;
    for(int j = 0; j < k; j++)
    {
        if(!strcmp(echipa1,echipa[j].Nume))
        {
          ok  = 1; // l-am citit, nu mai citesc acest nume
        }
    }
    if(ok == 0) // trebuie sa citesc
    {
      strcpy(echipa[nrEchipe].Nume,echipa1);
      nrEchipe++;
    }

    ok = 0;
    for(int j = 0; j < k; j++)
    {
        if(!strcmp(echipa2,echipa[j].Nume))
        {
          ok  = 1;
        }
    }
    if(ok == 0)
    {
      strcpy(echipa[nrEchipe].Nume,echipa2);
      nrEchipe++;
    }


    for(int j = 0; j < nrEchipe; j++)
    {

      if(!strcmp(echipa1, echipa[j].Nume))
      {
        echipa[j].NrGoluriInscrise += nrGol1;
        echipa[j].NrGoluriPrimite += nrGol2;
        index1 = j;
      }


      if(!strcmp(echipa2, echipa[j].Nume))
      {
        echipa[j].NrGoluriPrimite += nrGol1;
        echipa[j].NrGoluriInscrise += nrGol2;
        index2 = j;
      }

    }

    if(nrGol1 > nrGol2)
    {
      echipa[index1].nrPuncte += 3;
    }else if(nrGol1 == nrGol2)
    {
      echipa[index1].nrPuncte += 1;
      echipa[index2].nrPuncte += 1;
    }else
    {
      echipa[index2].nrPuncte += 3;
    }

  }

  Echipa aux;
  int i,j;
    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k-1;j++){
            if(echipa[j].nrPuncte<echipa[j+1].nrPuncte){
                aux=echipa[j];
                echipa[j]=echipa[j+1];
                echipa[j+1]=aux;
            }
        }
    }


  for(int i = 0; i < k; i++)
  {
    printf("%s %d %d %d\n",echipa[i].Nume,echipa[i].nrPuncte,echipa[i].NrGoluriInscrise,echipa[i].NrGoluriPrimite);
  }

  return 0;
}
