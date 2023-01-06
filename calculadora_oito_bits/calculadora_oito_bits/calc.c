#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"

#define CONTA 1
#define INTERNA  0

int le_dado(char word[]){
    int controle, check, tamanho_string,varre;
    check = 0;
    controle = 0;
    scanf("%8s",word);
    fflush(stdin);
    int tipo = CONTA;

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

    alinha_direita(word,tipo);
    printf("string completa: %s\n", word);
    return check;
}

//void soma(char valor_1[], char valor_2[], char soma_res[]){
char* soma(char valor_1[], char valor_2[]){
int controle = 0;
char v1[10],v2[10];
static char vai_um = '0';
static char soma_res[11];

int tamanho = strlen (valor_1);
if (tamanho == 8){
    completa(v1, valor_1);
    completa(v2, valor_2);
}else{

strcpy(v1,valor_1);
alinha_direita(v1,CONTA);
strcpy(v2,valor_2);
alinha_direita(v2,CONTA);
}

strcpy(soma_res,"ABCDEFGHIJ");
vai_um = '0';

//Mandrakaria ativar! - Implementação do somador de oito bits com overflow:
    for (controle = 9 ; controle >= 0; controle--){
        if (controle == 0){
            soma_res[controle] = soma_res[1];
        }else{
            soma_res[controle] = (invert(v1[controle-1])&invert(v2[controle-1])&vai_um)|
                                   (invert(v1[controle-1])&v2[controle-1]&invert(vai_um))|
                                   (v1[controle-1]&invert(v2[controle-1])&invert(vai_um))|
                                   (v1[controle-1]&v2[controle-1]&vai_um);
            if(((v2[controle-1]&vai_um)|
                (v1[controle-1]&vai_um)|
                (v1[controle-1]&v2[controle-1]))=='1'){
                vai_um = '1';
            }else{
                vai_um = '0';
            }
        }
    }
  //  vai_um = '0';
//Mandrakaria desativar!

 return soma_res;
}

const char * compl_1(char v2[]){
    int varre;
    static char comp_1[11];
    for(varre = 8; varre >=0; varre--){
        comp_1[varre] = invert(v2[varre]);
    }
return comp_1;
}

const char * compl_2(char comp_1[]){
    char comp_2[11];
    strcpy(comp_2,soma("000000001",comp_1));
    char * ret = comp_2+1;
return ret;
}

/*
   1-+127
    00000001 MENOS 01111111
    RESULTADO ESPERADO:   110000010
    RESULTADO ENCONTRADO: 010000010
*/

char * subtrai(char valor_1[], char valor_2[]){
    char v1[10],v2[10];
    static char complemento_1[10], complemento_2[11];
    static char sub_res[11];
    completa(v1, valor_1);
    completa(v2, valor_2);
    sub_res[0]='0';
    strcpy (complemento_1, compl_1(v2));
    strcpy (complemento_2, compl_2(complemento_1));
    char *ve1 = v1+1;
    char *c2 = complemento_2+1;
    strcpy (sub_res, soma(ve1,c2));
   // strcpy (sub_res, soma(v1,complemento_2));

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

////Aplicando a regra do sinal
//  if (sinal == '1'){
//    strcpy (mult_res, compl_1(mult_res));
//    strcpy (mult_res, compl_2(mult_res));
//  }
//return mult_res;
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
    char res_0 = res[1];
    char res_1 = res[2];
    char i_res_0 = invert(res[1]);
    char i_res_1 = invert(res[2]);

    if(((i_res_0&res_1)|(res_0&i_res_1))=='1'){
        erro = 1;
        }else{
        erro=0;
    }
return erro;
}


void completa(char saida[],char entrada[] ){
    if (entrada[0] == '1'){
        saida[0] = '1';
       // saida[1] = '1';
    }else{
        saida[0]='0';
       // saida[1]='0';
    }
    int controle = 1;
    while (controle <= 9){
        saida[controle] = entrada[controle -1];
        controle++;
    }
//    saida[9]='\0';

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

void alinha_direita(char word[],int tipo){
int tamanho_string, varre;
tamanho_string = strlen(word);
    tamanho_string--;
    for(varre = 8; varre >=0; varre--){
        if(tamanho_string >= 0){
            word[varre] = word[tamanho_string];
            tamanho_string --;
        }else{
            word[varre] = '0';
        }
    }
    word[9]='\0';
    if (tipo == 1){
        if (word[1]=='1'){word[0]='1';}
    }else{
        word[0]='0';
    }
return;
}
