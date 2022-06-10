#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elev{
	char name[30];
	int varsta;
	int note[2];
}Elev;


void calculeazaMedie(float *medii, Elev *v, int n){

	for(int i = 0; i < n; i++){
		medii[i] = ((float)v[i].note[0] + (float)v[i].note[1])/2;
	}
}

int main(int argc, char *argv[]){

	FILE *f = fopen(argv[1],"rb");	
	
	Elev v[10];
	int n;

	fread(&n, sizeof(int), 1,f);
	fread(v, sizeof(Elev), 6, f);	

	fclose(f);
	
	for(int i = 0; i < n; i++){
		printf("%s %d %d %d\n",v[i].name,v[i].varsta,v[i].note[0],v[i].note[1]);
	}

	float *medii = malloc(n*sizeof(float));

	calculeazaMedie(medii, v, n);

	for(int i = 0;i < n; i++){
		printf("%f\n", medii[i]);
	}
	
	fclose(f);

	FILE *fout = fopen(argv[2],"w+");

	for(int i = 0;i < n; i++){
		fprintf(fout,"%f\n", medii[i]);
	}
	

	fclose(fout);

	return 0;
}
