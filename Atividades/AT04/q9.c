#include <stdio.h>

struct Cliente
{
	char nome[50], cpf[12], dataNascimento[11], sexo;

};

void cadastrarCliente(struct Cliente *cliente);
int validarNome(char *nomeCliente);

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

	int nomeValidado;

	fgets((*cliente).nome, 50, stdin);
	setbuf(stdin, NULL);
	fgets((*cliente).cpf, 12, stdin);
	setbuf(stdin, NULL);
	fgets((*cliente).dataNascimento, 11, stdin);
	setbuf(stdin, NULL);
	scanf(" %c",&(*cliente).sexo);

	nomeValidado = validarNome((*cliente).nome);


	printf("%d\n",nomeValidado);
}

int validarNome(char *nomeCliente){

	int tam = 0, i;
	int retorno;

	for(i=0;nomeCliente[i]!='\0';i++)
		tam += 1;

	if(tam<=12)
		retorno = 1;
	else
		retorno = 0;

	return retorno;
}
