#include<stdio.h>
#include<string.h>

int main() {

	int p,s;
	scanf("%d",&p);
	scanf("%d",&s);
	char partide[100][100];
	int scor[100][100];
	int crescator = 0; // variabila care ne spune daca sirul de sondaje e crescator sau nu
	int maxDif = 0; // retinem diferenta maxima pana la un moment dat
	int index; // retinem indexul unde se intampla asta (nr partidului)
	int i;
	int j;
	int nrPartideCrescatoare = 0;

	for(i = 0; i < p; i++){
		scanf("%s",partide[i]);
		for(j = 0; j < s; j++){
			scanf("%d",&scor[i][j]);
		}
	}

	for(i = 0; i < p; i++){
		for(j = 0;j < s-1;j ++){
			if(scor[i][j+1] < scor[i][j])
				crescator = 1;
		}
		if(crescator == 0){
			printf("%s ",partide[i]);
			nrPartideCrescatoare++;
		}
		crescator = 0;
	}

	if(nrPartideCrescatoare == 0){
		printf("Nu exista");
	}

	for(i = 0;i < p; i++){
		if(maxDif < (scor[i][s-1] - scor[i][0])){
			maxDif = (scor[i][s-1] - scor[i][0]);
			index = i;
		}
	}

	printf("\n%s", partide[index]);
	printf("%d%%\n",maxDif);

	return 0;
}
