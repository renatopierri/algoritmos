#ifndef TDA_NR_ABSTRATO_H_INCLUDED
#define TDA_NR_ABSTRATO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//Interface.
//Aqui lista a estrutura e as operacoes que podem ser
//realizadas na estrutura, bem como os parametros necessários.

typedef struct Op_imaginaria *op_imaginaria;
op_imaginaria Op_imaginaria_new(void);

//Conjunto de operacoes permitidas para a operacao com numeros imaginarios.
extern size_t obj_size(struct Op_imaginaria *);

extern void absoluto(struct Op_imaginaria *,double valores[], char operadores[]);

extern void soma_2_imaginarios(struct Op_imaginaria *, double valores[],
                               char operadores[]);

extern void multiplica_termos_x_imaginario(struct Op_imaginaria *,double valores[],
                                     char operadores[]);

extern void regra_sinal(struct Op_imaginaria *,double valores[], char sinais[]);

extern void destroi_op_imaginaria(struct Op_imaginaria *);


#endif // TDA_NR_ABSTRATO_H_INCLUDED
