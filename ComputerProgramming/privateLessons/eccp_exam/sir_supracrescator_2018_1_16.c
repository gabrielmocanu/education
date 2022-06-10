#include <stdio.h>
#include <string.h>

int main(){

	int n;
	scanf("%d",&n);
	int v[1000];
	for(int i = 0;i < n; i++){
		scanf("%d",&v[i]);
	}

	int sum_cur = 0;

	int nrElems = 0;
	int elems[1000];

	int ok = 0;
	int i;

	for(i = 0; i < n; i++){

		if(v[i] > sum_cur){
			sum_cur = sum_cur + v[i];
		}
		else {
			elems[nrElems] = i+1;
			nrElems++;
			v[i] = sum_cur + 1;
			sum_cur = sum_cur + v[i];
		}
	}

	if(nrElems < 3){
		for(i = 0;i < nrElems; i++){
			if(elems[i] > n/2+1){ // elems[i] -> pozitia unde se afla elementul de schimbat
				ok = 1;
			}
		}
	}else{
		ok = 1;
	}

	printf("%d\n",nrElems);
	for(i = 0;i < nrElems;i++){
		printf("%d\n",elems[i]);
	}

	if(ok == 1)
		printf("Respins\n");
	else
		printf("Acceptat\n");

	return 0;

}
