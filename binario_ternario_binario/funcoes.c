#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

int le_dado(char word[],int tipo){
    int controle, check, tamanho_string;
    controle = 0;

    //Verifica se tem apenas 0s, 1s e 2s conforme o caso
    if(tipo == BINARIO){
        check = 0;
        scanf("%8s",word);
        fflush(stdin);
        tamanho_string = strlen(word);
        while (controle < tamanho_string){
            if (word[controle]== '0'||word[controle] == '1'){
                check = 0;
                controle++;
            }else{
                check = 1;
                controle = tamanho_string;
            }
        }
    }else{
        check = 0;
        scanf("%6s",word);
        fflush(stdin);
        tamanho_string = strlen(word);
        while (controle < tamanho_string){
            if (word[controle]=='0'||word[controle]=='1'||word[controle]=='2'){
                check = 0;
                controle++;
            }else{
                check = 1;
                controle = tamanho_string;
            }
        }
    }
return check;
}

void representaTernario(char entrada_binario[], char result_ternario[]){
    int controle = 0;
    int decimal = 0;
    int v1 = 0;
    char temp1[7];
    int tamanhoString = strlen(entrada_binario);
    for(controle = 0; controle <= tamanhoString; controle++){
        if(entrada_binario[controle]=='1'){
           decimal=decimal+pow(2,-1*controle+7) ;
        }
    }
    controle = 5;
    while(decimal>0){
        v1 = decimal%3;
        temp1[controle]=v1+'0';
        controle --;
        decimal = (int)(decimal/3);
    }
    while(controle>=0){
        temp1[controle]='0';
        controle --;
    }
    strcpy(result_ternario,temp1);
return;
}

void representaBinario(char entrada_ternario[],char result_binario[]){
	int controle = 0;
    int decimal = 0;
    int v1 = 0;
    char temp1[9];
    int tamanhoString = strlen(entrada_ternario);
    for(controle = 0; controle <= tamanhoString; controle++){
        if((entrada_ternario[controle]=='1')||(entrada_ternario[controle]=='2')){
           decimal=decimal+(((entrada_ternario[controle])-48)*(pow(3,-1*controle+5)));
        }
    }
    controle = 7;
    while(decimal>0){
        v1 = decimal%2;
        temp1[controle]=v1+'0';
        controle --;
        decimal = (int)(decimal/2);
    }
    while(controle>=0){
        temp1[controle]='0';
        controle --;
    }
    strcpy(result_binario,temp1);
return;
}

void alinha_direita(char entrada[],int tipo){
    int tamanho_string;
    int controle;
    int desloca;
    char bin_direita[9]="00000000";
    char ter_direita[7]="000000";

    int des,ctrl;

    if(tipo == BINARIO){
        des = 8;
    }else{
        des = 6;
    }
    ctrl = des -1;

    tamanho_string = strlen(entrada);
    desloca = des - tamanho_string;

    if(tipo == BINARIO){
        for(controle = ctrl;controle>=0;controle--){
            if (controle < tamanho_string){
                bin_direita[controle+desloca] = entrada[controle];
            }
        }
        strcpy(entrada,bin_direita);
    }else{
        for(controle = ctrl;controle>=0;controle--){
            if (controle < tamanho_string){
                ter_direita[controle+desloca] = entrada[controle];
            }
        }
        strcpy(entrada,ter_direita);
    }

return;
}
