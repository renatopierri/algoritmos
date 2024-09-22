#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Teste_Moda_121b.h"
#include "../funcoes.h"



CuSuite* StrUtilGetSuite();

void RunAllTests(void){
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    CuSuiteAddSuite(suite, StrUtilGetSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf ("%s\n\n", output->buffer);
}

void Teste_Gera_Aleatorio(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[ITENS];
    int tamanho = sizeof(valores)/sizeof(valores[0]) ;
    int quantidade = 100;
    int total;
    int controle;
    char resp1[10];
    char resp2[10];
    for (controle = 0;controle < tamanho; controle ++){
        valores[controle] = 0;
    }
    gera_aleatorio(valores, tamanho, quantidade);
    for (controle = 0;controle < tamanho; controle ++){
        total = total + valores[controle];
    }
    sprintf(resp1,"%i",(int)total);
    sprintf(resp2,"%i",(int)quantidade);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc,resp2 , str->buffer);
}

void Teste_Zera_Valores(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[TAMANHO];
    int tamanho = sizeof(valores)/sizeof(valores[0]);
    int controle;
    char resp1[TAMANHO+1]={'\0'};
    char resp2[TAMANHO+1]={'\0'};
    char temp[2];
    gera_aleatorio(valores, tamanho, 200);
    zera_valores(valores,tamanho);
    for(controle = 0;controle < tamanho;controle++){
        sprintf(temp,"%i",(int)valores[controle]);
        strcat(resp1,temp);
        strcat(resp2,"0");
    }
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc,resp2 , str->buffer);
}

void Teste_Calcula_Moda(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[10]={5,8,6,3,1,1,20,3,4,4};
    int limite = 9;
    int resultado = 0;
    char resp1[3]={'\0'};
    resultado = calcula_moda(valores,limite);
    sprintf(resp1,"%i",(int)resultado);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, "6", str->buffer);
}

void Teste_Calcula_Moda_Erro(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[10]={5,8,6,20,1,1,20,3,4,4};
    int limite = 9;
    int resultado = 0;
    char resp1[3]={'\0'};
    resultado = calcula_moda(valores,limite);
    sprintf(resp1,"%i",(int)resultado);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, "-1", str->buffer);
}

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,Teste_Gera_Aleatorio);
    SUITE_ADD_TEST(suite,Teste_Zera_Valores);
    SUITE_ADD_TEST(suite,Teste_Calcula_Moda);
    SUITE_ADD_TEST(suite,Teste_Calcula_Moda_Erro);
}
