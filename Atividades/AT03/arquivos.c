#include <stdio.h>
#include "precoTotal.h"

int main(){

	int qtd;
	float precoUnitario, valoCarrinho;

	scanf("%d",&qtd);
	scanf("%f",&precoUnitario);

	valoCarrinho = precoTotal(qtd, precoUnitario);

	printf("%f", valoCarrinho);
	
	return 0;
}