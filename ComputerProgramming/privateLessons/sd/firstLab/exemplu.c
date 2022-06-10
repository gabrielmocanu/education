#include <stdio.h>

typedef struct 
{
	int x,y;
}punct;

int main(int argc, char const *argv[])
{
	punct a;
	a.x = 5;
	a.y = 0;

	printf("x este %d\n",a.x);
	return 0;
}