#include "Teste_Latitude_122.h"
#include "../funcoes.h"CuSuite* StrUtilGetSuite();
#include <string.h>

void RunAllTests(void){
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
    CuSuiteAddSuite(suite, StrUtilGetSuite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf ("%s\n\n", output->buffer);
}

void Teste_Le_Dados_automatico(CuTest *tc){
    double vlat[36]= {[0 ... 35]=99};
    double vtemp[36]={[0 ... 35]=99};
    char resp[4]={"ok"};
    CuString* str = CuStringNew();
    le_dados(vlat,vtemp);
    int controle;
    for (controle = 0;controle<=35;controle++){
    if(((vlat[controle]==99)|(vtemp[controle]==99))==1){
        strcpy(resp,"nao");
        break;
        }
    }

    CuStringAppend(str,"ok");
    CuAssertStrEquals(tc,resp , str->buffer);

}

void Teste_Le_Dados_manual(CuTest *tc){
    //Para testar aqui, AUTOMATICO deve ser = 0 em funcoes.h;
    double vlat[36]= {[0 ... 35]=99};
    double vtemp[36]={[0 ... 35]=99};
    char resp[4]={"ok"};
    CuString* str = CuStringNew();
    le_dados(vlat,vtemp);
    int controle;
    for (controle = 0;controle<=35;controle++){
    if(((vlat[controle]==99)|(vtemp[controle]==99))==1){
        strcpy(resp,"nao");
        break;
        }
    }
    CuStringAppend(str,"ok");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Classifica_Dados(CuTest *tc){
    double vlat[36]= {[0 ... 35]=99};
    double vtemp[36]={[0 ... 35]=99};
    double prova=0;
    char resp[12];
    CuString* str = CuStringNew();
    le_dados(vlat,vtemp);
    classifica_dados(vlat,vtemp,36);
    prova = vlat[34]+vtemp[34]+vlat[35]+vtemp[35];
    sprintf(resp, "%f", prova);
    CuStringAppend(str,"-255.125000");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias1(CuTest *tc){
    double vlat[36]= {-87.5,-82.5,-77.5,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={-46.17500000000  ,-38.95000000000  ,-34.65833333333  ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"0");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias2(CuTest *tc){
    double vlat[36]= {-87.0,-82.5,-77.5,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={-46.17500000000  ,-38.95000000000  ,-34.65833333333  ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"17");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias3(CuTest *tc){
    double vlat[36]= {-87.0,-82.5,-77.5,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={ 99              ,-38.95000000000  ,-34.65833333333  ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"37");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias4(CuTest *tc){
    double vlat[36]= {-87.0,-82.0,-77.0,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={-46.17500000000  ,-38.95000000000  ,-34.65833333333  ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"51");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias5(CuTest *tc){
    double vlat[36]= {-87.5,-82.5,-77.5,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={ 99              , 99              ,-34.65833333333  ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"40");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias6(CuTest *tc){
    double vlat[36]= {-87.5,-82.5,-77.5,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={ 99              , 99              , 99              ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"60");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Remove_Inconsistencias7(CuTest *tc){
    double vlat[36]= {-87.0,-82.0,-77.0,-72.5,-67.5,-62.5,-57.5,-52.5,-47.5,
                      -42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5, -7.5, -2.5,
                        2.5,  7.5, 12.5, 17.5, 22.5, 27.5, 32.5, 37.5, 42.5,
                       47.5, 52.5, 57.5, 62.5, 67.5, 72.5, 77.5, 82.5, 87.5};
    double vtemp[36]={ 99              , 99              , 99              ,
                      -24.69166666667  ,-10.76666666667  , -3.34166666667  ,
                        0.92500000000  ,  4.32500000000  ,  7.85000000000  ,
                       11.54166666667  , 15.01666666667  , 17.76666666667  ,
                       20.24166666667  , 22.24,66666667  , 23.76666666667  ,
                       24.90833333333  , 25.76666666667  , 25.97500000000  ,
                       26.15000000000  , 26.34166666667  , 26.43333333333  ,
                       25.66666666667  , 24.05000000000  , 21.28333333333  ,
                       17.10000000000  , 13.61666666667  , 10.07500000000  ,
                        6.15000000000  ,  3.12500000000  ,  0.50000000000  ,
                       -4.60000000000  , -8.83333333333  , 12.08333333333  ,
                      -15.14166666667  ,-16.74166666667  ,-17.06666666667  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    classifica_dados(vlat,vtemp,36);
    prova = remove_inconsistencias( vlat,  vtemp, 36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"74");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_Calcula_Media1(CuTest *tc){
    double vlat[36]= { 87.5, 82.5, 77.5, 72.5, 67.5, 62.5, 57.5, 52.5, 47.5,
                       42.5, 37.5, 32.5, 27.5, 22.5, 17.5, 12.5,  7.5,  2.5,
                       -2.5, -7.5,-12.5,-17.5,-22.5,-27.5,-32.5,-37.5,-42.5,
                      -47.5,-52.5,-57.5,-62.5,-67.5,-72.5,-77.5,-82.5,-87.5};
    double vtemp[36]={-17.06666666667  ,-16.74166666667  ,-15.14166666667  ,
                      -12.08333333333  , -8.83333333333  , -4.60000000000  ,
                        0.50000000000  ,  3.12500000000  ,  6.15000000000  ,
                       10.07500000000  , 13.61666666667  , 17.10000000000  ,
                       21.28333333333  , 24.05000000000  , 25.66666666667  ,
                       26.43333333333  , 26.34166666667  , 26.15000000000  ,
                       25.97500000000  , 25.76666666667  , 24.90833333333  ,
                       23.76666666667  , 22.24166666667  , 20.24166666667  ,
                       17.76666666667  , 15.01666666667  , 11.54166666667  ,
                        7.85000000000  ,  4.32500000000  ,  0.92500000000  ,
                       -3.34166666667  ,-10.76666666667  ,-24.69166666667  ,
                      -34.65833333333  ,-38.95000000000  ,-46.17500000000  };
    int prova=22;
    char resp[12];
    CuString* str = CuStringNew();
    prova = calcula_media(vlat,vtemp,36);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"13980");
    CuAssertStrEquals(tc,resp , str->buffer);
}

void Teste_print_erro1(CuTest *tc){
    CuString* str = CuStringNew();
    int prova;
    char resp[12];
    prova = print_erro(111);
    sprintf(resp, "%i", prova);
    CuStringAppend(str,"12");
    system("cls");
    CuAssertStrEquals(tc,resp , str->buffer);
}

CuSuite*StrUtilGetSuite(){
    CuSuite* suite = CuSuiteNew();

    SUITE_ADD_TEST(suite,Teste_Le_Dados_automatico);
    SUITE_ADD_TEST(suite,Teste_Le_Dados_manual);
    SUITE_ADD_TEST(suite, Teste_Classifica_Dados);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias1);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias2);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias3);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias4);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias5);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias6);
    SUITE_ADD_TEST(suite,Teste_Remove_Inconsistencias7);
    SUITE_ADD_TEST(suite,Teste_Calcula_Media1);
    SUITE_ADD_TEST(suite,Teste_print_erro1);
}
