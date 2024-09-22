#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "telas.h"
#include "funcoes.h"

int telaAbertura(){
    char codigo[5];
    int valor = -1;
    int resp = 0;
    while(valor == -1){
        printf("TELA LOJA\n");
        printf("Digite o codigo da loja\n");
        if(DEBUG != 1){
            scanf("%3s",&codigo);
        }else{
            strcpy(codigo,"12");
            valor =1;
        }
        fflush(stdin);
        valor = valida_valor(codigo,CODIGO);
        resp = atoi(codigo);
        if(((valor == -1)|(resp == 0)|(resp > MAXLOJA))&(resp != FECHALOJA)){
            printf("Codigo invalido = %02s,\nDigitar novamente.",codigo);
            valor = -1;
            sleep(2);
            system("cls");
        }
        if(resp == FECHALOJA){
            resp = FECHALOJA;
        }
    }
return resp;
}
int telaItem(cod_loja){
    float vitem;
    int loop=0;
    while(loop != SAIINSEREITEM){

        system("cls");
        printf("TELA ITEM\n");
        printf("Voce esta na loja = %02i\n",cod_loja);
        printf("Digite o codigo do item, de 1 a 10: \n");
        printf ("Digite o valor do item: %05.2f\n",vitem);
        printf ("Digite 50 para retornar ao menu anterior\n",vitem);
        system("pause");

    }
return cod_loja;
}

