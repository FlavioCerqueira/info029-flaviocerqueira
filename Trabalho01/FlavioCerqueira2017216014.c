// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Flávio Silva Cerqueira
//  email: fsilvacerqueira@gmail.com
//  Matrícula: 2017216014
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    char dd[3], mm[3], aaaa[5];
  int Dia, Mes, Ano, i, j, datavalida, bissexto;

  for(i=0;data[i]!='/';i++)//Quebra a string e converte para inteiro - ano, mês e dia
    dd[i] = data[i];
  Dia = atoi(dd);
  for(i=i+1,j=0;data[i]!='/';i++,j++)
    mm[j] = data[i];
  Mes = atoi(mm);
  for(i=i+1,j=0;data[i]!='\0';i++,j++)
    aaaa[j] = data[i];
  Ano = atoi(aaaa);
  if(Ano>=0&&Ano<=18)
    Ano = Ano + 2000;
  if(Ano>=19&&Ano<=99)
    Ano = Ano + 1900; 

  if(Ano%4==0)//Calcula se o ano é bissexto ou regular
    bissexto = 1;
  else 
    bissexto = 0;
    if((bissexto)&&(Ano%100!=0))
      bissexto = 1;
    else if(Ano%400==0)
           bissexto = 1;
         else
           bissexto = 0;

  if((Dia>31||Dia<1)||(Mes>12||Mes<1)||Ano<0)
    return 0;
  else
    datavalida = 1;
  if(datavalida && Mes==4||Mes==6||Mes==9||Mes==11)
    if(Dia>30)
      return 0;
    else 
      datavalida = 1;
  if(datavalida && Mes==2)
    if(bissexto&&Dia<=29)
      datavalida = 1;
    else
      return 0;
    
  if(datavalida)
    return 1; 
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    
    int qtdOcorrencias = 0, i;

    if(isCaseSensitive!=1){
      if(c>='a'&&c<='z')
        c = c - 'a' + 'A';
  for(i=0;texto[i]!='\0';i++){
    if(texto[i]>='a'&&texto[i]<='z')
      texto[i] = texto[i] - 'a' + 'A';
    if(texto[i]==c)
      qtdOcorrencias++; 
  } 
    }
    else
      for(i=0;texto[i]!='\0';i++)
        if(texto[i]==c)
          qtdOcorrencias++;
    
    return qtdOcorrencias;
        
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
   
   int qtdOcorrencias=0;
   int i,j,l,x,y,count=0,count2=0,count3=0;
    
    x=y=j=l=0;

    if(strlen(strBusca)==1){
        for(i=0;strTexto[i]!='\0';i++){
            if(strTexto[i]==strBusca[0])
                count++;
        }
        return count;
    }

    for(i = 0;strTexto[i]!='\0'; i++){
        count=0;
    if(strTexto[i]==-70 || strTexto[i]==-77 || strTexto[i]==-83 || strTexto[i]==-87 || strTexto[i]==-89 || strTexto[i]==-93 || strTexto[i]==-95)
       count3++;
        if(strTexto[i] == strBusca[j]){
            for(x=i+1,l=j+1;strBusca[l]==strTexto[x];x++,l++)
                count++;
        }
        if(count==strlen(strBusca)-1){
            posicoes[y++]=(i+1)-count3;
            posicoes[y++]=x-count3;
            qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
	int aux, inversao = 0;

    while(num>0){
      aux = num%10;
      inversao = inversao * 10 + aux;  
      num /= 10;
    }
   num = inversao;

   return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias=0, aux, divisor=1, resto;

    aux = numerobusca;
      while(aux>0){
        aux = aux/10;
        divisor *= 10;
      }
      while(numerobase>0){
        resto = numerobase%divisor;
        if(resto==numerobusca)
          qtdOcorrencias++;
        numerobase /= 10;
      }

    return qtdOcorrencias;
}