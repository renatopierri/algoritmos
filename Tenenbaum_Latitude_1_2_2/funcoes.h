#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>

/*
DEBUG:      0 - Operacao normal, 1 - Modo de testes.
CONTINUO:   0 - Roda uma vez,    1 - Modo continuo.
AUTOMATICO  0 - Insere manual    1 - Insere dados automaticamente
*/

#define DEBUG 0
#define CONTINUO 1
#define AUTOMATICO 1



typedef struct Lat_temp *tipo_lat_temp;
//Conjunto de operacoes permitidas para o tipo_lat_temp.
extern size_t obj_size(struct Lat_temp *);
extern void insere_lat_temp(struct Lat_temp *,double,double,int);
extern void destroi_lat_temp(struct Lat_temp *);

void le_dados(double vlat[], double vtemp[]);
#endif // FUNCOES_H_INCLUDED
