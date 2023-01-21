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

Fonte: Estruturas de Dados Usando C - Tenembaum, pg53.

Autor da solução: Renato de Pierri
https://nets-nuts.com.br/calculando-a-mediana-tenembaum-1-2-1-a/

Para simplificar a solução, ao inves de inserir os valores no array, optei  por
gerar automaticamente os valores do array.

*/
//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();

int main()
{
    int debug =0;
    int continuo = 1;
    int mediana_10[10];
    int mediana_11[11];
    double mediana;
    int controle;

    do{
        if(debug == 0){

            printf("Calcula mediana de 10 elementos.\n\n");
            printf("Aqui a mediana eh a media entre o quinto e sexto elemento do array.\n");
            printf("Gerando um array de 10 elementos inteiros.\n");

            gera_aleatorio(mediana_10,10);

            printf("Classificando o array de 10 elementos.\n");

            mediana = classifica(mediana_10,10);

            printf("Imprimindo o array de 10 elementos, classificado.\n");
            for(controle = 0;controle<=9;controle++){
              printf("%i, ", mediana_10[controle])  ;
            }
            printf("\n");
            printf("A mediana eh: %.01f.\n\n\n",mediana);

            printf("Calcula mediana de 11 elementos.\n\n");
            printf("Aqui a mediana eh o sexto elemento do array.\n");
            printf("Gerando um array de 11 elementos inteiros.\n");

            gera_aleatorio(mediana_11,11);

            printf("Classificando o array de 11 elementos.\n");

            mediana = classifica(mediana_11,11);

            printf("Imprimindo o array de 11 elementos, classificado.\n");
            for(controle = 0;controle<=10;controle++){
              printf("%i, ", mediana_11[controle])  ;
            }
            printf("\n");
            printf("A mediana eh: %.01f.\n\n",mediana);

            system("pause");
            system("cls");

        }else{
            RunAllTests();
            system("pause");
            system("cls");
        }
    }while(continuo == 1);
return 0;
}
