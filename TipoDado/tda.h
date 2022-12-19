#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//Interface.
//Aqui lista a estrutura e as operacoes que podem ser
//realizadas na estrutura, bem como os parametros necessários.

 typedef struct caixa{
     char material[20];
     float tamanho;
     float largura;
     float altura;
     int id;
    }tipo_caixa;

//Conjunto de operacoes permitidas para o tipo_caixa.
size_t obj_size(struct caixa *);
void configura_material_caixa(struct caixa *,char[]);
void configura_id_caixa(struct caixa *, int);
void configura_tamanho_caixa(struct caixa *,float);
void configura_largura_caixa(struct caixa *,float);
void configura_altura_caixa(struct caixa *,float);
int obj_getid(struct caixa *);
void imprime_caixa(struct caixa *);

#endif // TDA_H_INCLUDED
