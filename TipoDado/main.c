#include <stdio.h>
#include "tda.h"

int main() {
    int tamanho_obj,id_caixa;
//Declarando uma caixa do "tipo_caixa"
    tipo_caixa caixa;

//Chamando o conjunto de operacoes permitidas para o tipo_caixa.
    configura_material_caixa(&caixa,"madeira");
    configura_tamanho_caixa(&caixa,12);
    configura_largura_caixa(&caixa,17.4);
    configura_altura_caixa(&caixa,7.2);
    configura_id_caixa(&caixa, 32);
    tamanho_obj = obj_size(&caixa);
    id_caixa = obj_getid(&caixa);

//Imprimindo individualmente cada um dos elementos da caixa
//Nesta implementacao é possivel acessar diretamente
//cada um dos elementos da estrutura
    printf("Material da caixa: %s.\n"
        "Tamanho: %.1fcm\n"
        "Largura: %.1fcm\n"
        "Altura: %.1fcm\n"
        "id da caixa: %d\n"
        "Tamanho do objeto: %d\n\n",
        caixa.material,
        caixa.tamanho,
        caixa.largura,
        caixa.altura,
        id_caixa,
        tamanho_obj
    );

//Funcao para imprimir todos elementos da caixa
    imprime_caixa(&caixa);
   return 0;
}
