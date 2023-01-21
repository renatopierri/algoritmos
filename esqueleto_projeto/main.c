#include <stdio.h>
#include <stdlib.h>
#include "Teste_unitario/Teste_Mediana_121a.h"
#include "Teste_unitario/CuTest.h"
#include "funcoes.h"

/*
Exerc�cio 1.2.1 a.
A mediana de um vetor de n�meros � o elemento m do vetor, tal  que  metade  dos
n�meros restantes no vetor � maior ou igual a m e metade � menor ou igual a  m,
se o n�mero de elementos no vetor for �mpar. Se o n�mero de elementos for  par,
a mediana ser� a m�dia dos  dois  elementos,  m1  e  m2,  tal  que  metade  dos
elementos restantes � maior ou igual a ml  e  m2,  e  metade  dos  elementos  �
menor ou igual a m1 e m2. Escreva uma fun��o  em  C  que  aceite  um  vetor  de
n�meros e retorne a mediana dos n�meros no vetor.

Fonte: Estruturas de Dados Usando C - Tenembaum.

Autor da solu��o: Renato de Pierri
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
