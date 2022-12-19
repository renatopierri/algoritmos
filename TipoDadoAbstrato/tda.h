#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//Interface.
//Aqui lista a estrutura e as operacoes que podem ser
//realizadas na estrutura, bem como os parametros necessários.

typedef struct Caixa *tipo_caixa;

//Conjunto de operacoes permitidas para o tipo_caixa.
extern size_t obj_size(struct Caixa *);
extern void configura_material_caixa(struct Caixa *,char[]);
extern void configura_id_caixa(struct Caixa *, int);
extern void configura_tamanho_caixa(struct Caixa *,float);
extern void configura_largura_caixa(struct Caixa *,float);
extern void configura_altura_caixa(struct Caixa *,float);
extern int obj_getid(struct Caixa *);
extern void imprime_caixa(struct Caixa *);
extern void imprime_id_caixa(struct Caixa *);
extern void destroi_caixa(struct Caixa *);

#endif // TDA_H_INCLUDED
