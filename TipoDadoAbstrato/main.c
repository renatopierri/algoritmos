#include <stdio.h>
#include "tda.h"

int main() {
    int tamanho_obj,id_caixa;
    define_caixa caixa;

    configura_tipo_caixa(&caixa,"madeira");
    configura_tamanho_caixa(&caixa,12);
    configura_largura_caixa(&caixa,17.4);
    configura_altura_caixa(&caixa,7.2);
    configura_id_caixa(&caixa, 32);
    tamanho_obj = obj_size(&caixa);
    id_caixa = obj_getid(&caixa);
    imprime_caixa(&caixa);

    printf("Tipo de caixa: %s.\n"
        "Tamanho: %.2f\n"
        "Largura: %.2f\n"
        "Altura: %.2f\n"
        "id da caixa: %d\n"
        "Tamanho do objeto: %d\n",
        caixa.tipo,
        caixa.tamanho,
        caixa.largura,
        caixa.altura,
        id_caixa,
        tamanho_obj
    );
   return 0;
}
