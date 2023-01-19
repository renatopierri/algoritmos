#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tda_nr_abstrato.h"
#include "Teste_unitario/teste_tda_nr_abstrato.h"

typedef struct Op_imaginaria{
    double registro[7];
    char op_in_out[3];

}opimg;

op_imaginaria Op_imaginaria_new(void){
    op_imaginaria op_img = malloc(sizeof(struct Op_imaginaria));
    int controle = 0;
    while (controle <= 5){
        op_img->registro[controle]=0;
        controle++;
    }
    op_img->registro[6]='\0';
    strcpy(op_img->op_in_out,"  \0");
    return op_img;
}

void destroi_op_imaginaria(struct Op_imaginaria *op_img){
    free(op_img);
}

//Implementacao das operacoes permitidas para o tipo op_imaginaria:
size_t obj_size(struct Op_imaginaria *op_img){
    return sizeof op_img;
}

void absoluto(struct Op_imaginaria *op_img,
              double valores[],
              char operadores[]){
    valores[4] = pow(valores[0],2);
    valores[5] = pow(valores[1],2);
    operadores[1] = '+';
}

void soma_2_imaginarios(struct Op_imaginaria *op_img,
                        double valores[],
                        char operadores[]){
    valores[4] = valores[0] + valores[2];
    valores[5] = valores[1] + valores[3];
    operadores[1] = '+';
}

void multiplica_termos_x_imaginario(struct Op_imaginaria *op_img,
                                    double valores[],
                                    char operadores[]){
    valores[4] = (valores[0] * valores[2]) - (valores[1] * valores[3]);
    valores[5] = (valores[0] * valores[3]) + (valores[1] * valores[2]);
    operadores[1] = '+';

}

void regra_sinal(struct Op_imaginaria *op_img, double valores[], char sinais[] ){
    if (sinais[0]=='-'){
        valores[4] = valores[0]* -1;
        valores[5] = valores[1]* -1;
    }else{
        valores[4] = valores[0];
        valores[5] = valores[1];
    }
}

