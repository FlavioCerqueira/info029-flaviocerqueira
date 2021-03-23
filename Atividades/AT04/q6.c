#include <stdio.h>

void ler3Letras(char *letras, int n);

int main(){

	char letras[3]; 
	int i, n = 3;

	ler3Letras(letras, n);

	for(i=0;i<n;i++)
		printf("%c ",letras[i]);

	return 0;
}

void ler3Letras(char *letras, int n){

	int i;

	for(i=0;i<n;i++)
		scanf(" %c",&letras[i]);
}