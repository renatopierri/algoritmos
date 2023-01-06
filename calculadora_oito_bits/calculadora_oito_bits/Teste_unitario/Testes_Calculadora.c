#include "CuTest.h"

CuSuite* StrUtilGetSuite();

void TesteNato(char oi[]);

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

//Teste invert bit

//void TesteInverte0(CuTest *tc){
//
//char * input1 = "0";
//char * actual = invert(input1);
//char * expected = "1";
//CuAssertStrEquals (tc, expected, actual);
//}

//void TesteInverte1(CuTest *tc){
//char * input1 = '1';
//char * actual = invert(input1);
//char * expected = '0';
//CuAssertStrEquals (tc, expected, actual);
//}

//Testes de soma

void TesteSoma1(CuTest *tc){
char * input1 = "10000000";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "1101111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma2(CuTest *tc){
char * input1 = "10000000";
char * input2 = "00000001";
char * actual = soma(input1, input2);
char * expected = "1110000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma3(CuTest *tc){
char * input1 = "10000000";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "1111111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma4(CuTest *tc){
char * input1 = "11111111";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1101111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma5(CuTest *tc){
char * input1 = "00000001";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1110000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma6(CuTest *tc){
char * input1 = "00000001";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "0010000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma7(CuTest *tc){
char * input1 = "01111111";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1111111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma8(CuTest *tc){
char * input1 = "01111111";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "0001111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma9(CuTest *tc){
char * input1 = "01111111";
char * input2 = "00000001";
char * actual = soma(input1, input2);
char * expected = "0010000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma10(CuTest *tc){
char * input1 = "11111111";
char * input2 = "00000001";
char * actual = soma(input1, input2);
char * expected = "0000000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma11(CuTest *tc){
char * input1 = "11111111";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "0001111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma12(CuTest *tc){
char * input1 = "00000001";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "0000000000";
CuAssertStrEquals (tc, expected, actual);
}

//Testes de subtracao

void TesteSub1(CuTest *tc){
char * input1 = "10000000";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub2(CuTest *tc){
char * input1 = "10000000";
char * input2 = "00000001";
char * actual = subtrai(input1, input2);
char * expected = "1101111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub3(CuTest *tc){
char * input1 = "10000000";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1100000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub4(CuTest *tc){
char * input1 = "11111111";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0001111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub5(CuTest *tc){
char * input1 = "00000001";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0010000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub6(CuTest *tc){
char * input1 = "00000001";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000010";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub7(CuTest *tc){
char * input1 = "01111111";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0011111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub8(CuTest *tc){
char * input1 = "01111111";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "0010000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub9(CuTest *tc){
char * input1 = "01111111";
char * input2 = "00000001";
char * actual = subtrai(input1, input2);
char * expected = "0001111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub10(CuTest *tc){
char * input1 = "11111111";
char * input2 = "00000001";
char * actual = subtrai(input1, input2);
char * expected = "1111111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub11(CuTest *tc){
char * input1 = "11111111";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub12(CuTest *tc){
char * input1 = "00000001";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "0000000010";
CuAssertStrEquals (tc, expected, actual);
}

//Complemento de 1 e complemento de 2

void Complemento_1(CuTest *tc){
char * input1 = "111100001";
char * actual =  compl_1(input1);
char * expected = "000011110";
CuAssertStrEquals (tc, expected, actual);
}

void Complemento_2_128n(CuTest *tc){
char * input1 = "001111111";
char * actual =  compl_2(input1);
char * expected = "010000000";
CuAssertStrEquals (tc, expected, actual);
}

void Complemento_2_1n(CuTest *tc){
char * input1 = "000000000";
char * actual =  compl_2(input1);
char * expected = "000000001";
CuAssertStrEquals (tc, expected, actual);
}

void Complemento_2_1p(CuTest *tc){
char * input1 = "111111110";
char * actual =  compl_2(input1);
char * expected = "111111111";
CuAssertStrEquals (tc, expected, actual);
}

void Complemento_2_127p(CuTest *tc){
char * input1 = "110000000";
char * actual =  compl_2(input1);
char * expected = "110000001";
CuAssertStrEquals (tc, expected, actual);
}


CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

//  SUITE_ADD_TEST(suite,TesteInverte0);
//  SUITE_ADD_TEST(suite,TesteInverte1);

    SUITE_ADD_TEST(suite,TesteSoma1);
    SUITE_ADD_TEST(suite,TesteSoma2);
    SUITE_ADD_TEST(suite,TesteSoma3);
    SUITE_ADD_TEST(suite,TesteSoma4);
    SUITE_ADD_TEST(suite,TesteSoma5);
    SUITE_ADD_TEST(suite,TesteSoma6);
    SUITE_ADD_TEST(suite,TesteSoma7);
    SUITE_ADD_TEST(suite,TesteSoma8);
    SUITE_ADD_TEST(suite,TesteSoma9);
    SUITE_ADD_TEST(suite,TesteSoma10);
    SUITE_ADD_TEST(suite,TesteSoma11);
    SUITE_ADD_TEST(suite,TesteSoma12);

    SUITE_ADD_TEST(suite,Complemento_1);
    SUITE_ADD_TEST(suite,Complemento_2_128n);
    SUITE_ADD_TEST(suite,Complemento_2_1n);
    SUITE_ADD_TEST(suite,Complemento_2_1p);
    SUITE_ADD_TEST(suite,Complemento_2_127p);

    SUITE_ADD_TEST(suite,TesteSub1);
    SUITE_ADD_TEST(suite,TesteSub2);
    SUITE_ADD_TEST(suite,TesteSub3);
    SUITE_ADD_TEST(suite,TesteSub4);
    SUITE_ADD_TEST(suite,TesteSub5);
    SUITE_ADD_TEST(suite,TesteSub6);
    SUITE_ADD_TEST(suite,TesteSub7);
    SUITE_ADD_TEST(suite,TesteSub8);
    SUITE_ADD_TEST(suite,TesteSub9);
    SUITE_ADD_TEST(suite,TesteSub10);
    SUITE_ADD_TEST(suite,TesteSub11);
    SUITE_ADD_TEST(suite,TesteSub12);



    return suite;
}
