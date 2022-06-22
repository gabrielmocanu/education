/* 

Write a piece of code which prints the characters in a cstring in a reverse order.

*/

#include <stdio.h>
#include <string.h>
int main() {
    int i, n;
    char s[10] = "abcde";
    char m;
    n = strlen(s);
    for(i = 0; i < n/2; i++){
        m = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = m;
    }
    printf("%s\n", s);

    return 0;
}