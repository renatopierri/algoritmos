#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"
#include "Teste_unitario/CuTest.h"
#include "Teste_unitario/Testes_Calculadora.h"

#define DEBUG 0
/*
Tenenbaum 1.1.5
Escreva funcoes em C, add, subtract e multiply, que leiam duas strings
de Os e ls representando inteiros nao-negativos binarios, e imprima  a
string representando a soma, a diferenca e o produto, respectivamente.

Este codigo implementa controle de erro de soma e subtracao de numeros
positivos e negativos, como um opcional.

Este codigo apresenta resultados validos cujo resultados estejam entre
os valores de -127 a +128.

Este código comentado esta no site https://nets-nuts.com.br.
No caminho  Notas de aulas -> Estruturas de dados usando C
*/

//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();
//Suite de testes

int main(){
int le_dado();
int le_dado(char word[]);
int eerro;
int erro_1=1, erro_2=1;
static char valor_1[9],
            valor_2[9],
            soma_resultado[10],
            sub_resultado[10],
            mult_resultado[10];

//  DEBUG == 1: Debug | DEBUG == 0: Operacao normal
    if (DEBUG == 0){
        while(1){
            while(erro_1 == 1||erro_2 == 1){
                printf("digite o primeiro valor binario de ate 8 bits\n");
                erro_1 = le_dado(valor_1);
                printf("digite o segundo valor binario de ate 8 bits\n");
                erro_2 = le_dado(valor_2);
                if(erro_1 == 1 || erro_2==1){
                   printf("valor invalido, digite novamente todos os valores\n") ;
                   Sleep(3000);
                   system("cls");
                   erro_1 = 1;
                   erro_2 = 1;
                }
            }

            printf("Resultados validos entre -128 ate +127 - 10000000 ate 01111111\n\n");

            strcpy(soma_resultado,soma(valor_1, valor_2));
            printf ("Operacao de soma\n");
            printf("Resultado     =   %s\n",
                   &(soma_resultado[strlen (soma_resultado)-8]));
            eerro = verifica_erro(soma_resultado);
            printf("Erro de soma ----------: %d\n\n",eerro);

            strcpy (sub_resultado, subtrai(valor_1, valor_2));
            printf("Operacao de subtracao\n");
            printf ("Resultado     =   %s\n",
                    &(sub_resultado[strlen (sub_resultado) - 8]));
            eerro = verifica_erro(sub_resultado);
            printf("Erro de subtracao -----: %d\n\n",eerro);

            strcpy(mult_resultado, multiplica(valor_1, valor_2));
            printf("Operacao de multiplicacao\n");
            printf ("Multiplicacao =   %s\n",
                    &(mult_resultado[strlen (mult_resultado)-8]));
             eerro = verifica_erro(mult_resultado);
             printf("Erro de multiplicacao nao foi implementado.\n"
                    "Apresenta resultados validos somente entre -128 e +127\n\n");

            system("pause");
            system("cls");
            erro_1=1;
        }
    }else{
        RunAllTests();
    }
return 0;
}



