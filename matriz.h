/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Biblioteca para realizar operações matriciais                     *
 *                                                                   *
 * Estado: Funcionando (teste realizado com matriz 3x3)              *
 * Data: 07/04/2020                                                  *
                                                                     *
 * Autor: Vitor Henrique Andrade Helfensteller Straggiotti Silva     *
 * Iniciado em: 04/09/2019                                           *
 *                                                                   *
 * NECESSITA DA BIBLIOTECA racional.h PARA CORRETO FUNCIONAMENTO     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include<stdlib.h>
#include<stdio.h>
#include"racional.h"

/********************************************************************************************************************************/
//retorna uma matriz de frações resultante da soma de outras duas matrizes de frações (matrizes de mesmas dimesões)
struct tRacional** soma_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao);

//retorna uma matriz de frações resultante da subtração de outras duas matrizes de frações (matrizes de mesmas dimesões)
struct tRacional** subtracao_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao);

//retorna uma matriz de frações resultante da multiplicação de outras duas matrizes de frações (matrizes de mesmas dimensões)
struct tRacional** multiplicacao_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao);

//realiza a impressão da matriz passada como argumento
void print_matriz(struct tRacional **A, unsigned int Dimensao);

/********************************************************************************************************************************/
struct tRacional** soma_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao){
  struct tRacional **Resposta;
  //Alocação dinamica de memoria
  Resposta = (struct tRacional **)malloc(Dimensao * sizeof(struct tRacional *));
  for(unsigned int i=0; i < Dimensao; i++){
    Resposta[i] = (struct tRacional*)malloc(Dimensao * sizeof(struct tRacional));
  }

  for(unsigned int Linha=0; Linha < Dimensao; Linha++){
    for(unsigned int Coluna=0; Coluna < Dimensao; Coluna++){
      Resposta[Linha][Coluna] = soma_fracao(A[Linha][Coluna], B[Linha][Coluna]);
    }//fim do for coluna
  }//fim do for linha
  return Resposta;
}//fim de função
//==================================================================================================
struct tRacional** subtracao_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao){
  struct tRacional **Resposta;
  //Alocação dinamica de memoria
  Resposta = (struct tRacional**)malloc(Dimensao * sizeof(struct tRacional*));
  for(unsigned int i=0; i<Dimensao; i++){
    Resposta[i] = (struct tRacional*)malloc(Dimensao * sizeof(struct tRacional));
  }

  for(unsigned int Linha=0; Linha < Dimensao; Linha++){
    for(unsigned int Coluna=0; Coluna < Dimensao; Coluna++){
      Resposta[Linha][Coluna] = subtracao_fracao(A[Linha][Coluna], B[Linha][Coluna]);
    }//fim do for coluna
  }//fim do for linha
  return Resposta;
}//fim de função
//=======================================================================================================
struct tRacional** multiplicacao_matriz(struct tRacional **A, struct tRacional **B, unsigned int Dimensao){
  struct tRacional **Resposta;

  //Alocação dinamica de memoria
  Resposta = (struct tRacional**)malloc(Dimensao * sizeof(struct tRacional*));
  for(unsigned int i=0; i<Dimensao; i++){
    Resposta[i] = (struct tRacional*)malloc(Dimensao * sizeof(struct tRacional));
  }//fim de for i

  //Zerando matriz de frações
  for(unsigned int Linha=0; Linha < Dimensao; Linha++){
    for(unsigned int Coluna=0; Coluna < Dimensao; Coluna++){
      Resposta[Linha][Coluna].Numerador = 0;
      Resposta[Linha][Coluna].Denominador = 1;
    }//fim de for coluna
  }//fim de for linha

  //Construindo matriz Resposta da multiplicação
  for(unsigned int Linha=0; Linha < Dimensao; Linha++){
    for(unsigned int Coluna=0; Coluna < Dimensao; Coluna++){
      //para cada valor de linha varremos todos os valores de coluna
      for(unsigned int i=0; i < Dimensao; i++){
        Resposta[Linha][Coluna] = soma_fracao(Resposta[Linha][Coluna], multiplica_fracao(A[Linha][i], B[i][Coluna]));
      }//fim de for i
    }//fim de for coluna
  }//fim de for linha
  return Resposta;
}//fim de função
//======================================================================================================
void print_matriz(struct tRacional **A, unsigned int Dimensao){
  for(unsigned int Linha=0; Linha < Dimensao; Linha++){
    for(unsigned int Coluna=0; Coluna < Dimensao; Coluna++){
      printf("   ");
      printf("(");
      print_fracao(A[Linha][Coluna]);
      printf(")");
    }//fim de for j
    printf("\n");
  }//fim de for i
  printf("\n");
}//fim de função
//----------------------------------------------------------------------------------------------------------------
