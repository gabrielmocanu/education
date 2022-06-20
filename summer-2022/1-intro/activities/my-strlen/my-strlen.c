/*

Write a function myStrLen(char*) which returns the length of the parameter cstring.  Write the function without using the C++ function strlen.

*/
#include<stdio.h>

int myStrLen(char* a){
    int len;
    len = 0;
    while(*a){
        len++;
        a++;
    }
    return len;
}

int main(){
    char s[200] = {0};
    scanf("%s", s);
    printf("%d\n", myStrLen(s));
}