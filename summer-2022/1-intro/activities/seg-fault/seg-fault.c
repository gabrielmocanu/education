#include <stdio.h>
#include<stdlib.h>

/*

Find and eliminate all code that generates Segmentation Fault

*/

int main() {
	char **s;
	s = malloc(sizeof(char*));
	char foo[] = "Hello World";
	// printf("%p\n", s);
	*s = foo;
	printf("s is %s\n",s);
	printf("s is %p\n",s);
	s[0] = foo;

	printf("s[0] is %s\n",s[0]);
		return(0);
}

