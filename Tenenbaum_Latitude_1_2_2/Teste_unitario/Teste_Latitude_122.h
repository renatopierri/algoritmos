#ifndef TESTE_LATITUDE_122_H_INCLUDED
#define TESTE_LATITUDE_122_H_INCLUDED
#include "../funcoes.h"
#include "CuTest.h"
CuSuite*StrUtilGetSuite();
void RunAllTests(void);
void Teste_Le_Dados_automatico(CuTest *tc);
void Teste_Le_Dados_manual(CuTest *tc);
void Teste_Classifica_Dados(CuTest *tc);
void Teste_Remove_Inconsistencias1(CuTest *tc);
void Teste_Remove_Inconsistencias2(CuTest *tc);
void Teste_Remove_Inconsistencias3(CuTest *tc);
void Teste_Remove_Inconsistencias4(CuTest *tc);
void Teste_Remove_Inconsistencias5(CuTest *tc);
void Teste_Remove_Inconsistencias6(CuTest *tc);
void Teste_Remove_Inconsistencias7(CuTest *tc);
void Teste_Calcula_Media1(CuTest *tc);
void Teste_print_erro1(CuTest *tc);

#endif // TESTE_LATITUDE_122_H_INCLUDED
