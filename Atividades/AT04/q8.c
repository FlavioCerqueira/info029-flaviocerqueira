#include <stdio.h>

struct Cliente
{
	char nome[50], cpf[12], dataNascimento[11], sexo;

};

void cadastrarCliente(struct Cliente *cliente);

int main(){

	struct Cliente cliente;
	
	cadastrarCliente(&cliente);

	puts(cliente.nome);
	puts(cliente.dataNascimento);
	puts(cliente.cpf);
	printf("%c", cliente.sexo);	

	return 0;
}

void cadastrarCliente(struct Cliente *cliente){

	scanf("%s",&(*cliente).nome);
	scanf("%s",&(*cliente).cpf);
	scanf("%s",&(*cliente).dataNascimento);
	scanf(" %c",&(*cliente).sexo);
}
