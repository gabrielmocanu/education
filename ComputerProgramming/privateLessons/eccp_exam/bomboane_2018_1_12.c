#include <stdio.h>
#include <string.h>

int main(){

	int n;
	scanf("%d",&n);
	int v[1000];
	int i;
	for(i = 0; i < n; i++){
		scanf("%d",&v[i]);  // v[i] -> suma de bani pentru ziua i+1
	}
	int sum = 0; // suma de bani pe care o are Andrei
	int pret; // pret produs
	int aroma; // fericirea pe care o aduce bomboana respectiva
	int fericire = 0; // suma fericrii pe care o are Andrei
	int maxAroma = 0; // aroma maxima pe care a cumparat-o Andrei pana la un anumit mom de timp

	for(i = 0; i < n; i++){
		 sum = sum + v[i];
		 scanf("%d",&pret);
		 scanf("%d",&aroma);

		 if(sum >= pret){
			sum = sum - pret;
			fericire = fericire + aroma;
			if(maxAroma < aroma)
				maxAroma = aroma;
		 }else{
			if(maxAroma < aroma){
				fericire = fericire - aroma;
			}
		}
	}

	printf("%d\n",fericire);
	return 0;
}
