#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *p;
	int i;
	p = (int *)malloc(10*sizeof(int));

	p[0] = 1;
	p[1] = 3;

	for(i=0;i<10;i++)
	{
		printf("%d ",p[i]);
	}

	printf("\n %d \n",*p);

	p++;

	printf("\n %d \n",*p);

	for(i=0;i<20;i++);
	{
		p++;
	}

		printf("\n %d \n",*p);




	return 0;
}