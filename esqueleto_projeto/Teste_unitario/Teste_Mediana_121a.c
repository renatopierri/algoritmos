#include "Teste_Mediana_121a.h"
#include "CuTest.h"

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

//void TesteValorAbsoluto2(CuTest *tc){
//    CuString* str = CuStringNew();
//    op_imaginaria nr_img = Op_imaginaria_new();
//    double  val[7];
//    char operadores[3];
//
//    //Inicializando o teste
//    val[0]=1;
//    val[1]=7;
//    val[2]=0;
//    val[3]=0;
//    operadores[0]='+';
//
//    //Testando a funcao
//    absoluto(nr_img,val,operadores);
//
//    //Preparando o resultado para assercao
//    CuStringAppend(str,operadores );
//    CuAssertStrEquals(tc, "++", str->buffer);
//}

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

//    SUITE_ADD_TEST(suite,TesteValorAbsoluto1);
//    SUITE_ADD_TEST(suite,TesteValorAbsoluto2);
//    SUITE_ADD_TEST(suite,TesteSoma_2_Imaginarios1);
//    SUITE_ADD_TEST(suite,TesteSoma_2_Imaginarios2);
//    SUITE_ADD_TEST(suite,TesteMultiplica_termos_x_imaginario1);
//    SUITE_ADD_TEST(suite,TesteMultiplica_termos_x_imaginario2);
//    SUITE_ADD_TEST(suite,TesteRegraSinal);
}
