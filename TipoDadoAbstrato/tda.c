#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tda.h"

void configura_tipo_caixa(struct caixa *o, char i[]){
     strcpy (o->tipo, i);
}

void configura_id_caixa(struct caixa *o, int i) {
    o->id = i;
}

void configura_tamanho_caixa(struct caixa *o,float i){
    o->tamanho = i;
}

void configura_largura_caixa(struct caixa *o,float i){
    o->largura =i;
}

void configura_altura_caixa(struct caixa *o,float i){
    o->altura = i;
}

int obj_getid(struct caixa *o) {
    return o->id;
}

size_t obj_size(struct caixa *o) {
    return sizeof (*o);
}

void imprime_caixa(struct caixa *o){
    printf("Tipo de caixa: %s.\n"
        "Tamanho: %.2f\n"
        "Largura: %.2f\n"
        "Altura: %.2f\n"
        "Id da caixa %d\n"
        "Tamanhho do objeto %u\n",
        o->tipo,
        o->tamanho,
        o->largura,
        o->altura,
        obj_getid(o),
        (unsigned)obj_size(o)
    );
}
