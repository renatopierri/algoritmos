#include <stdio.h>
#include <stdlib.h>
#include "Teste_unitario/Teste_Mediana_121a.h"
#include "Teste_unitario/CuTest.h"
#include "funcoes.h"

void gera_aleatorio(int valores[],int tamanho){
    int controle;
    for(controle = 0;controle<=tamanho;controle++){
        valores[controle]=rand() % 100;
    }
}

float classifica(int mediana[], int tamanho){
    int sup;
    int inf;
    float med;
    qsort(mediana, tamanho, sizeof(int), funcao_compara);
    if (tamanho%2==0){
        sup = (int)(tamanho/2);
        inf = sup - 1;
        med = (mediana[sup]+mediana[inf])/2.0f;
    }else{
        sup = (int)(tamanho/2);
        med =(float) mediana[sup];
    }
return med;
}

int funcao_compara (const void * v1, const void * v2) {
    return ( *(int*)v1 - *(int*)v2 );
}
