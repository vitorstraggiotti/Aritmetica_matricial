/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Arquivo de cabeçalho para realizar operações com numeros racionais          *
 *                                                                             *
 * Estado: Funcionando parcialmente (bug: não realiza simplificação negativa   *
 * Data de teste: 17/12/2019                                                   *
 *                                                                             *
 * Estado: Funcionando                                                         *
 * Data: 07/04/2020                                                            *
 *                                                                             *
 * Autor: Vitor Henrique Andrade Helfensteller Straggiotti Silva               *
 * Iniciado em: 04/09/2019                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct tRacional{
  long int Numerador;
  long int Denominador;
};

/******************************************************************************/
//imprime valor da fração
void print_fracao(struct tRacional A);

//retorna a fração simplificada passada como argumento
struct tRAcional simplicar(struct tRacional A);

//retorna o calculo da soma de duas frações
struct tRacional soma_fracao(struct tRacional A, struct tRacional B);

//retorna o calculo da multiplicação de duas frações
struct tRacional multiplica_fracao(struct tRacional A, struct tRacional B);

//retorna o calculo da divisão de duas frações (A/B)
struct tRacional divide_fracao(struct tRacional A, struct tRacional B);

//retorna o calculo da subtração de duas frações (A-B)
struct tRacional subtracao_fracao(struct tRacional A, struct tRacional B);

/******************************************************************************/
void print_fracao(struct tRacional A){
  printf("%li / %li", A.Numerador, A.Denominador);
}
//-----------------------------------------------------------------------------
struct tRacional simplificar(struct tRacional A){
  //decomposição em fatores primos
  long int PrimosNumerador[50];
  long int PrimosDenominador[50];
  unsigned int Divisor=2, ContadorNumerador=0, ContadorDenominador=0;
  struct tRacional Resultado = A;

  while(1){ //criando vetor de primos do numerador
    if((Resultado.Numerador % Divisor) == 0){
      Resultado.Numerador = Resultado.Numerador / Divisor;
      PrimosNumerador[ContadorNumerador] = Divisor;
      ContadorNumerador++;
      Divisor--;
    }
    Divisor++;
    if((Resultado.Numerador == 1) || (Resultado.Numerador == -1))
      break;
  }

  Divisor = 2;
  while(1){ //criando vetor de primos do denominador
    if((Resultado.Denominador % Divisor) == 0){
      Resultado.Denominador = Resultado.Denominador / Divisor;
      PrimosDenominador[ContadorDenominador] = Divisor;
      ContadorDenominador++;
      Divisor--;
    }
    Divisor++;
    if((Resultado.Denominador == 1) || (Resultado.Denominador == -1))
      break;
  }

  //comparação e cancelamento de fatores primos comuns
  for(int i=0; i<ContadorNumerador; i++){
    for(int j=0; j<ContadorDenominador; j++){
      if(PrimosNumerador[i] == PrimosDenominador[j]){
        PrimosNumerador[i] = 1;
        PrimosDenominador[j] = 1;
      }//fim do if
    }//fim do for j
  }//fim do for i

  //montando resultado baseado nos vetores de primos
  for(unsigned int i=0; i<ContadorNumerador; i++){
    Resultado.Numerador = Resultado.Numerador * PrimosNumerador[i];
  }
  for(unsigned int j=0; j<ContadorDenominador; j++){
    Resultado.Denominador = Resultado.Denominador * PrimosDenominador[j];
  }
  return Resultado;
}
//-----------------------------------------------------------------------------
struct tRacional soma_fracao(struct tRacional A, struct tRacional B){
  struct tRacional Resultado;

  Resultado.Numerador = (B.Denominador * A.Numerador) + (A.Denominador * B.Numerador);
  Resultado.Denominador = A.Denominador * B.Denominador;
  Resultado = simplificar(Resultado);

  return Resultado;
}
//-----------------------------------------------------------------------------
struct tRacional subtracao_fracao(struct tRacional A, struct tRacional B){
  struct tRacional Resultado;

  Resultado.Numerador = (B.Denominador * A.Numerador) - (A.Denominador * B.Numerador);
  Resultado.Denominador = A.Denominador * B.Denominador;
  Resultado = simplificar(Resultado);

  return Resultado;
}
//-----------------------------------------------------------------------------
struct tRacional multiplica_fracao(struct tRacional A, struct tRacional B){
  struct tRacional Resultado;

  Resultado.Numerador = A.Numerador * B.Numerador;
  Resultado.Denominador = A.Denominador * B.Denominador;
  Resultado = simplificar(Resultado);

  return Resultado;
}
//-----------------------------------------------------------------------------
struct tRacional divide_fracao(struct tRacional A, struct tRacional B){
  struct tRacional Resultado;

  Resultado.Numerador = A.Numerador * B.Denominador;
  Resultado.Denominador = A.Denominador * B.Numerador;
  Resultado = simplificar(Resultado);

  return Resultado;
}
//------------------------------------------------------------------------------
