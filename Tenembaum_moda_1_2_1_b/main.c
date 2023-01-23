#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "Teste_unitario/Teste_Moda_121b.h"
/*
Exerc�cio 1.2.1 b.
A MODA de um vetor de n�meros � o n�mero m no vetor que �  repetido  com  maior
freq��ncia. Se mais de um n�mero for repetido com freq��ncia m�xima igual,  n�o
existir� uma moda. Escreva uma fun��o em C que aceite um  vetor  de  n�meros  e
retorne a moda ou uma indica��o de que a moda n�o existe.

Fonte: Estruturas de Dados Usando C - Tenembaum, pg53 - 54.

Autor da solu��o: Renato de Pierri
https://nets-nuts.com.br

Para simplificar, ao inves de inserir manualmente os valores no array optei por
gerar automaticamente os valores do array.

Essa funcao "calcula_moda" faz o calculo apenas de numeros positivos.
Caso a serie nao tenha um valor para a moda, a funcao retornara o valor "-1".

funcoes.h tem as configuracoes da aplicacao e de teste, conforme abaixo:

QUANTIDADE: Nr de elementos na serie.
DADOS:      Nr de dados que serao gerados aleatoriamente para calcular a moda.
DEBUG:      0 - Operacao normal, 1 - Modo de testes.
CONTINUO:   0 - Roda uma vez,    1 - Modo continuo.

//Parametros de teste
#define ITENS 5     - Numero de itens a serem gerados.
#define TAMANHO 100 - N�mero de valores da serie a serem analisados.
*/

int main(){

    int limite, tamanho_valores, moda = 0;
    int valores[QUANTIDADE]={0};
    moda--;
    limite = QUANTIDADE - 1;
    tamanho_valores = sizeof(valores)/sizeof(int);
    do{
        if(DEBUG == 0){
            gera_aleatorio(valores,tamanho_valores,DADOS);
            moda = calcula_moda(valores,limite);
            zera_valores(valores,tamanho_valores);
        }else{
            printf("Rodando testes\n");
            RunAllTests();
            system("pause");
        }
    }while(CONTINUO == 1);
    return 0;
}
