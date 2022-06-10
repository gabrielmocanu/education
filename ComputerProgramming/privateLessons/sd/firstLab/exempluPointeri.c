#include <stdio.h>

int  main(int argc, char const *argv[]) {

  int a = 5;
  int *p;

  p = &a;
  printf("Valoarea lui a este %d\n",a);
  printf("Valoarea lui a este %d\n",*p);
  printf("a se afla in memorie la adresa %p\n",p);
  printf("a se afla in memorie la adresa %p\n",&a);
  return 0;
}
