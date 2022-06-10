#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elev{
	char name[30];
	int varsta;
	int note[2];
}Elev;


int main(int argc, char *argv[]){

	FILE *f = fopen(argv[1],"wb+");	
	
	Elev v[10];
	int n = 6;

	fwrite(&n,sizeof(int),1,f);


	strcpy(v[0].name, "Andrei");
	v[0].varsta = 12;
	v[0].note[0] = 10;
	v[0].note[1] = 10;

	strcpy(v[1].name, "Maria");
	v[1].varsta = 12;
	v[1].note[0] = 9;
	v[1].note[1] = 8;

	strcpy(v[2].name, "Claudiu");
	v[2].varsta = 15;
	v[2].note[0] = 8;
	v[2].note[1] = 5;

	strcpy(v[3].name, "Claudia");
	v[3].varsta = 14;
	v[3].note[0] = 5;
	v[3].note[1] = 10;

	strcpy(v[4].name, "Gabi");
	v[4].varsta = 18;
	v[4].note[0] = 6;
	v[4].note[1] = 10;

	strcpy(v[5].name, "George");
	v[5].varsta = 18;
	v[5].note[0] = 8;
	v[5].note[1] = 10;


	fwrite(v, sizeof(Elev), 6, f);
	
	fclose(f);


	return 0;
}
