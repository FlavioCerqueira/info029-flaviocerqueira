#include <stdio.h>

void ler3numeros(int *vetor, int a);

int main(){

	int i, vetor[3], n=3;

	ler3numeros(vetor, n);

	for(i=0;i<n;i++)
		printf("%d ",vetor[i]);

	return 0;
}

void ler3numeros(int *vetor, int a){

	int i;

	for(i=0;i<a;i++)
		scanf("%d",&vetor[i]);
}