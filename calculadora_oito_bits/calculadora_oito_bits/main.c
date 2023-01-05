#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "calc.h"
#include "Arquivos_adicionais/CuTest.h"

/*
    ESTE CODIGO ESTA BUGADO, COM ERRO NO MODULO DE SUBTRACAO
    ESTOU RESOLVENDO O BUG. SE VC CONSEGUIR ARRUMAR, ME AVISE
    ESTA ERRANDO NO CALCULO DO BIT DE OVERFLOW (VAI UM) EM ALGUMAS
    SUBTRACOES. POR EXEMPLO: QUANDO SUBTRAI 1 DE 127 DA ERRO.
    00000001 MENOS 01111111
    RESULTADO ESPERADO:   110000010
    RESULTADO ENCONTRADO: 010000010
*/

//Tenenbaum 1.1.5
//Escreva funcoes em C, add, subtract e multiply, que leiam duas strings
//de Os e ls representando inteiros nao-negativos binarios, e imprima a
//string representando a soma, a diferenca e o produto, respectivamente.
//Nao e escopo desse exercicio implementar controle de erro.
//Controle de erro pode ser implementado como um opcional.
//Este código comentado esta no site https://nets-nuts.com.br
//No caminho  Notas de aulas -> Estruturas de dados usando C

int le_dado();
int le_dado(char word[]);
int eerro;
//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();
//Suite de testes
int maino(){
    while(1){
        int v1=1,v2=1 ;
        static char valor_1[11],
             valor_2[11],
             soma_resultado[11],
             sub_resultado[11],
             mult_resultado[11];
        while(v1 == 1||v2 == 1){
            printf("digite o primeiro valor binario de ate 8 bits\n");
            v1 = le_dado(valor_1);
            printf("digite o segundo valor binario de ate 8 bits\n");
            v2 = le_dado(valor_2);
            if(v1 == 1 || v2==1){
               printf("valor invalido, digite novamente todos os valores\n") ;
               Sleep(3000);
               system("cls");
               v1 = 1;
               v2 = 1;
            }
        }

        printf("Resultados validos entre -128 ate +127 - 10000000 ate 01111111\n\n");
        strcpy(soma_resultado,soma(valor_1, valor_2));
        printf ("Operacao de soma\n");
//        printf("Resultado     = %s\n",
//           &(soma_resultado[strlen (soma_resultado)-8]));
        printf("Resultado     = %s\n", soma_resultado);
        eerro = verifica_erro(soma_resultado);

        printf("erro: %d\n\n",eerro);

        printf("Operacao de subtracao\n");
        strcpy (sub_resultado, subtrai(valor_1, valor_2));
    //  printf ("Resultado     = %s\n",
    //          &(sub_resultado[strlen (sub_resultado) - 8]));
        printf ("Resultado     = %s\n",sub_resultado);
        eerro = verifica_erro(sub_resultado);
        printf("erro: %d\n\n",eerro);

    //    printf("Operacao de multiplicacao\n");
    //    strcpy(mult_resultado, multiplica(valor_1, valor_2));
    ////    printf ("Multiplicacao = %s\n\n",
    ////           &(mult_resultado[strlen (mult_resultado)-8]));
    //    printf ("Multiplicacao = %s\n",mult_resultado);
    //    eerro = verifica_erro(soma_resultado);
    //    printf("erro: %d\n\n",eerro);

        system("pause");
        system("cls");
    }
return 0;
}
// Testes unitarios

void TesteSoma1(CuTest *tc){
char * input1 = "10000000";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "1101111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub1(CuTest *tc){
char * input1 = "10000000";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma2(CuTest *tc){
char * input1 = "10000000";
char * input2 = "00000001";
char * actual = soma(input1, input2);
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


void TesteSoma3(CuTest *tc){
char * input1 = "10000000";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "1111111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub3(CuTest *tc){
char * input1 = "10000000";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1100000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma4(CuTest *tc){
char * input1 = "11111111";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1101111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub4(CuTest *tc){
char * input1 = "11111111";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0001111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma5(CuTest *tc){
char * input1 = "00000001";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1110000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub5(CuTest *tc){
char * input1 = "00000001";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0010000001";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma6(CuTest *tc){
char * input1 = "00000001";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "0010000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub6(CuTest *tc){
char * input1 = "00000001";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000010";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma7(CuTest *tc){
char * input1 = "01111111";
char * input2 = "10000000";
char * actual = soma(input1, input2);
char * expected = "1111111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub7(CuTest *tc){
char * input1 = "01111111";
char * input2 = "10000000";
char * actual = subtrai(input1, input2);
char * expected = "0011111111";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma8(CuTest *tc){
char * input1 = "01111111";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "0001111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub8(CuTest *tc){
char * input1 = "01111111";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "0010000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma9(CuTest *tc){
char * input1 = "01111111";
char * input2 = "00000001";
char * actual = soma(input1, input2);
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

void TesteSoma10(CuTest *tc){
char * input1 = "11111111";
char * input2 = "00000001";
char * actual = soma(input1, input2);
char * expected = "0000000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub10(CuTest *tc){
char * input1 = "11111111";
char * input2 = "00000001";
char * actual = subtrai(input1, input2);
char * expected = "1111111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma11(CuTest *tc){
char * input1 = "11111111";
char * input2 = "01111111";
char * actual = soma(input1, input2);
char * expected = "0001111110";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub11(CuTest *tc){
char * input1 = "11111111";
char * input2 = "01111111";
char * actual = subtrai(input1, input2);
char * expected = "1110000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSoma12(CuTest *tc){
char * input1 = "00000001";
char * input2 = "11111111";
char * actual = soma(input1, input2);
char * expected = "0000000000";
CuAssertStrEquals (tc, expected, actual);
}

void TesteSub12(CuTest *tc){
char * input1 = "00000001";
char * input2 = "11111111";
char * actual = subtrai(input1, input2);
char * expected = "0000000010";
CuAssertStrEquals (tc, expected, actual);
}









CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,TesteSoma1);
    SUITE_ADD_TEST(suite,TesteSub1);
    SUITE_ADD_TEST(suite,TesteSoma2);
    SUITE_ADD_TEST(suite,TesteSub2);
    SUITE_ADD_TEST(suite,TesteSoma3);
    SUITE_ADD_TEST(suite,TesteSub3);
    SUITE_ADD_TEST(suite,TesteSoma4);
    SUITE_ADD_TEST(suite,TesteSub4);
    SUITE_ADD_TEST(suite,TesteSoma5);
    SUITE_ADD_TEST(suite,TesteSub5);
    SUITE_ADD_TEST(suite,TesteSoma6);
    SUITE_ADD_TEST(suite,TesteSub6);
    SUITE_ADD_TEST(suite,TesteSoma7);
    SUITE_ADD_TEST(suite,TesteSub7);
    SUITE_ADD_TEST(suite,TesteSoma8);
    SUITE_ADD_TEST(suite,TesteSub8);
    SUITE_ADD_TEST(suite,TesteSoma9);
    SUITE_ADD_TEST(suite,TesteSub9);
    SUITE_ADD_TEST(suite,TesteSoma10);
    SUITE_ADD_TEST(suite,TesteSub10);
    SUITE_ADD_TEST(suite,TesteSoma11);
    SUITE_ADD_TEST(suite,TesteSub11);
    SUITE_ADD_TEST(suite,TesteSoma12);
    SUITE_ADD_TEST(suite,TesteSub12);

    return suite;
}


