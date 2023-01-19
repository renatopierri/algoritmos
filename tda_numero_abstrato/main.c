#include <stdio.h>
#include <stdlib.h>
#include "tda_nr_abstrato.h"
#include "Teste_unitario/teste_tda_nr_abstrato.h"
#include "funcoes.h"

/*
Exercício:
Escreva uma especificacao de TDA para os numeros  complexos, a+
bi, onde abs(a+bi) eh  sqrt(a^2+b^2), (a+bi)+(c+di)e(a+c)+(b+d)
i, (a+b)*(c+di) eh (a*c-b*d)+(a*d+b*c)i e -(a+bi) eh (-a)+(-b)i

Fonte: Tenembaum, Estrutura de dados usando C, ex 1.1.8, pg34.
Autor da soulucao: Renato de Pierri - nets-nuts.com.br

Interpretacao do exercicio:
Escreva uma especificacao de TDA para os numeros complexos a+bi onde:
1: abs(a+bi) = sqrt(a^2 + b^2)
2:    (a+bi) + (c+di) = (a+c) + (b+d)i
3:    (a+b)  * (c+di) = (a*c-b*d) + (a*d+b*c)i
4:   -(a+bi) = (-a) + (-b)i

Interpretacao da interpretacao da questão:
Criar um TDA - Tipo de Dado Abstrato que receba parametros e:

Calcule o valor absoluto, de acordo com a equação nr 1.
Calcule a soma de dois numeros imaginarios, de acordo com a equacao nr 2.
Multiplique dois numeros imaginarios, na forma da equacao nr 3.
Aplique a propriedade do sinal, de acordo com a equacao nr 4.
*/

//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();

int main()
{
    //int debug = 1;
    int debug = 0;
    int continuo = 1;
    //int continuo = 0;

    double val[7];
    char operadores[3];
    op_imaginaria nr_img = Op_imaginaria_new();

    do{
      if (debug == 1){
        RunAllTests();
      }else{
        printf("Implementação de Tipo de Dado Abstrato - TDA\n\n");

        //=====================================================================

        gera_randomico(val);

        printf("Calculando o valor absoluto do numero imaginario "
               "(%.1f + %.1fi)\n",val[0],val[1]);
        operadores[0]='+';
        absoluto(nr_img,val,operadores);
        printf("O absoluto de (%.1f %c %.1fi)"
               " eh (%.1f %c %.1f) = %.1f\n\n",
               val[0],operadores[0],val[1],val[4],
               operadores[0],val[5],(val[4]+val[5]));

        //=====================================================================

        gera_randomico(val);

        operadores[0] = '+';
        printf("Calculando a soma de %.1f + %.1fi com %.1f + %.1fi\n",
               val[0],val[1],val[2],val[3]);
        soma_2_imaginarios(nr_img,val,operadores);
        printf("O valor da soma de (%.1f + %.1fi) %c (%.1f + %.1fi)"
               " eh: (%.1f %c %.1fi)\n\n", val[0],val[1],operadores[0],
               val[2], val[3], val[4],operadores[1],val[5]);

        //=====================================================================

        gera_randomico(val);

        printf("Multiplicando os termos (%.1f + %.1f) com um nr imaginario "
               "(%.1f + %.1fi) \n",val[0],val[1],val[2],val[3]);
        operadores[0] = '*';
        multiplica_termos_x_imaginario(nr_img,val,operadores);
        printf("A multiplicacao dos termos (%.1f + %.1f) por (%.1f + %.1fi)"
               " eh: (%.1f %c %.1fi)\n\n", val[0],val[1],
               val[2], val[3], val[4],operadores[1], val[5]);

        //=====================================================================

        printf("Aplicando a regra do sinal \n");

        gera_randomico(val);

        operadores[0] = '-';
        regra_sinal(nr_img,val,operadores);
        printf("-(%.1f + %.1fi) eh: (%.1f) + (%.1fi)\n\n",
               val[0],val[1],val[4],val[5]);

        //=====================================================================

      }
      system("pause");
      system("cls");
    }while(continuo);
}
