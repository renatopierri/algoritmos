#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"

#define NEGATIVO 1

int le_dado(char word[]){
    int controle, check, tamanho_string;
    check = 0;
    controle = 0;
    scanf("%8s",word);
    fflush(stdin);


//Verifica se tem apenas "um" e "zeros"
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

    alinha_direita(word);
    printf("string completa:  %s\n", word);
    return check;
}

//void soma(char valor_1[], char valor_2[], char soma_res[]){
char* soma(char valor_1[], char valor_2[]){
    int controle = 0;
    static char v1[9],v2[9];
    static char vai_um = '0';
    static char soma_res[10];

    int tamanho = strlen (valor_1);
    if (tamanho == 8){
        completa(v1, valor_1);
        completa(v2, valor_2);
    }else{
        strcpy(v1,valor_1);
        strcpy(v2,valor_2);
    }

    strcpy(soma_res,"ABCDEFGHI");
    vai_um = '0';

//Mandrakaria ativar! - Implementação do somador de oito bits com overflow:
    for (controle = 9 ; controle >= 0; controle--){
        soma_res[controle] = (invert(v1[controle])&invert(v2[controle])&vai_um)|
                               (invert(v1[controle])&v2[controle]&invert(vai_um))|
                               (v1[controle]&invert(v2[controle])&invert(vai_um))|
                               (v1[controle]&v2[controle]&vai_um);
        if(((v2[controle]&vai_um)|
            (v1[controle]&vai_um)|
            (v1[controle]&v2[controle]))=='1'){
            vai_um = '1';
        }else{
            vai_um = '0';
        }
    }

//Mandrakaria desativar!
soma_res[9]='\0';
 return soma_res;
}

const char * compl_1(char v2[]){
    int varre;
    static char comp_1[9];
    for(varre = 8; varre >=0; varre--){
        comp_1[varre] = invert(v2[varre]);
    }
return comp_1;
}

const char * compl_2(char comp_1[]){
    static char comp_2[9];
    strcpy(comp_2,soma("000000001",comp_1));
return comp_2;
}

char * subtrai(char valor_1[], char valor_2[]){
    static char v1[9],v2[9];
    static char complemento_1[9], complemento_2[9];
    static char sub_res[9];
    completa(v1, valor_1);
    completa(v2, valor_2);
    sub_res[0]='0';
    strcpy (complemento_1, compl_1(v2));
    strcpy (complemento_2, compl_2(complemento_1));
    strcpy (sub_res, soma(v1,complemento_2));
return sub_res;
}

char * multiplica(char valor_1[], char valor_2[]){
    static char fator1[9],fator2[9],ct[9], temp[9];
    static char mult_res[10];
    static char complemento_1[9];
    int sinal;


    strcpy (fator1, valor_1);
    strcpy (fator2, valor_2);
    strcpy (ct, valor_2);
//    char sinal = v2[0];

    strcpy(mult_res,"000000000");
    strcpy(temp,"00000000");
    if(ct[0] == '1'){
        while((ct[0]|ct[1]|ct[2]|ct[3]|ct[4]|ct[5]|ct[6]|ct[7])!='0'){
            strcpy(temp,(soma(temp,fator1))+1);
            strcpy(ct,((soma(ct,"00000001"))+1));
        }
    }else{
        while((ct[0]|ct[1]|ct[2]|ct[3]|ct[4]|ct[5]|ct[6]|ct[7]|ct[8])!='0'){
            strcpy(temp,(soma(temp,fator1))+1);
            strcpy(ct,((subtrai(ct,"00000001"))+1));
        }
    }
    sinal = verifica_sinal(fator1[0], fator2[0]);
    if((sinal == NEGATIVO)||(temp[0]=='1')){
        char f1 = invert(fator1[0]);
        char f2 = fator2[0];
        if((f1=='1')&(f2=='1')||(f1=='0')&(f2=='1')){
            strcpy (complemento_1, compl_1(temp));
            complemento_1[8]='\0';
            completa(temp,complemento_1);
            strcpy (mult_res, compl_2(temp));
        }else{
            completa(mult_res,temp);
        }

    }else{
        completa(mult_res,temp);
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

    if(((i_res_0&res_1)|(res_0&i_res_1))=='1'){
        erro = 1;
        }else{
        erro=0;
    }
return erro;
}

int verifica_sinal(char fator1, char fator2){
    int erro = 1;
    char i_fator1 = invert(fator1);
    char i_fator2 = invert(fator2);

    if(((i_fator1&fator2)|(fator1&i_fator2))=='1'){
        erro = 1;
        }else{
        erro=0;
    }
return erro;
}


void completa(char saida[],char entrada[] ){
    if (entrada[0] == '1'){
        saida[0] = '1';
    }else{
        saida[0]='0';
    }
    int controle = 1;
    while (controle <= 9){
        saida[controle] = entrada[controle-1];
        controle++;
    }
//    saida[9]='\0';
return;
}

void encurta(char word[]){
    int tamanho_string = 8;
    int varre;
//Alinhando a direita
    tamanho_string--;
    for(varre = 10; varre >=0; varre--){
        if(tamanho_string >= 0){
            word[varre] = word[tamanho_string];
            tamanho_string --;
        }else{
            word[varre] = '0';
        }
    }
    word[9]='\0';
    if (word[1]=='1'){word[0]='1';}
    return;
}

void alinha_direita(char word[]){
    int tamanho_string, varre;
    tamanho_string = strlen(word);
    if(tamanho_string < 8){
        tamanho_string--;
            for(varre = 7; varre >=0; varre--){
                if(tamanho_string >= 0){
                    word[varre] = word[tamanho_string];
                    tamanho_string --;
                }else{
                    word[varre] = '0';
                }
            }
    }

return;
}
