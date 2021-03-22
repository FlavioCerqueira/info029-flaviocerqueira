#include <stdio.h>

int fatorialNumero(int a);

int main(){

	int n, resultado;

	scanf("%d",&n);

	if(n<=0)
		printf("IMPOSSÍVEL CALCULAR");
	else{
		resultado = fatorialNumero(n);
		printf("%d", resultado);
	}

	return 0;
}

int fatorialNumero(int a){

	int fat;

	for(fat=1; a>1; a = a-1)
		fat *= a;

	return fat;
}
