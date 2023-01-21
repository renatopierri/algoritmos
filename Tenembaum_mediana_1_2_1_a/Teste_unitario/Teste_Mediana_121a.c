#include <stdlib.h>
#include <stdio.h>
#include "Teste_Mediana_121a.h"
#include "CuTest.h"
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

void TesteAleatorio_10(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[10];
    size_t nr_elementos;
    char resp1[5];
    gera_aleatorio(valores,10);
    nr_elementos = sizeof(valores)/sizeof(valores[0]);
    sprintf(resp1,"%i",(int)nr_elementos);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, "10", str->buffer);
}

void TesteAleatorio_11(CuTest *tc){
    CuString* str = CuStringNew();
    int valores[11];
    size_t nr_elementos;
    char resp1[5];
    gera_aleatorio(valores,11);
    nr_elementos = sizeof(valores)/sizeof(valores[0]);
    sprintf(resp1,"%i",(int)nr_elementos);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, "11", str->buffer);
}

void TesteClassifica_10(CuTest *tc){
    int valores[10] = {91, 27, 27, 42, 45, 81, 91, 4, 36, 61};
    float mediana;
    mediana = 7.3;
    char resp1[5];
    CuString* str = CuStringNew();
    mediana = classifica(valores,10);
    sprintf(resp1,"%.01f",mediana);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, "43.5", str->buffer);
}

void TesteClassifica_11(CuTest *tc){
    int valores[11] = {91, 4, 27, 36, 45, 61, 81, 91, 95, 27, 42};
    float mediana;
    char resp1[5];
    char resp2[5];
    CuString* str = CuStringNew();
    mediana = classifica(valores,11);
    sprintf(resp1,"%.01f",mediana);
    sprintf(resp2,"%.01f",(float)valores[5]);
    CuStringAppend(str,resp1);
    CuAssertStrEquals(tc, resp2, str->buffer);
}

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,TesteAleatorio_10);
    SUITE_ADD_TEST(suite,TesteAleatorio_11);
    SUITE_ADD_TEST(suite,TesteClassifica_10);
    SUITE_ADD_TEST(suite,TesteClassifica_11);

}
