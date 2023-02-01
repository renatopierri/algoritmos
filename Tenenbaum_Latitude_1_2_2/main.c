#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "Teste_unitario/Teste_Latitude_122.h"


/*

Exercício 1.2.2
Escreva um programa em C que faça o seguinte:  Leia  um  grupo  de  leituras  de
temperatura. Uma leitura consiste em dois números: uminteiro  entre  -90  e  90,
representando a latitude  na  qual a  leitura  foi  efetuada,  e  a  temperatura
observada nessa latitude. Imprima uma tabela consistindo em cada latitude  e  na
temperatura  média  da  latitude.  Se  não  existirem  leituras  em  determinada
latitude, imprima "sem dados" em  vez  de  uma  média.  Em  seguida,  imprima  a
temperatura média nos hemisférios Norte e Sul (o  Norte  consiste  em  latitudes
de 1 a 90 e o Sul em latitudes de -1 a -90). (Essa temperatura  média  deve  ser
calculada como a média das médias, não como a média das leituras iniciais.)
Determine também o hemisfério mais quente.  Ao  fazer  a  determinação,  use  as
temperaturas médias em todas as latitudes  de  cada  hemisfério  para  os  quais
existem dados tanto para essa latitude como para a  latitude  correspondente  no
outro hemisfério. (Por exemplo, se existirem dados  para latitude  57,  mas  não
para latitude -57, então  a  temperatura  média  para a  latitude  57  deve  ser
ignorada, ao determinar o hemisfério mais quente.)

Fonte da latitude x temperatura:
https://crudata.uea.ac.uk/cru/data/temperature/

Base do algoritmo de classificacao de dois arrays:
https://stackoverflow.com/questions/32948281/c-sort-two-arrays-the-same-way

Fonte: Estruturas de Dados Usando C - Tenembaum, pg 54.

Autor da solução: Renato de Pierri
https://nets-nuts.com.br/latitude-x-temperatura-tenenbaum-1-2-2/

*/

int main(){

    double vlat[36]= {[0 ... 35]=99};
    double vtemp[36]={[0 ... 35]=99};
    int controle, erro,result = 0;
    int check = 0;
    size_t tamanho;

    do{
        if(DEBUG == 0){
            check = le_dados(vlat,vtemp);
            if (check == 0){
                tamanho = sizeof(vlat)/sizeof(vlat[0]);
                classifica_dados(vlat,vtemp,tamanho);
                erro = remove_inconsistencias(vlat,vtemp,tamanho);
                if (erro >= 51){
                    printf("\nErro irrecuperavel: %i, digitar "
                           "novamente os dados.\n\n",erro);
                    print_erro(erro);
                }else{
                    print_erro(erro);
                    result = calcula_media(vlat,vtemp,tamanho);
                }
            }
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

