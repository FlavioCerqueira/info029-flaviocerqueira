
// Nome: Flávio Silva Cerqueira
// Matrícula: 2017201614  
// Análise e Desenvolvimento de Sistemas
// Disciplina: INFO029 - Laboratório de Programação

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int menu();
void inserirVetor();
void excluirVetor();
void listar();
void listarAllOrdenado();
void listarAllElementosOrdenado();
void aumentarVetor();
void liberaMemoria();


struct principal {
    int *vetorStruct;
    int qtd_vetor;
    int qtd_aux;
};
typedef struct principal PRIN;


int main() {
    PRIN vetor[10];
    int op, i;
    int sair = 0;

    
    for(i = 0; i < 10; i++) {
        vetor[i].vetorStruct = NULL;
    }
    for(i = 0; i < 10; i++) {
        vetor[i].qtd_vetor = 0;
    }
    for(i = 0; i < 10; i++) {
        vetor[i].qtd_aux = 0;
    }


    while (!sair) {
        op = menu();
        
        switch (op) {
            case 0: {
                liberaMemoria(&vetor);
                sair = 1;
                break;
            }
            case 1: {     
                inserirVetor(&vetor);
                break;
            }

            case 2: { 
                excluirVetor(&vetor);
                break;
            }
            case 3: {
                listar(&vetor);
                break;
            }
            case 4: {
                listarAllOrdenado(&vetor);
                break;
            }
            case 5: {
                listarAllElementosOrdenado(&vetor);
                break;
            }
            case 6: {
                aumentarVetor(&vetor);
                break;
            }
            default: {
                printf("OPCAO INVALIDA.\n");
            }
        }
    }

    printf("\n");
    
    return 0;
}

int menu() {
    int op;

    printf("\n\n");
    printf("\tDigite a opcao desejada\n");
    printf("\t0 - Sair\n");
    printf("\t1 - Inserir elemento\n");
    printf("\t2 - Excluir elemento\n");
    printf("\t3 - Listar todos os elementos de todas as estruturas\n");
    printf("\t4 - Listar todos os elementos de todas as estruturas ordenados\n");
    printf("\t5 - Listar todos os elementos ordenados\n");
    printf("\t6 - Aumentar tamanho da estrutura auxiliar\n");
        scanf("%d", &op);
        printf("\n");
    return op;
}

void inserirVetor(PRIN *estrutura) {
    int indice_Struct, entradaPos, tam_User, verifica, entradaStructAux, entradaElemento;


    printf("Informe em qual posicao deseja inserir (0-9): ");
        scanf("%d", &entradaPos);

    if (entradaPos >= 0 && entradaPos <= 9) {
        verifica = estrutura[entradaPos].qtd_vetor;

        if(estrutura[entradaPos].vetorStruct == NULL) {
            printf("Informe qual tamanho da estrutura auxiliar: ");
                scanf("%d", &entradaStructAux);
            estrutura[entradaPos].vetorStruct = (int *) malloc (entradaStructAux * sizeof(int)); //!Aloca o vetor auxiliar
            estrutura[entradaPos].qtd_aux = entradaStructAux; //!Quantidade do auxiliar
        }
        
        printf("Informe o elemento a ser inserido: ");
            scanf("%d", &entradaElemento);
        estrutura[entradaPos].vetorStruct[verifica] = entradaElemento; 
        
        if (verifica == estrutura[entradaPos].qtd_aux) { //!Verifica se a struct tem espaço
            puts("Estrutura cheia.");
        } else { //Caso tenha espaço, verifica = TRUE = +1
            verifica++;
            estrutura[entradaPos].qtd_vetor = verifica;
        }

    } else {
        puts("Posicao nao foi encontrada.");
    }
}

void excluirVetor(PRIN *estrutura) {
    int del, op, i, j, aux;

    printf("Informe em qual estrutura haverá a remocao: ");
        scanf("%d", &op);

    if(op >= 0 && op <= 9) {
        printf("Informe o elemento a ser removido: ");
        scanf("%d", &del);

        for(i = 0; i < estrutura[op].qtd_aux; i++) {
            if(estrutura[op].vetorStruct[i] == del) {
                aux = i;
                estrutura[op].vetorStruct[i] = 0;
                break;
            }
        }
    estrutura[op].qtd_vetor -= 1;

    printf("%d\n", aux);

        for(i = aux; estrutura[op].qtd_aux - 1; i++) {
            estrutura[op].vetorStruct[i] = estrutura[op].vetorStruct[i + 1];
        }
        estrutura[op].vetorStruct[i] = 0;
    } else {
        puts("Posicao nao encontrada.");
    }

}

