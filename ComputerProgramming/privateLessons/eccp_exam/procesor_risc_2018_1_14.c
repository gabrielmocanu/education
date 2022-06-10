#include <stdio.h>
#include <string.h>


int main(){

	char op[10]; // operatia pe care noi o citim
	int reg1,reg2,reg3; // variable pe care noi le citim
	int reg[16]; // registrii
	int n; // numarul de linii
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%s",op);
		if( strcmp(op,"lconst") == 0){
			scanf("%d",&reg1);
			scanf("%d",&reg2);
			reg[reg1] = reg2;
		}else if(!strcmp(op,"print")){
			scanf("%d",&reg1);
			printf("%d\n",reg[reg1]);
		}else if(!strcmp(op, "add")){
			scanf("%d",&reg1);
			scanf("%d",&reg2);
			scanf("%d",&reg3);
			reg[reg1] = reg[reg2] + reg[reg3];
		}else if(!strcmp(op, "mul")){
			scanf("%d",&reg1);
			scanf("%d",&reg2);
			scanf("%d",&reg3);
			reg[reg1] = reg[reg2] * reg[reg3];
		}else if(!strcmp(op, "div")){
			scanf("%d",&reg1);
			scanf("%d",&reg2);
			scanf("%d",&reg3);
			if(reg[reg3] == 0){
				printf("Exception: line %d\n",i+1);
				break;
			}
			reg[reg1] = reg[reg2] / reg[reg3];
		}
	}

	return 0;
}
