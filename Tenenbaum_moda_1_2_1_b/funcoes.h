#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

/*
funcoes.h tem as configuracoes da aplicacao e de teste, conforme abaixo:

QUANTIDADE: Nr de elementos na serie.
DADOS:      Nr de dados que serao gerados aleatoriamente para calcular a moda.
DEBUG:      0 - Operacao normal, 1 - Modo de testes.
CONTINUO:   0 - Roda uma vez,    1 - Modo continuo.

//Parametros de teste
#define ITENS 5     - Numero de itens a serem gerados.
#define TAMANHO 100 - Número de valores da serie a serem analisados.
*/

#define QUANTIDADE 10
#define DADOS 100
#define DEBUG 0
#define CONTINUO 1

#define ITENS 5
#define TAMANHO 100

void gera_aleatorio(int valores[],int tamanho, int quantidade);
void zera_valores(int valores[],int tamanho);
int calcula_moda(int valores[],int limite);

#endif // FUNCOES_H_INCLUDED
