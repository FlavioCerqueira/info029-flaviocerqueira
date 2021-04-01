#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dma{

    int dia, mes, ano;

} Data;

typedef struct {

    char nome[50], cpf[12], sexo, matricula[10];
    Data data_nascimento;

} Fichaaluno;

typedef struct {

    char nome[50], cpf[12], sexo, matricula[10];
    Data data_nascimento;

} Fichaprofessor;

typedef struct {

    char nome[50], codigo[10], professor[20];
    int semestre;

} Fichadisciplina;

void flush();

Fichaaluno cadastraAluno();

Fichaprofessor cadastraProfessor();

Fichadisciplina cadastraDisciplina();

void listarAlunos();

void listarProfessores();

void listarDisciplinas();

int menuInicial();

int gerenciarAlunos();

void atualizarAluno();

int menuRelatorio();

int main(){
    
    int sair = 0, opcao, qtdAlunos = 0, submenu, qtdProfessores = 0, qtdDisciplnas = 0, i = 0;
    int menuAlunos;
    Fichaaluno alunos[10];
    Fichaprofessor professores[10];
    Fichadisciplina disciplinas[10];


    while(!sair){
        
        opcao = menuInicial();
        
        switch(opcao){
            
            case 1:{
                    alunos[qtdAlunos] = cadastraAluno();
                    qtdAlunos++;
                break;
            }
            case 2:{
                    professores[qtdProfessores] = cadastraProfessor();
                    qtdProfessores++;
                break;
            }
            case 3:{
                    disciplinas[qtdDisciplnas] = cadastraDisciplina();
                    qtdDisciplnas++;
                break;
            }
            case 4:{
                    submenu = menuRelatorio();
                    
                    switch(submenu){
                        
                        case 1:{
                                listarAlunos(alunos, qtdAlunos);
                            break;
                        }
                        case 2: {
                                listarProfessores(professores, qtdProfessores);
                            break;
                        }
                        case 3: {
                        		listarDisciplinas(disciplinas, qtdDisciplnas);
                        		break;
                        }
                    }
                break;
            } 
            case 5:{
            	menuAlunos = gerenciarAlunos();

            	switch(menuAlunos){

            		case 1: {
            			atualizarAluno(alunos, qtdAlunos);
            			break;
            		}
            	}
            	//CHAMAR FUNÇÃO GERENCIAR ALUNOS -> INICIAR SUBFUNÇÕES DE GERENCIAMENTO DE ALUNOS
            	break;
            }

            //CHAMAR FUNÇÃO EMITIR RELATÓRIO; -> INICIAR SUBFUNCOES DE RELATORIOS
            case 6:{
                printf("\n| PROJETO ESCOLA FINALIZADO |\n\n");
                sair = 1;
                break;
            }
        }
    }
    
    return 0;
}

void flush() {
    //funçao excelente para limpar o buffer de entrada.
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != EOF && ch != '\n' ) {}
}

Fichaaluno cadastraAluno(){

    Fichaaluno aluno;
    
    flush();
    printf("NOME COMPLETO: ");
    fgets(aluno.nome,50,stdin);
    setbuf(stdin, NULL);
    printf("MATRICULA: ");
    fgets(aluno.matricula, 20, stdin);
    setbuf(stdin, NULL);
    printf("CPF: ");
    fgets(aluno.cpf, 12, stdin);
    setbuf(stdin, NULL);
    printf("SEXO: ");
    scanf(" %c",&aluno.sexo);
    setbuf(stdin, NULL);
    printf("DIA DO NASCIMENTO: ");
    scanf("%d",&aluno.data_nascimento.dia);
    printf("MES DO NASCIMENTO: ");
    scanf("%d",&aluno.data_nascimento.mes);
    printf("ANO DO NASCIMENTO: ");
    scanf("%d",&aluno.data_nascimento.ano);

    printf("\n| ALUNO CADASTRADO |\n\n");

    return aluno;
}

Fichaprofessor cadastraProfessor(){

    Fichaprofessor professor;

    flush();
    printf("NOME COMPLETO: ");
    fgets(professor.nome, 50, stdin);
    setbuf(stdin, NULL);
    printf("MATRICULA: ");
    fgets(professor.matricula, 10, stdin);
    setbuf(stdin, NULL);
    printf("CPF: ");
    fgets(professor.cpf, 12, stdin);
    setbuf(stdin, NULL);
    printf("SEXO: ");
    scanf("%c",&professor.sexo);
    setbuf(stdin, NULL);
    printf("DIA DO NASCIMENTO: ");
    scanf("%d",&professor.data_nascimento.dia);
    printf("MES DO NASCIMENTO: ");
    scanf("%d",&professor.data_nascimento.mes);
    printf("ANO DO NASCIMENTO: ");
    scanf("%d",&professor.data_nascimento.ano);

    printf("\n|  PROFESSOR CADASTRADO  |\n");

    return professor;
}

