#include <stdio.h>
#include <string.h>

int main(){

	int n;
	scanf("%d",&n);

	int v[1000];
	int i;

	for(i = 0 ; i < n;i++){
		scanf("%d",&v[i]);
	}

	int s;
	scanf("%d",&s);

	int ok = 1;
	int aux;

	while(ok == 1){
		ok = 0;
		for(i = 0; i < n; i++){
			if(v[i] > v[i+1]){
				aux = v[i+1];   // aux = v[i]
				v[i+1] = v[i]; // v[i] = v[i+1]
				v[i] = aux;  // v[i+1] = aux
				ok = 1;  // ok = 1
			}
		}
	}

	// Cautarea binara
	ok = 1;
	int mid = 0;

	int left = 1;
	int right = n;

	mid = (left + right)/2;

	while(ok){
		if(s == v[mid]){
			// printf("mid = %d\n",mid);
			printf("%d\n",v[mid]);
			ok = 0;
		}else if(s < v[mid]){
			// printf("mid = %d\n",mid);
			printf("%d\n",v[mid]);

			right = mid;
			if((left + right) % 2 != 0){
				mid =(left + right)/2 + 1;
			}else{
				mid = (left + right)/2;
			}

		}else{
			// printf("mid = %d\n",mid);
			printf("%d\n",v[mid]);
			left = mid;
			if((left + right) % 2 != 0){
				mid =(left + right)/2 + 1;
			}else{
				mid = (left + right)/2;
			}
		}

		if(right - left <= 1){
			ok = 0;
		}
	}

	return 0;
}
