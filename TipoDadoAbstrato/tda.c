#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tda.h"

//Implementacao das operacoes permitidas para o tipo_caixa
void configura_material_caixa(struct caixa *o, char i[]){
     strcpy (o->material, i);
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
    printf("Material de caixa: %s.\n"
        "Tamanho: %.1fcm\n"
        "Largura: %.1fcm\n"
        "Altura: %.1fcm\n"
        "Id da caixa %d\n"
        "Tamanhho do objeto %u\n",
        o->material,
        o->tamanho,
        o->largura,
        o->altura,
        obj_getid(o),
        (unsigned)obj_size(o)
    );
}
