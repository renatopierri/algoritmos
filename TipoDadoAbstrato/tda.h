#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

 typedef struct caixa{
     char tipo[10];
     float tamanho;
     float largura;
     float altura;
     int id;
    }define_caixa;


/*
 * The compiler considers struct obj an incomplete type. Incomplete types
 * can be used in declarations.
 */

size_t obj_size(struct caixa *);
void configura_tipo_caixa(struct caixa *,char[]);
void configura_id_caixa(struct caixa *, int);
void configura_tamanho_caixa(struct caixa *,float);
void configura_largura_caixa(struct caixa *,float);
void configura_altura_caixa(struct caixa *,float);

int obj_getid(struct caixa *);
void imprime_caixa(struct caixa *);
//    printf("Tipo de caixa: %s.\n"
//        "Tamanho: %.2f\n"
//        "Largura: %.2f\n"
//        "Altura: %.2f\n"
//        "Tamanho do objeto: %d\n"
//        "id da caixa: %d\n",
//        caixa.tipo,
//        caixa.tamanho,
//        caixa.largura,
//        caixa.altura,
//        tamanho_obj,
//        id_caixa
//    );

#endif // TDA_H_INCLUDED
