#include <stdio.h>

int menuInicial(){

	int op;

	printf("1 - SOMA\n2 - SUBTRACAO\n3 - MULTIPLICACAO\n4 - DIVISAO\n");
	scanf("%d",&op);

	return op;
}

float soma(float a, float b){

	return a + b;
}

float subtracao(float a, float b){

	return a - b;
}

float multiplicacao(float a, float b){

	return a * b;
}

float divisao(float a, float b){

	return a / b;
}

int main(){

	int opmenu = 0;
	float a, b, res;

	scanf("%f",&a);
	scanf("%f",&b);

	opmenu = menuInicial();

	switch(opmenu){
		case 1: {
			res = soma(a, b);
			break;
		}
		case 2: {
			res = subtracao(a, b);
			break;
		}
		case 3: {
			res = multiplicacao(a, b);
			break;
		}
		case 4: {
			res = divisao(a, b);
			break;
		}
		default:{
			printf("Opcao Invalida");
			break;
		}
	}

	printf("%f", res);

	return 0;
}	
