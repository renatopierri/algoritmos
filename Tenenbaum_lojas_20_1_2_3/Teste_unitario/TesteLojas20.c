#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TesteLojas20.h"
#include "../funcoes.h"
#include "../telas.h"

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

//Verifica se existe a diretiva DEBUG = 1 ou 0, quando rodando teste.
void Testa_Modo_Debug(CuTest *tc){
    CuString* str = CuStringNew();
    int valor = DEBUG;
    char resp[4];
    sprintf(resp,"%i",valor);
    CuStringAppend(str,resp);
    if (valor == 1){
        CuAssertStrEquals(tc,"1" , str->buffer);
    }else{
        if (valor == 0){
            CuAssertStrEquals(tc,"0" , str->buffer);
        }else{
            CuAssertStrEquals(tc,"Nao eh 1 ou zero" , str->buffer);
        }
    }
}

//Verifica se existe a diretiva CONTINUO e se = 1 ou 0 quando rodando teste.
void Testa_Modo_Continuo(CuTest *tc){
    CuString* str = CuStringNew();
    int valor = CONTINUO;
    char resp[4];
    sprintf(resp,"%i",valor);
    CuStringAppend(str,resp);
    if (valor == 1){
        CuAssertStrEquals(tc,"1" , str->buffer);
    }else{
        if (valor == 0){
            CuAssertStrEquals(tc,"0" , str->buffer);
        }else{
            CuAssertStrEquals(tc,"Nao eh 1 ou zero" , str->buffer);
        }
    }
}

void Testa_Tela_Abertura(CuTest *tc){
    CuString* str = CuStringNew();
    int valor = 0;
    char resp[4];
    valor = telaAbertura();
    sprintf(resp,"%i",valor);
    CuStringAppend(str,resp);
    CuAssertStrEquals(tc,"12" , str->buffer);
return;
}

void Testa_Valida_Valor1(CuTest *tc){
    CuString* str = CuStringNew();
    int valor = 0;
    char resp[4];
    valor = valida_valor("27.83",VALOR);
    valor = valor + valida_valor("+27.83",VALOR);
    valor = valor + valida_valor("-27.83",VALOR);
    valor = valor + valida_valor("27.833333",VALOR);
    valor = valor + valida_valor("2783.",VALOR);
    valor = valor + valida_valor(".2783",VALOR);
    valor = valor + valida_valor("a27.8.3",VALOR);
    valor = valor + valida_valor("2a7.83",VALOR);
    valor = valor + valida_valor("2a783",VALOR);
    valor = valor + valida_valor("2783a",VALOR);
    valor = valor + valida_valor(".27.8.3",VALOR);
    valor = valor + valida_valor("a.7.83",VALOR);
    valor = valor + valida_valor("2.783",VALOR);
    sprintf(resp, "%i", valor);
    CuStringAppend(str,resp);
    CuAssertStrEquals(tc,"1" , str->buffer);

}

void Testa_Valida_Valor2(CuTest *tc){
    CuString* str = CuStringNew();
    int valor = 0;
    char resp[4];
    valor = valida_valor("27.83",CODIGO);
    valor = valor + valida_valor("27A83",CODIGO);
    valor = valor + valida_valor("2783A",CODIGO);
    valor = valor + valida_valor("A27833333",CODIGO);
    valor = valor + valida_valor("27",CODIGO);
    valor = valor + valida_valor("2",CODIGO);
    valor = valor + valida_valor("",CODIGO);
    sprintf(resp, "%i", valor);
    CuStringAppend(str,resp);
    CuAssertStrEquals(tc,"-1" , str->buffer);

}
CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,Testa_Modo_Debug);
    SUITE_ADD_TEST(suite,Testa_Modo_Continuo);
    SUITE_ADD_TEST(suite,Testa_Tela_Abertura);
    SUITE_ADD_TEST(suite,Testa_Valida_Valor1);
    SUITE_ADD_TEST(suite,Testa_Valida_Valor2);

}
