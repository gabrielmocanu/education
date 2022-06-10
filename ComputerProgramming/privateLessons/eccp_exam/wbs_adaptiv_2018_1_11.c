#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

	int n;
	scanf("%d",&n);
	int b;
	scanf("%d",&b);
	int msg[1024];
	int i,j,k;
	for(i = 0; i < n; i++){
		scanf("%d",&msg[i]);
	}

	int msg0[4000]; // sir codat 0
	int msg1[4000]; // sir codat 1
	int ok0 = 0;
	int ok1 = 0;

	int curentLen0 = 0; // lungimea sirului codat cu 0
	int curentLen1 = 0; // lungimea sirului codat cu 1

	for( i = 0;i < n; i+=b){
		for( j = i; j < i+b && j < n; j++){
			if(msg[j] == 1)
				ok0 = 1;
		}

		if(ok0 == 1 || j < i + b) {
			ok0 = 0;
			msg0[curentLen0] = 1;
			curentLen0++;
			for(k = i; k < i+b && k<n; k++){
				msg0[curentLen0] = msg[k];
				curentLen0++;
			}
		}
		else{
			msg0[curentLen0] = 0;
			curentLen0++;
		}
	}

	// for(int i = 0; i < curentLen0; i++){
	// printf("\n");
	// 	printf("%d ",msg0[i]);
	// }
	//

	for(i = 0;i < n; i+=b){
		for(j = i; j < i+b && j < n; j++){
			if(msg[j] == 0)
				ok1 = 1;
		}

		if(ok1 == 1 || j < i + b) {
			ok1 = 0;
			msg1[curentLen1] = 0;
			curentLen1++;
			for(k = i; k < i+b && k < n; k++){
				msg1[curentLen1] = msg[k];
				curentLen1++;

			}
		}
		else{

			msg1[curentLen1] = 1;
			curentLen1++;
		}
	}

	// for(int i = 0; i < curentLen1; i++){
	// 	printf("%d ",msg1[i]);
	//
	// }
	//
	// printf("\n");


	double comp0 = (double)n/(curentLen0+1);
	double comp1 = (double)n/(curentLen1+1);
	comp0 = roundf(comp0*100)/100;
	comp1 = roundf(comp1*100)/100;


	if(comp0 >= comp1){
		printf("%.2f\n",comp0);
		printf("0\n");
		for(int i = 0;i < curentLen0; i++){
			printf("%d\n",msg0[i]);
		}
	}else{
		printf("%.2f\n",comp1);
		printf("1\n");
		for(int i = 0;i < curentLen1; i++){
			printf("%d\n",msg1[i]);
		}
	}

	return 0;
}
