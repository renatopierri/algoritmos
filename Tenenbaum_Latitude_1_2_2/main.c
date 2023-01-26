#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "Teste_unitario/Teste_Latitude_122.h"


/*

Exerc�cio 1.2.2
Escreva um programa em C que fa�a o seguinte:  Leia  um  grupo  de  leituras  de
temperatura. Uma leitura consiste em dois n�meros: uminteiro  entre  -90  e  90,
representando a latitude  na  qual a  leitura  foi  efetuada,  e  a  temperatura
observada nessa latitude. Imprima uma tabela consistindo em cada latitude  e  na
temperatura  m�dia  da  latitude.  Se  n�o  existirem  leituras  em  determinada
latitude, imprima "sem dados" em  vez  de  uma  m�dia.  Em  seguida,  imprima  a
temperatura m�dia nos hemisf�rios Norte e Sul (o  Norte  consiste  em  latitudes
de 1 a 90 e o Sul em latitudes de -1 a -90). (Essa temperatura  m�dia  deve  ser
calculada como a m�dia das m�dias, n�o como a m�dia das leituras iniciais.)
Determine tamb�m o hemisf�rio mais quente.  Ao  fazer  a  determina��o,  use  as
temperaturas m�dias em todas as latitudes  de  cada  hemisf�rio  para  os  quais
existem dados tanto para essa latitude como para a  latitude  correspondente  no
outro hemisf�rio. (Por exemplo, se existirem dados  para latitude  57,  mas  n�o
para latitude -57, ent�o  a  temperatura  m�dia  para a  latitude  57  deve  ser
ignorada, ao determinar o hemisf�rio mais quente.)

Fonte da latitude x temperatura:
https://crudata.uea.ac.uk/cru/data/temperature/

Fonte: Estruturas de Dados Usando C - Tenembaum, pg 54.

Autor da solu��o: Renato de Pierri
https://nets-nuts.com.br

*/

int main(){

    int limite = 0;

    do{
        if(DEBUG == 0){
            printf("Rodando normal\n");
            le_dados(ARQUIVO);
            system("pause");
            system("cls");
        }else{
            printf("Rodando testes\n");
            RunAllTests();
            system("pause");
            system("cls");
        }
    }while(CONTINUO == 1);
    return 0;
}
