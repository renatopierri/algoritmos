/*
Implementando os algoritmos do livro "Estruturas de Dados Usando C - Tenembaum"
Autor da implementacao: Renato de Pierri
Concatenando duas strings - figura 1.1.3
*/
#include <stdio.h>
#include <stdlib.h>
void movimenta(char origem[],char destino[],int *posicao_destino);

int main()
{
    int posicao=0;
    int indice=1;
    char palavra_1[]="5Hello";
    char palavra_2[]="9Everybody";
    char concatenado[16];
    movimenta (palavra_1,concatenado,&posicao);
    posicao++;
    movimenta (palavra_2,concatenado,&posicao);
    concatenado[0]=posicao;

    printf("%s\n%s\n%d",palavra_1,palavra_2,concatenado[0]);
    while (concatenado[indice]!='\0'){
        printf ("%c",concatenado[indice]);
        indice++;
    }

    return 0;
}

void movimenta(char origem[],char destino[],int *posicao_destino){
    int indice_origem = 0;
    if ((*posicao_destino)>=1){indice_origem++;}
    while (origem[indice_origem] != '\0'){
        destino[(*posicao_destino)] = origem[indice_origem];
        (*posicao_destino)++;
        indice_origem++;
    }
    (*posicao_destino)--;
}
