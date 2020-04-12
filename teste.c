//teste de Biblioteca para aritimetica matricial racional

#include"matriz.h"

#define DIMENSAO    3

int main(void){
  struct tRacional **MatrizResposta;
  struct tRacional **Matriz_A;
  struct tRacional **Matriz_B;

  //Alocação de memoria
  Matriz_A = (struct tRacional**)malloc(DIMENSAO * sizeof(struct tRacional*));
  Matriz_B = (struct tRacional**)malloc(DIMENSAO * sizeof(struct tRacional*));
  for(int i=0; i<DIMENSAO; i++){
    Matriz_A[i] = (struct tRacional*)malloc(DIMENSAO * sizeof(struct tRacional));
    Matriz_B[i] = (struct tRacional*)malloc(DIMENSAO * sizeof(struct tRacional));
  }//fim de for i

  //Atribuindo valores para as matrizes A
  Matriz_A[0][0].Numerador = 2;            Matriz_A[0][1].Numerador = 1;     Matriz_A[0][2].Numerador = 3;
  Matriz_A[0][0].Denominador = 3;          Matriz_A[0][1].Denominador = 3;   Matriz_A[0][2].Denominador = 7;

  Matriz_A[1][0].Numerador = 3;            Matriz_A[1][1].Numerador = 5;     Matriz_A[1][2].Numerador = 7;
  Matriz_A[1][0].Denominador = 7;          Matriz_A[1][1].Denominador = 9;   Matriz_A[1][2].Denominador = 8;

  Matriz_A[2][0].Numerador = 3;            Matriz_A[2][1].Numerador = 9;     Matriz_A[2][2].Numerador = 6;
  Matriz_A[2][0].Denominador = 2;          Matriz_A[2][1].Denominador = 7;   Matriz_A[2][2].Denominador = 4;

  //Atribuindo valores para as matrizes B
  Matriz_B[0][0].Numerador = 1;            Matriz_B[0][1].Numerador = 3;     Matriz_B[0][2].Numerador = 3;
  Matriz_B[0][0].Denominador = 7;          Matriz_B[0][1].Denominador = 8;   Matriz_B[0][2].Denominador = 5;

  Matriz_B[1][0].Numerador = 5;            Matriz_B[1][1].Numerador = 13;    Matriz_B[1][2].Numerador = 7;
  Matriz_B[1][0].Denominador = 3;          Matriz_B[1][1].Denominador = 9;   Matriz_B[1][2].Denominador = 13;

  Matriz_B[2][0].Numerador = 9;            Matriz_B[2][1].Numerador = 7;     Matriz_B[2][2].Numerador = 4;
  Matriz_B[2][0].Denominador = 21;         Matriz_B[2][1].Denominador = 8;   Matriz_B[2][2].Denominador = 5;

  //imprimindo matrizes
  printf("Matriz A:\n");
  print_matriz(Matriz_A, DIMENSAO);
  printf("Matriz B:\n");
  print_matriz(Matriz_B, DIMENSAO);

  //Soma de matrizes
  printf("A + B :\n");
  MatrizResposta = soma_matriz(Matriz_A, Matriz_B, DIMENSAO);
  print_matriz(MatrizResposta, DIMENSAO);

  //Subtração de matrizes
  printf("A - B :\n");
  MatrizResposta = subtracao_matriz(Matriz_A, Matriz_B, DIMENSAO);
  print_matriz(MatrizResposta, DIMENSAO);

  //Multiplicação de matrizes
  printf("A * B :\n");
  MatrizResposta = multiplicacao_matriz(Matriz_A, Matriz_B, DIMENSAO);
  print_matriz(MatrizResposta, DIMENSAO);


  //Desalocação de memoria
  for(int i=0; i<DIMENSAO; i++){
    free(Matriz_A[i]);
    free(Matriz_B[i]);
    free(MatrizResposta[i]);
  }//fim de for i
  free(Matriz_A);
  free(Matriz_B);
  free(MatrizResposta);

  return 0;
}
