#include <stdio.h>
#include <stdlib.h>
#include "Teste_unitario/TesteLojas20.h"
#include "Teste_unitario/CuTest.h"
#include "funcoes.h"
#include "telas.h"

/*

Fonte: Estruturas de Dados Usando C - Tenembaum.

Autor da solução: Renato de Pierri
nets-nuts.com.br

*/
//Suite de testes
CuSuite* CuGetSuite();
CuSuite* CuStringGetSuite();

int main()
{
    int cod_loja = 0;
    int tela = 0;
    do{
        if(DEBUG==0){
            //Solicitar o número da loja
            cod_loja = telaAbertura();
            if (cod_loja != FECHALOJA){
                tela = telaItem(cod_loja);

            }else{
                printf("Encerrando o programa\n");
                system("pause");
                break;
            }
            system("pause");
            system("cls");

        }else{
            RunAllTests();
            printf("testes\n");
            system("pause");
            system("cls");
        }
    }while(CONTINUO == 1);

return 1;

}