Fichadisciplina cadastraDisciplina(){

    Fichadisciplina disciplina;
  
    setbuf(stdin, NULL);
    printf("INFORME O NOME DA DISCIPLINA: ");
    fgets(disciplina.nome, 50, stdin);
    setbuf(stdin, NULL);
    printf("INFORME O CODIGO DA DISCIPLINA: ");
    fgets(disciplina.codigo, 10, stdin);
    setbuf(stdin, NULL);
    printf("NOME DO PROFESSOR: ");
    fgets(disciplina.professor, 20, stdin);
    setbuf(stdin, NULL);
    printf("SEMESTRE: ");
    scanf("%d",&disciplina.semestre);

    printf("\n|  DISCIPLINA CADASTRADA  |\n");

    return disciplina;
}

int menuInicial(){
    
    int opcao;
    
    printf("MENU INICIAL\nDIGITE A OPCAO DESEJADA:\n1 - CADASTRAR ALUNO\n2 - CADASTRAR PROFESSOR\n3 - CADASTRAR DISCIPLINA");
    printf("\n4 - EMITIR RELATORIO\n5 - GERENCIAR ALUNOS\n6 - SAIR\nDigite o numero da opcao:  ");
    scanf("%d",&opcao);
    
    return opcao;
}

void listarAlunos(Fichaaluno *alunos, int qtdAlunos){

    int i;
    
    for(i=0; i<qtdAlunos; i++){
        printf("NOME DO ALUNO: %s", alunos[i].nome);
        printf("CPF DO ALUNO: %s", alunos[i].cpf);
        printf("\nMATRICULA DO ALUNO: %s", alunos[i].matricula);
        printf("SEXO DO ALUNO: %c", alunos[i].sexo);
        printf("\nDATA DE NASCIMENTO: %d/%d/%d\n\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
    }
}

void listarProfessores(Fichaprofessor *professores, int qtdProfessores){

    int i;

    for(i=0; i<qtdProfessores; i++){
        printf("NOME DO PROFESSOR: %s", professores[i].nome);
        printf("CPF DO PROFESSOR: %s", professores[i].cpf);
        printf("\nMATRICULA DO PROFESSOR: %s", professores[i].matricula);
        printf("SEXO DO PROFESSOR: %c", professores[i].sexo);
        printf("DATA DE NASCIMENTO: %d/%d/%d\n", professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
    }
}

void listarDisciplinas(Fichadisciplina *disciplinas, int qtdDisciplnas){

	int i;

	for(i=0;i<qtdDisciplnas;i++){
		printf("CODIGO DA DISCIPLINA: %s", disciplinas[i].codigo);
		printf("NOME DA DISCIPLINA: %s", disciplinas[i].nome);
		printf("NOME DO PROFESSOR: %s", disciplinas[i].professor);
		printf("SEMESTRE: %d\n\n", disciplinas[i].semestre);
	}
}

void atualizarAluno(Fichaaluno *alunos, int qtdAlunos){

	int i;
	char chaveBusca[10];

	setbuf(stdin, NULL);
	printf("INFORME O NUMERO DA MATRÍCULA: ");
	fgets(chaveBusca, 10, stdin);
	
	for(i=0;i<qtdAlunos;i++){
		if (strstr(chaveBusca, alunos[i].matricula) != 0 ){
			printf("NOME DO ALUNO: %s\n", alunos[i].nome);
			// INLCUIR CAMPOS PARA ALTERAÇÃO
		}
	}
}

int menuRelatorio(){

    int opcao;

    printf("1 - LISTAR ALUNOS\n2 - LISTAR PROFESSORES\n3 - LISTAR DISCIPLINAS\n4 - LISTAR UMA DISCIPLINA\n5 - LISTAR ALUNOS POR SEXO\n6 - LISTAR ALUNOS POR NOME");
    printf("\n7 - LISTAR ALUNOS POR DATA DE NASCIMENTO\n8 - LISTAR PROFESSORES POR SEXO\n9 - LISTAR PROFESSORES POR NOME\n10 - LISTAR PROFESSORES POR NASCIMENTO");
    printf("\nDigite o numero da opcao: ");
    scanf("%d",&opcao);

    return opcao;
}

int gerenciarAlunos(){

	int opcao;

	printf("1 - ATUALIZAR DADOS DO ALUNO\n2 - INCLUIR EM UMA DISCIPLINA\n3 - EXCLUIR ALUNO");
	printf("\nDigite o numero da opcao: ");
	scanf("%d",&opcao);

	return opcao;
}