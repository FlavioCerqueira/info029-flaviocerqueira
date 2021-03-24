#include <stdio.h>

void ler3Palavras(char *palavra, int n);

int main(){

	char palavra1[50], palavra2[50], palavra3[50];
	int n = 50;

	ler3Palavras(palavra1, n);
	ler3Palavras(palavra2, n);
	ler3Palavras(palavra3, n);

	puts(palavra1);
	puts(palavra2);
	puts(palavra3);

	return 0;
}

void ler3Palavras(char *palavra, int n){

	scanf("%s",&palavra);

}