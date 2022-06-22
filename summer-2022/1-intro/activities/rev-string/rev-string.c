/*

Write a function revString(char*) which reverses the parameter cstring.  The function returns nothing.  You may use C++ string handling functions in <cstring> in the function if you wish.

*/
#include <stdio.h>
#include <string.h>

void revString(char* ptr);

int main()
{
    char s[10] = "abcde";
    revString(s);  // call the function
    printf("%s\n", s);
    return 0;
}

void revString(char* ptr)
{
  char m;
  int i, n;
  n = strlen(ptr);
  for(i = 0; i < n/2; i++){
      m = ptr[i];
      ptr[i] = ptr[n-i-1];
      ptr[n-i-1] = m;
  }
}