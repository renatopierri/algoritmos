#ifndef TESTE_MODA_121B_H_INCLUDED
#define TESTE_MODA_121B_H_INCLUDED
#include "../funcoes.h"
#include "CuTest.h"
CuSuite*StrUtilGetSuite();
void RunAllTests(void);

// Testes unitarios

void Teste_Gera_Aleatorio(CuTest *tc);
void Teste_Zera_Valores(CuTest *tc);
void Teste_Calcula_Moda(CuTest *tc);
void Teste_Calcula_Moda_Erro(CuTest *tc);

#endif // TESTE_MODA_121B_H_INCLUDED
