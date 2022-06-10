#include <stdio.h>
#include <string.h>

int main(){

	int n,k;
	float min = 999;
	int p[100];
	int v[100];
	int i;
	scanf("%d",&n);
	scanf("%d",&k);
	float t[100];

	for(i = 0; i < k; i++){
		scanf("%d %d",&p[i],&v[i]);
	}

	for(i = 0; i < k; i++){
		t[i] = (float)(n-p[i])/v[i];
	}

	for(i = 0; i < k; i++){
		if(t[i] < min)
			min = t[i];
	}

	for(i = 0; i < k; i++){
		if(t[i]==min)
			printf("%d ",i+1);
	}

	return 0;
}
