#include <stdio.h>

float somarValores(float a, float b);

int main(){

float resultado, a, b;

scanf("%f",&a);
scanf("%f",&b);

resultado = somarValores(a, b);

printf("%f", resultado);

	return 0;
}

float somarValores(float a, float b){

	float resultado;

	resultado = a + b;

	return resultado;
}