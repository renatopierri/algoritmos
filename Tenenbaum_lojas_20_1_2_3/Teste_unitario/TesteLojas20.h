#ifndef TESTELOJAS20_H_INCLUDED
#define TESTELOJAS20_H_INCLUDED

#include "../funcoes.h"
#include "CuTest.h"
CuSuite*StrUtilGetSuite();
void RunAllTests(void);

// Testes unitarios

void Testa_Modo_Debug(CuTest *tc);
void Testa_Modo_Continuo(CuTest *tc);
void Testa_Tela_Abertura(CuTest *tc);
void Testa_Valida_Valor1(CuTest *tc);
void Testa_Valida_Valor2(CuTest *tc);


#endif // TESTELOJAS20_H_INCLUDED
