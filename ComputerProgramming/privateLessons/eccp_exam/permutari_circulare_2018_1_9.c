#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

	int numar;
	int v[1000];

	int n;
	scanf("%d",&n);

	int max = n;
	int m = 0; // numarul de biti
	int ultim;
	int i,j;

	while(n/2 != 0){
		v[m] = n % 2;
		n = n/2;
		m++;
	}

	v[m] = n % 2;
	m++;
	
	for( i = 0; i < m; i++){

		// permutarea
		ultim = v[m-1];
		for( j = m-1;j > 0; j--){
			v[j] = v[j-1];
		}
		v[0] = ultim;

		numar = 0;
		for(j =0; j < m; j++){
			numar = numar + v[j]*pow(2,j);
		}

		if(numar > max)
			max = numar;
	}

	printf("%d\n",max);

	return 0;
}
