#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"

//Tenenbaum 1.1.5
//Escreva funcoes em C, add, subtract e multiply, que leiam duas strings
//de Os e ls representando inteiros nao-negativos binarios, e imprima a
//string representando a soma, a diferenca e o produto, respectivamente.
//Nao e escopo desse exercicio implementar controle de erro.
//Controle de erro pode ser implementado como um opcional.
//Este código comentado esta no site https://nets-nuts.com.br
//No caminho  Notas de aulas -> Estruturas de dados usando C

int le_dado();
int le_dado(char word[]);

int main()
{while(1){
    int v1=1,v2=1 ;
    char valor_1[9],
         valor_2[9],
         soma_resultado[10],
         sub_resultado[10],
         mult_resultado[10];
    while(v1 == 1||v2 == 1){
        printf("digite o primeiro valor binario de ate 8 bits\n");
        v1 = le_dado(valor_1);
        printf("digite o segundo valor binario de ate 8 bits\n");
        v2 = le_dado(valor_2);
        if(v1 == 1 || v2==1){
           printf("valor invalido, digite novamente todos os valores\n") ;
           Sleep(3000);
           system("cls");
           v1 = 1;
           v2 = 1;
        }
    }

    printf("Resultados validos entre -128 ate +127 - 10000000 ate 01111111\n\n");
    strcpy(soma_resultado,soma(valor_1, valor_2));
    printf ("Operacao de soma\n");
    printf("Resultado     = %s\n",
           &(soma_resultado[strlen (soma_resultado)-8]));

    printf("Operacao de subtracao\n");
    strcpy (sub_resultado, subtrai(valor_1, valor_2));
    printf ("Resultado     = %s\n",
            &(sub_resultado[strlen (sub_resultado) - 8]));

    printf("Operacao de multiplicacao\n");
    strcpy(mult_resultado, multiplica(valor_1, valor_2));
    printf ("Multiplicacao = %s\n\n",
           &(mult_resultado[strlen (mult_resultado)-8]));

    system("pause");
    system("cls");}
return 0;
}

