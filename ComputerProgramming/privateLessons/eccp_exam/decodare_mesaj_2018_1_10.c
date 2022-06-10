#include<stdio.h>
#include<string.h>

int main(){

	char mapare[100] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'
		,'T','U','V','W','X','Y','Z'};

	char msg[10240];

	scanf("%s",msg);
	int cifra1; // prima cifra pe care o interpretez
	int cifra2; // a doua cifra
	int numar; // in aceasta variabila formam numarul
	int i = 0;
	while(i < strlen(msg)){

		cifra1 = msg[i] - '0';
		cifra2 = msg[i+1] - '0';
		numar = cifra1*10+cifra2;

		if(numar > 26 || i == strlen(msg)-1){
			numar = cifra1;
			printf("%c",mapare[numar]);
			i++;
		}else{
			printf("%c",mapare[numar]);
			i = i + 2;
		}
	}

	printf("\n");
	return 0;
}
