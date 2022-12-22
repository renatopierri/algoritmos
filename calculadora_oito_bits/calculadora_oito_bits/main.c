#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Escreva funcoes em C, add, subtract e multiply, que leiam duas strings
//de Os e ls representando inteiros nao-negativos binarios, e imprima a
//string representando a soma, a diferenca e o produto, respectivamente.

void soma(char v1[], char v2[], char soma_res[]);
void subtrai(char v1[], char v2[], char sub_res[]);
void multiplica (char v1[], char v2[],char mult_res[]);
char invert(char bit);

int le_dado();
int le_dado(char word[]);

int main()
{
    int v1=1,v2=1 ;
    char valor_1[9], valor_2[9],soma_resultado[10],sub_resultado[10],mult_resultado[16];
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
    soma(valor_1, valor_2, soma_resultado);
    subtrai(valor_1, valor_2, sub_resultado);
    multiplica(valor_1, valor_2, mult_resultado);

    return 0;
}

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

void soma(char v1[], char v2[], char soma_res[]){
int controle = 0;
static char vai_um = '0';
    soma_res[0]='0';
//Mandrakaria ativar! - Logica booleana da soma e logica booleana do vai um:
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

        printf("bit    %d: %c %c %c\n",
               7-controle, v1[controle],
               v2[controle],soma_res[controle+1]);
    }
//Mandrakaria desativar!
//Imprimindo o resultado da soma binaria:
    printf("overflow:     %c\n", soma_res[0]);
    printf("Resultado = %s\n",soma_res);
return;
}

void subtrai(char v1[], char v2[], char sub_res[]){

return;
}

void multiplica(char v1[], char v2[], char mult_res[]){

return;
}
char invert(char bit){
    if (bit == '0'){
        bit = '1';
    }else{
        bit = '0';
    }
return bit;
}
