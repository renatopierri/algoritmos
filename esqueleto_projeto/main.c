#include <stdio.h>
#include <stdlib.h>
#include "Teste_unitario/Teste_Mediana_121a.h"
#include "Teste_unitario/CuTest.h"
#include "funcoes.h"

/*
Exercício 1.2.1 a.
A mediana de um vetor de números é o elemento m do vetor, tal  que  metade  dos
números restantes no vetor é maior ou igual a m e metade é menor ou igual a  m,
se o número de elementos no vetor for ímpar. Se o número de elementos for  par,
a mediana será a média dos  dois  elementos,  m1  e  m2,  tal  que  metade  dos
elementos restantes é maior ou igual a ml  e  m2,  e  metade  dos  elementos  é
menor ou igual a m1 e m2. Escreva uma função  em  C  que  aceite  um  vetor  de
números e retorne a mediana dos números no vetor.

Fonte: Estruturas de Dados Usando C - Tenembaum.

Autor da solução: Renato de Pierri
nets-nuts.com.br

*/
//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();

int main()
{
    int debug =1;
    int continuo = 1;
    do{
        if(debug == 0){

            printf("Hello world!\n");
            system("pause");
            system("cls");

        }else{
            RunAllTests();
            printf("testes\n");
            system("pause");
            system("cls");
        }
    }while(continuo == 1);

return;

}
