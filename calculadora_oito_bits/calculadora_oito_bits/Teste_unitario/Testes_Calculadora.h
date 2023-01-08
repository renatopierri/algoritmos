#ifndef TESTES_CALCULADORA_H_INCLUDED
#define TESTES_CALCULADORA_H_INCLUDED

//CuSuite* StrUtilGetSuite();

void TesteNato(char oi[]);
void RunAllTests(void);

void TesteSoma1(CuTest *tc);
void TesteSoma2(CuTest *tc);
void TesteSoma3(CuTest *tc);
void TesteSoma4(CuTest *tc);
void TesteSoma5(CuTest *tc);
void TesteSoma6(CuTest *tc);
void TesteSoma7(CuTest *tc);
void TesteSoma8(CuTest *tc);
void TesteSoma9(CuTest *tc);
void TesteSoma10(CuTest *tc);
void TesteSoma11(CuTest *tc);
void TesteSoma12(CuTest *tc);

//Testes de subtracao

void TesteSub1(CuTest *tc);
void TesteSub2(CuTest *tc);
void TesteSub3(CuTest *tc);
void TesteSub4(CuTest *tc);
void TesteSub5(CuTest *tc);
void TesteSub6(CuTest *tc);
void TesteSub7(CuTest *tc);
void TesteSub8(CuTest *tc);
void TesteSub9(CuTest *tc);
void TesteSub10(CuTest *tc);
void TesteSub11(CuTest *tc);
void TesteSub12(CuTest *tc);

void TestMult1(CuTest *tc);

//Complemento de 1 e complemento de 2

void Complemento_1(CuTest *tc);
void Complemento_2_128n(CuTest *tc);
void Complemento_2_1n(CuTest *tc);
void Complemento_2_1p(CuTest *tc);
void Complemento_2_127p(CuTest *tc);

//Teste de sinal
void mais3__x__mais2(CuTest *tc);
void mais3__x_menos2(CuTest *tc);
void menos3_x__mais2(CuTest *tc);
void menos3_x_menos2(CuTest *tc);

CuSuite*StrUtilGetSuite();

#endif // TESTES_CALCULADORA_H_INCLUDED
