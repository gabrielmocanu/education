#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct Numar{
  char judet[100];
  char nr[100];
  char personal[100];
}Numar;

int main(int argc, char const *argv[]) {

  Numar numere[100];
  int i = 0;
  int j = 0;
  char judete[100][100] = { "AB" , "BR", "B", "SV" };
  int ok;
  while(scanf("%s %s %s\n",numere[i].judet,numere[i].nr,numere[i].personal) != EOF){

    for(j = 0; j < 4; j++)
    {
      if(strcmp(numere[i].judet,judete[j]) == 0)
      {
        ok = 1;
        break;
      }
      else
      {
        ok = 0;
      }
    }

    if(ok == 0)
    {
      continue;
    }


    if(strlen(numere[i].nr) == 3 || strlen(numere[i].nr) == 2)
    {
      for(j = 0;j < strlen(numere[i].nr); j++)
      {
        if(numere[i].nr[j] >= 48 && numere[i].nr[j] <= 57)
        {
          ok = 1;
        }
        else
        {
          ok = 0;
          break;
        }
      }
    }
    else
    {
      ok = 0;
    }

    if(ok == 0)
    {
      continue;
    }

    if(strlen(numere[i].personal) == 3)
    {
      for(j = 0; j < strlen(numere[i].personal); j++)
      {
        if(numere[i].personal[j] >= 65 && numere[i].personal[j] <= 90)
        {
          ok = 1;
          break;
        }
        else
        {
          ok = 0;
        }
      }
    }
    else
    {
      ok = 0;
    }

    if(ok == 0)
    {
      continue;
    }

    printf("%s %s %s\n",numere[i].judet, numere[i].nr, numere[i].personal);

    i++;
  }

  return 0;
}
