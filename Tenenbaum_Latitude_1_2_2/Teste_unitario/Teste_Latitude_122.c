#include "Teste_Latitude_122.h"
#include "../funcoes.h"CuSuite* StrUtilGetSuite();

void RunAllTests(void){
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    CuSuiteAddSuite(suite, StrUtilGetSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf ("%s\n\n", output->buffer);
}

//void Teste_Gera_Aleatorio(CuTest *tc){
//    CuString* str = CuStringNew();
//    int valores[ITENS];
//    int tamanho = sizeof(valores)/sizeof(valores[0]) ;
//    int quantidade = 100;
//    int total;
//    int controle;
//    char resp1[10];
//    char resp2[10];
//    for (controle = 0;controle < tamanho; controle ++){
//        valores[controle] = 0;
//    }
//    gera_aleatorio(valores, tamanho, quantidade);
//    for (controle = 0;controle < tamanho; controle ++){
//        total = total + valores[controle];
//    }
//    sprintf(resp1,"%i",(int)total);
//    sprintf(resp2,"%i",(int)quantidade);
//    CuStringAppend(str,resp1);
//    CuAssertStrEquals(tc,resp2 , str->buffer);
//}

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

//    SUITE_ADD_TEST(suite,Teste_Gera_Aleatorio);

}
