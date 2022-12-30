#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"

int le_dado(char word[]){
    int controle, check, tamanho_string,varre;
    check = 0;
    controle = 0;
    scanf("%8s",word);
    fflush(stdin);

//Verifica se tem "um" e "zeros"
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

//Alinhando a direita
    tamanho_string--;
    for(varre = 7; varre >=0; varre--){
        if(tamanho_string >= 0){
            word[varre] = word[tamanho_string];
            tamanho_string --;
        }else{
            word[varre] = '0';
        }
    }
    word[8]='\0';

    printf("string: %s\n", word);
    return check;
}

//void soma(char valor_1[], char valor_2[], char soma_res[]){
char* soma(char valor_1[], char valor_2[]){
int controle = 0;
char v1[9],v2[9];
static char vai_um = '0';
static char soma_res[10];
soma_res[0]='0';
strcpy (v1, valor_1);
strcpy (v2, valor_2);

//Mandrakaria ativar! - Implementação do somador de oito bits com overflow:
    for (controle = 7; controle >= 0; controle--){
        soma_res[controle+1] = (invert(v1[controle])&invert(v2[controle])&vai_um)|
                               (invert(v1[controle])&v2[controle]&invert(vai_um))|
                               (v1[controle]&invert(v2[controle])&invert(vai_um))|
                               (v1[controle]&v2[controle]&vai_um);
        if(((v2[controle]&vai_um)|
            (v1[controle]&vai_um)|
            (v1[controle]&v2[controle]))=='1'){
            vai_um = '1';

            if(controle == 0){
               soma_res[0] = '1';
            }
        }else{
            vai_um = '0';
        }
    }
    vai_um = '0';
//Mandrakaria desativar!
//Retornando o resultado da soma binaria:
 return soma_res;
}

const char * compl_1(char v2[]){
    int varre;
    static char comp_1[9];
    for(varre = 7; varre >=0; varre--){
        comp_1[varre] = invert(v2[varre]);
    }
return comp_1;
}

const char * compl_2(char comp_1[]){
    static char comp_2[9];
     strcpy(comp_2,soma("00000001",comp_1));
return comp_2;
}

char * subtrai(char valor_1[], char valor_2[]){
    char v1[9],v2[9];
    char complemento_1[9], complemento_2[9];
    static char sub_res[10];
    sub_res[0]='0';
    strcpy (v1, valor_1);
    strcpy (v2, valor_2);
    strcpy (complemento_1, compl_1(v2));
    strcpy (sub_res, compl_2(complemento_1));
    memcpy(complemento_2,&sub_res[1],9);
    strcpy (sub_res, soma(v1,complemento_2));
 return sub_res;
}

char * multiplica(char valor_1[], char valor_2[]){
    static char v1[9],v2[9];
    char sinal;
    static char mult_res[10];

    strcpy (v1, valor_1);
    strcpy (v2, valor_2);
    sinal = v2[0];

    strcpy(mult_res,"000000000");
    if(v2[0] == '1'){
        while((v2[0]|v2[1]|v2[2]|v2[3]|v2[4]|v2[5]|v2[6]|v2[7])!='0'){
            memcpy(mult_res,&((soma(mult_res,v1)))[1],9);
            memcpy(v2,&(soma(v2,"00000001"))[1],9);
        }
    }else{
        while((v2[0]|v2[1]|v2[2]|v2[3]|v2[4]|v2[5]|v2[6]|v2[7]|v2[8])!='0'){
            memcpy(mult_res,&((soma(mult_res,v1)))[1],9);
            memcpy(v2,&(subtrai(v2,"00000001"))[1],9);
        }
    }

//Aplicando a regra do sinal
  if (sinal == '1'){
    strcpy (mult_res, compl_1(mult_res));
    strcpy (mult_res, compl_2(mult_res));
  }
return mult_res;
}

char invert(char bit){
    if (bit == '0'){
        bit = '1';
    }else{
        bit = '0';
    }
return bit;
}

//controle de erro. Precisa implementar

int verifica_erro(char res[]){
    int erro = 1;
    char res_0 = res[0];
    char res_1 = res[1];
    char i_res_0 = invert(res[0]);
    char i_res_1 = invert(res[1]);

    res_0 = res_0&'\01';
    res_1 = res_1&'\01';
    i_res_0 = i_res_0&'\01';
    i_res_1 = i_res_1&'\01';

    if((i_res_0&i_res_1)|(res_0&res_1)){
        erro = 0;
        }else{
        erro=1;
    }
return erro;
}

//Verifica se e zero. Precisa implementar
//int verifica_zero(char res[]){
//    int ezero = 0;
//return ezero;
//}
