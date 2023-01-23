#ifndef FUNCOES_C_INCLUDED
#define FUNCOES_C_INCLUDED

#include <stdlib.h>
#include "funcoes.h"
#include "Teste_unitario/CuTest.h"
#include "Teste_unitario/Teste_Moda_121b.h"

void gera_aleatorio(int valores[],int tamanho, int quantidade){
    int controle;
    int temp;
    for(controle = 0;controle<quantidade;controle++){
        temp = rand() % tamanho;
        valores[temp]=(valores[temp])+1;
    }
}

void zera_valores(int valores[],int tamanho){
    int controle;
    for (controle = 0;controle<tamanho;controle++){
        valores[controle] = 0;
    }
}

int calcula_moda(int valores[],int limite){
    int contagem, controle, moda = 0;
    char status[11];
    moda = 0;
    contagem = valores[0];

    //Calculando a moda
    for (controle = 1;controle <=limite ;controle ++){
        if(contagem == valores[controle]){
            strcpy(status,"nao existe");
        }
        if(contagem < valores[controle]){
            contagem = valores[controle];
            moda = controle;
            strcpy(status,"valida");
        }
    }

    // Imprimindo o resultado
    printf("Os valores sao: ");
    for(controle = 0; controle <=limite;controle++){
        printf("%03i\t",controle);
    }
    printf("\n");

    printf("A contagem  eh: ");
    for(controle = 0; controle <=limite;controle++){
        printf("%03i\t",valores[controle]);
    }
    printf("\n\n");

    if(strcmp(status,"nao existe")){
        printf("A moda eh o valor %02i, com %03i contagens, status: %s\n",moda,contagem,status);
    }else{
        printf("Moda %s.\n", status);
        moda = -1;
    }

    printf("\n\n");
    if(DEBUG == 0){
        system("pause");
    }
    system("cls");
    return  moda;
}


#endif // FUNCOES_C_INCLUDED
