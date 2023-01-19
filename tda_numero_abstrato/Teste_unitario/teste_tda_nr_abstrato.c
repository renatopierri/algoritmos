#include <stdio.h>
#include <stdlib.h>
#include "teste_tda_nr_abstrato.h"
#include "../tda_nr_abstrato.h"
#include "CuTest.h"
#include "string.h"
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

void TesteValorAbsoluto1(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];
    char resp[4];
    char resultado[8];

    //Inicializando o teste
    int controle = 0;
    val[0]=1;
    val[1]=7;
    val[2]=0;
    val[3]=0;
    for(controle = 0;controle <=7;controle++){
        resultado[controle]='\0';
    }
    operadores[0]='+';

    //Testando a funcao
    absoluto(nr_img,val,operadores);

    //Preparando o resultado para assercao
    for (controle = 0;controle<=6;controle++){
        itoa((int)val[controle],resp,10);
        strcat(resultado,resp);
    }
    CuStringAppend(str,resultado );
    CuAssertStrEquals(tc, "17001490", str->buffer);
}

void TesteValorAbsoluto2(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];

    //Inicializando o teste
    val[0]=1;
    val[1]=7;
    val[2]=0;
    val[3]=0;
    operadores[0]='+';

    //Testando a funcao
    absoluto(nr_img,val,operadores);

    //Preparando o resultado para assercao
    CuStringAppend(str,operadores );
    CuAssertStrEquals(tc, "++", str->buffer);
}


void TesteSoma_2_Imaginarios1(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];
    char resp[4];
    char resultado[9];

    //Inicializando o teste
    int controle = 0;
    val[0]=9;
    val[1]=4;
    val[2]=8;
    val[3]=8;
    for(controle = 0;controle <=8;controle++){
        resultado[controle]='\0';
    }
    operadores[0]='+';

    //Testando a funcao
    soma_2_imaginarios(nr_img,val,operadores);

    //Preparando o resultado para assercao
    for (controle = 0;controle<=6;controle++){
        itoa((int)val[controle],resp,10);
        strcat(resultado,resp);
    }
    CuStringAppend(str,resultado );
    CuAssertStrEquals(tc, "948817120", str->buffer);
}

void TesteSoma_2_Imaginarios2(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];

    //Inicializando o teste
    val[0]=9;
    val[1]=4;
    val[2]=8;
    val[3]=8;
    operadores[0]='+';

    //Testando a funcao
    absoluto(nr_img,val,operadores);
    CuStringAppend(str,operadores );
    CuAssertStrEquals(tc, "++", str->buffer);
}

void TesteMultiplica_termos_x_imaginario1(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];
    char resp[4];
    char resultado[9];

    //Inicializando o teste
    int controle = 0;
    val[0]=3;
    val[1]=1;
    val[2]=2;
    val[3]=3;
    for(controle = 0;controle <=8;controle++){
        resultado[controle]='\0';
    }
    operadores[0]='+';

    //Testando a funcao
    multiplica_termos_x_imaginario(nr_img,val,operadores);

    //Preparando o resultado para assercao
    for (controle = 0;controle<=6;controle++){
        itoa((int)val[controle],resp,10);
        strcat(resultado,resp);
    }
    CuStringAppend(str,resultado );
    CuAssertStrEquals(tc, "31233110", str->buffer);
}

void TesteMultiplica_termos_x_imaginario2(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];

    //Inicializando o teste
    val[0]=3;
    val[1]=1;
    val[2]=2;
    val[3]=3;
    operadores[0]='+';

    //Testando a funcao
    absoluto(nr_img,val,operadores);
    CuStringAppend(str,operadores );
    CuAssertStrEquals(tc, "++", str->buffer);
}

void TesteRegraSinal(CuTest *tc){
    CuString* str = CuStringNew();
    op_imaginaria nr_img = Op_imaginaria_new();
    double  val[7];
    char operadores[3];
    int controle;
    char resultado[5];

    //Inicializando o teste
    for (controle=0;controle<=4;controle++){
        resultado[controle]='\0';
    }
    char temp[3];
    val[0] = 1;
    val[1] = 7;
    val[2] = 0;
    val[3] = 0;
    operadores[0]='-';

    //Testando a funcao
    regra_sinal(nr_img,val,operadores);

    //Preparando o resultado para assercao
    for(controle = 4;controle<=5;controle++){
        itoa((int)val[controle],temp,10);
        strcat(resultado,temp);
    }
    CuStringAppend(str,resultado );
    CuAssertStrEquals(tc, "-1-7", str->buffer);
}


CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,TesteValorAbsoluto1);
    SUITE_ADD_TEST(suite,TesteValorAbsoluto2);
    SUITE_ADD_TEST(suite,TesteSoma_2_Imaginarios1);
    SUITE_ADD_TEST(suite,TesteSoma_2_Imaginarios2);
    SUITE_ADD_TEST(suite,TesteMultiplica_termos_x_imaginario1);
    SUITE_ADD_TEST(suite,TesteMultiplica_termos_x_imaginario2);
    SUITE_ADD_TEST(suite,TesteRegraSinal);
}



