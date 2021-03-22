#include <stdio.h>

float subtraiValores(float a, float b, float c);

int main(){

	float a, b, c, resultado;

	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);

	resultado = subtraiValores(a, b, c);

	printf("%f", resultado);

	return 0;
}

float subtraiValores(float a, float b, float c){

	float resultado;

	resultado = a - b - c;

	return resultado;
}