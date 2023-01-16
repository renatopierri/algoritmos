#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "Teste_unitario/CuTest.h"
#include "Teste_unitario/Testes_bin_3_bin.h"

/*
Escreva um programa C para ler uma string de 0s e 1s representando  um  inteiro
positivo em notacao binaria e imprima uma string de 0s, 1s e 2s representando o
mesmo numero em notacao ternaria (veja o exercicio anterior). Escreva outro pro
grama C para ler um numero ternario e imprimir o equivalente em notacao binaria

Fonte: Tenembaum, Estrutura de dados usando C, ex 1.1.7, pg33.
Autor da soulucao: Renato de Pierri - nets-nuts.com.br
*/

//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();
//Suite de testes

int main()
{
    int debug;
    int check1,check2=1;

    char entrada_binaria[9];
    char result_ternario[7];

    char entrada_ternaria[7];
    char result_binario[9];

//  debug = 0; //roda os testes unitarios
//  debug = 1; //operacao normal

    debug = 1;

    if (debug){
        do{
            printf("Entre com valor binario de ate 8 bits\n");
            check1 = 0;
            check1 = le_dado(entrada_binaria,BINARIO);
            alinha_direita(entrada_binaria,BINARIO);
            if(check1 == 0){
                printf("Dado binario ok: %s\n", entrada_binaria);

            }else{
                printf("Dado binario inconsistente\n\n");
            }

            printf("Entre com valor ternario de ate 6 ternos\n");
            check2 = 0;
            check2 = le_dado(entrada_ternaria,TERNARIO);
            alinha_direita(entrada_ternaria,TERNARIO);
            if(check2 == 0){
                printf("Dado ternario ok: %s\n\n", entrada_ternaria);
            }else{
                printf("Dado ternario inconsistente\n\n");
            }
            if((check1==1)|(check2==1)){
                printf("Dados inconsistentes.\n"
                       "Entrar com os dados novamente.\n\n");
            }else{
                representaTernario(entrada_binaria, result_ternario);
                printf("Conversao de binario %s para ternario: %s\n\n",
                       entrada_binaria, result_ternario);

                representaBinario(entrada_ternaria, result_binario);
                printf("Conversao de ternario: %s para binario: %s\n\n",
                       entrada_ternaria, result_binario);
            }
            system("pause");
            system("cls");

        }while ((check1==1)|(check2==1));
    }else{
        RunAllTests();
    }
    return 0;
}
