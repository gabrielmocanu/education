#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persoana{

  char *nume;
  int varsta;
  struct persoana *next;

}persoana;

void AdaugarePrimaPozitie(persoana **cap, int varsta, char *nume)
{
  persoana *noua_persoana = (persoana *)malloc(sizeof(persoana));
  noua_persoana -> nume = (char *)malloc(20*sizeof(char));
  noua_persoana -> varsta = varsta;

  strcpy(noua_persoana->nume,nume);

  noua_persoana -> next = (*cap);
  (*cap) = noua_persoana;
}

void AdaugareUltimaPozitie(persoana **cap, int varsta, char *nume)
{
  persoana *noua_persoana = (persoana *)malloc(sizeof(persoana));
  persoana *ultima_persoana = *cap;

  noua_persoana -> nume = (char *)malloc(20*sizeof(char));
  noua_persoana -> varsta = varsta;

  strcpy(noua_persoana->nume,nume);

  noua_persoana -> next = NULL;
  if(*cap == NULL)
  {
    *cap = noua_persoana;
  }

  while(ultima_persoana -> next != NULL)
  {
    ultima_persoana = ultima_persoana -> next;
  }

  ultima_persoana -> next = noua_persoana;
}

void AfiseazaLista(persoana *lista)
{
  persoana *pers = lista;

  while(pers != NULL)
  {
    printf("%s cu varsta de %d\n",pers->nume,pers->varsta);
    pers = pers -> next;
  }

}

void StergePrimaPozitie(persoana **cap)
{
  persoana *prima_persoana = *cap;
  *cap = prima_persoana -> next;
  free(prima_persoana);
}

void StergeUltimaPozitie(persoana **cap)
{
  persoana *ultima_persoana = *cap;
  persoana *auxiliara;

  while(ultima_persoana -> next != NULL)
  {
    auxiliara = ultima_persoana;
    ultima_persoana = ultima_persoana -> next;
  }
  free(auxiliara->next);
  auxiliara->next = NULL;
}

int main(int argc, char const *argv[]) {

  persoana *cap = NULL;

  AdaugarePrimaPozitie(&cap,10,"Andreea");
  AdaugarePrimaPozitie(&cap,4,"Andrei");
  AdaugareUltimaPozitie(&cap,14,"Tibi");
  AdaugarePrimaPozitie(&cap,15,"Gabi");
  StergePrimaPozitie(&cap);
  StergeUltimaPozitie(&cap);

  AfiseazaLista(cap);
  return 0;
}