void listar(PRIN *estrutura) {
    int i, j;

    system("clear");

    for(i = 0; i < 10; i++) {
        for(j = 0; j < estrutura[i].qtd_aux; j++) {
            printf("Estrutura numero: %d\n", i);
            printf("Estrutura auxiliar: %d\n", j);
            printf("Elemento: %d\n", estrutura[i].vetorStruct[j]);
            printf("\n----------------------------\n");
        }
        printf("\n");
    }
}

void listarAllOrdenado(PRIN *estrutura) {
    PRIN auxOrdena[10]; //!Struct auxiliar para ordenação
    int i, j, k, aux, auxTam[10];

    system("clear");

    for( i = 0; i < 10; i++) {
        auxTam[i] = estrutura[i].qtd_aux;
    }

    for( i = 0; i < 10; i++) {
        auxOrdena[i].vetorStruct = (int *) malloc (auxTam[i] * sizeof(int));
    }

    for(i = 0; i < 10; i++) {
        if(estrutura[i].qtd_aux != 0) { 
            for(j = 0; j < estrutura[i].qtd_aux; j++) {
                auxOrdena[i].vetorStruct[j] = estrutura[i].vetorStruct[j];
            }
        }
    }

    for(i = 0; i < 10; i++) {
        if(estrutura[i].qtd_aux != 0) { 
            for(j = 0; j < estrutura[i].qtd_aux; j++) {
                for(k = j + 1; k < estrutura[i].qtd_aux; k++) {
                    if(auxOrdena[i].vetorStruct[j] > auxOrdena[i].vetorStruct[k]) {
                        aux = auxOrdena[i].vetorStruct[j];
                        auxOrdena[i].vetorStruct[j] = auxOrdena[i].vetorStruct[k];
                        auxOrdena[i].vetorStruct[k] = aux;
                    }
                }
            }
        }
    }

    for(i = 0; i < 10; i++) {
        printf("Estrutura auxiliar: %d", i);
        for(j = 0; j < auxTam[i]; j++) {
            if(auxOrdena[i].vetorStruct[j] != 0) {
                printf("\nElemento: %d\n", auxOrdena[i].vetorStruct[j]);
                printf("\n----------------------------\n");
            }
        }
        printf("\n");
    }
}

void listarAllElementosOrdenado(PRIN *estrutura) {
    int *vetAux, countOrdem = 0, todosElementos = 0, i, j, aux;

    system("clear");

    for(i = 0; i < 10; i++) { 
        if(estrutura[i].qtd_aux != 0) {
            countOrdem += estrutura[i].qtd_vetor;
        }
    }

    if(countOrdem > 0) { 
        vetAux = (int *) malloc (countOrdem * sizeof (int));
    }

    for(i = 0; i < 10; i++) {
        if(estrutura[i].qtd_aux != 0) {
            for(j = 0; j < estrutura[i].qtd_vetor; j++) {
                vetAux[todosElementos] = estrutura[i].vetorStruct[j];
                todosElementos += 1;
            }
        }
    }
    
    if(todosElementos == 0) {
        printf("Nenhum elemento iniciado.\n");
    } else {
        for(i = 0; i < countOrdem; i++){ 
            for(j = i+1; j < countOrdem; j++){
                if(vetAux[i] > vetAux[j]){
                    aux = vetAux[i];
                    vetAux[i] = vetAux[j];
                    vetAux[j] = aux;
                }
            }
        }
    }
    
    for(i = 0; i < todosElementos; i++) {
        printf("Elemento %d: %d\n", i, vetAux[i]);
    }

    printf("Tamanho: %d\n", todosElementos);

    free(vetAux);

}

void aumentarVetor(PRIN *estrutura) {
    int op, tam;

    printf("Informe a estrutura auxiliar que sera aumentada: \n");
        scanf("%d", &op);

    if(op >= 0 && op <= 9) {
        printf("Informe a quantidade a ser aumentada: \n");
            scanf("%d", &tam);

        if(tam > 0) {
            estrutura[op].vetorStruct = (int *) realloc (estrutura[op].vetorStruct, tam * sizeof(int));
            estrutura[op].qtd_aux += tam;
        } else {
            puts("Nao foi possivel aumentar a auxiliar.");
        }
    } else {
        puts("Nao foi encontrada a posicao");
    }

}

void liberaMemoria(PRIN *estrutura) {
    
    for(int i = 0; i < 10; i++) {
        free(estrutura[i].vetorStruct);
    }

    puts("FIM DO PROGRAMA!");

}