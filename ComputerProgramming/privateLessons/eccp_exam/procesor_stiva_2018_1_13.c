#include <stdio.h>
#include <string.h>

int main(){

	int n;
	scanf("%d",&n);

	char func[100];
	int nrElem = 0;
	int stack[1000];
	int i;
	int ok = 0;
	for(i = 0;i < n ;i++){

		scanf("%s",func);
		if(!strcmp(func,"iload")){ // !strcmp(a,b) == (strcmp(a,b) == 0)
			scanf("%d",&stack[nrElem]);
			nrElem++;
		}

		if(!strcmp(func,"iadd")){
			if(nrElem - 2 < 0){
				ok = 1;
				printf("Exception: line %d\n",i+1);
				break;
			}
			int sum = stack[nrElem-1] + stack[nrElem-2];
			stack[nrElem-2] = sum;
			stack[nrElem-1] = 0;
			nrElem--;
		}

		if(!strcmp(func,"imul")){
			if(nrElem - 2 < 0){
				ok = 1;
				printf("Exception: line %d\n",i+1);
				break;
			}
			int prod = stack[nrElem-1] * stack[nrElem-2];
			stack[nrElem-2] = prod;
			stack[nrElem-1] = 0;
			nrElem--;
		}

		if(!strcmp(func,"dup")){
			stack[nrElem] = stack[nrElem-1];
			nrElem++;
		}
	}

	if(ok == 0){
		printf("%d\n",nrElem);
		for(i = nrElem-1 ; i >= 0; i--){
			printf("%d\n",stack[i]);
		}

	}

	return 0;
}
