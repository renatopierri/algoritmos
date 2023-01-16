#include <stdio.h>
#include <stdlib.h>
#include "../funcoes.h"
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
// Testes unitarios


//==================================================

void TesteBinarioParaTernario1(CuTest *tc){
CuString* str = CuStringNew();
char  ter[7];
representaTernario("11111110", ter);
CuStringAppend(str,ter );
CuAssertStrEquals(tc, "100102", str->buffer);
}

void TesteBinarioParaTernario2(CuTest *tc){
CuString* str = CuStringNew();
char  ter[7];
representaTernario("01000010", ter);
CuStringAppend(str,ter );
CuAssertStrEquals(tc, "002110", str->buffer);
}

void TesteBinarioParaTernario3(CuTest *tc){
CuString* str = CuStringNew();
char  ter[7];
representaTernario("00000000", ter);
CuStringAppend(str,ter );
CuAssertStrEquals(tc, "000000", str->buffer);
}

void TesteBinarioParaTernario4(CuTest *tc){
CuString* str = CuStringNew();
char  ter[7];
representaTernario("00000010", ter);
CuStringAppend(str,ter );
CuAssertStrEquals(tc, "000002", str->buffer);
}

//==================================================

void TesteTernarioParaBinario1(CuTest *tc){
CuString* str = CuStringNew();
char  bin[9];
representaBinario("100110", bin);
CuStringAppend(str,bin );
CuAssertStrEquals(tc, "11111111", str->buffer);
}

void TesteTernarioParaBinario2(CuTest *tc){
CuString* str = CuStringNew();
char  bin[9];
representaBinario("002110", bin);
CuStringAppend(str,bin );
CuAssertStrEquals(tc, "01000010", str->buffer);
}

void TesteTernarioParaBinario3(CuTest *tc){
CuString* str = CuStringNew();
char  bin[9];
representaBinario("000000", bin);
CuStringAppend(str,bin );
CuAssertStrEquals(tc, "00000000", str->buffer);
}

void TesteTernarioParaBinario4(CuTest *tc){
CuString* str = CuStringNew();
char  bin[9];
representaBinario("000002", bin);
CuStringAppend(str,bin );
CuAssertStrEquals(tc, "00000010", str->buffer);
}

//==================================================

void TesteAlinhaDireita1(CuTest *tc){
CuString* str = CuStringNew();
char  input[9]="10";
alinha_direita(input,BINARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "00000010", str->buffer);
}

void TesteAlinhaDireita2(CuTest *tc){
CuString* str = CuStringNew();
char  input[9]="101010";
alinha_direita(input,BINARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "00101010", str->buffer);
}

void TesteAlinhaDireita3(CuTest *tc){
CuString* str = CuStringNew();
char  input[9]="10101010";
alinha_direita(input,BINARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "10101010", str->buffer);
}

void TesteAlinhaDireita4(CuTest *tc){
CuString* str = CuStringNew();
char  input[7]="22";
alinha_direita(input,TERNARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "000022", str->buffer);
}

void TesteAlinhaDireita5(CuTest *tc){
CuString* str = CuStringNew();
char  input[7]="012012";
alinha_direita(input,TERNARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "012012", str->buffer);
}

void TesteAlinhaDireita6(CuTest *tc){
CuString* str = CuStringNew();
char  input[7]="201";
alinha_direita(input,TERNARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "000201", str->buffer);
}

void TesteAlinhaDireita7(CuTest *tc){
CuString* str = CuStringNew();
char  input[9]="1000";
alinha_direita(input,BINARIO);
CuStringAppend(str,input );
CuAssertStrEquals(tc, "00001000", str->buffer);
}

//==================================================

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,TesteBinarioParaTernario1);
    SUITE_ADD_TEST(suite,TesteBinarioParaTernario2);
    SUITE_ADD_TEST(suite,TesteBinarioParaTernario3);
    SUITE_ADD_TEST(suite,TesteBinarioParaTernario4);

    SUITE_ADD_TEST(suite,TesteTernarioParaBinario1);
    SUITE_ADD_TEST(suite,TesteTernarioParaBinario2);
    SUITE_ADD_TEST(suite,TesteTernarioParaBinario3);
    SUITE_ADD_TEST(suite,TesteTernarioParaBinario4);

    SUITE_ADD_TEST(suite,TesteAlinhaDireita1);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita2);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita3);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita4);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita5);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita6);
    SUITE_ADD_TEST(suite,TesteAlinhaDireita7);
}
