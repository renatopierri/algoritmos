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

int le_dados(double vlat[], double vtemp[]);
void classifica_dados(double vlat[], double vtemp[], size_t tamanho);
int compare(const void *pp0, const void *pp1);
int remove_inconsistencias(double vlat[], double vtemp[], size_t tamanho);
int calcula_media(double vlat[],double vtemp[],size_t tamanho);
int print_erro(int erro);
#endif // FUNCOES_H_INCLUDED
