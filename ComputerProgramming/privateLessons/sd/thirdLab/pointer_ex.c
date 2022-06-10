/* Să se realizeze un program ce permite citirea de la tastatură a unui vector cu 10 elemente
numere întregi. Să se afişeze pe ecran adresele de memorie ale elementelor vectorului şi apoi
să se determine suma elementelor acestuia. Operațiile se vor realiza prin intermediul
pointerilor. */

#include <stdio.h>
#include <stdlib.h>
int main()
{
  /* Declarare variabile */
  int V[10], dim, i, suma;
  /* Citire dimensiune vector si verificare */
  do
  {
    printf("Introduceti numarul de elemente ale vectorului: ");
    scanf("%d", &dim);
    if ((dim<1) || (dim>10))
    printf("Numar invalid. Acesta trebuie sa fie intre 1 si 10.\n");
} while ((dim<1) || (dim>10));

  /* Citire vector, element cu element */
  printf("\nCitire valori vector:\n");
  for (i=0; i<dim; i++)
  {
  printf("V[%d] = ", i+1);
  scanf("%d", V+i); // stocare la adresele V+i <-> &V[i]
  }

  /* Afisare adrese de memorie ale elementelor vectorului */
  for (i=0; i<dim; i++)
  printf("Adresa de memorie a elementului de indice %d este: %p\n", i, V+i);

  /* Calcul suma */
  suma=0;
  for (i=0; i<dim; i++)
    suma += *(V+i);
  printf("Suma elementelor vectorului este %d\n", suma);

  return 0;
}
