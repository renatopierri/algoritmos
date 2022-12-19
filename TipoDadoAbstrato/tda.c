#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tda.h"

typedef struct Caixa{
     char material[20];
     float tamanho;
     float largura;
     float altura;
     int id;
};

tipo_caixa Caixa_new(void){
    tipo_caixa caixa = malloc(sizeof (struct Caixa));
    caixa->id = 1;
    strcpy (caixa->material, "teste");
    caixa->altura = 10.2;
    caixa->largura = 2.3;
    caixa->tamanho = 8.4;
    return caixa;
}

void destroi_caixa(struct Caixa *o){
    free(o);
}

//Implementacao das operacoes permitidas para o tipo_caixa
void configura_material_caixa(struct Caixa *o, char i[]){
     strcpy (o->material, i);
}

void configura_id_caixa(struct Caixa *o, int i) {
    o->id = i;
}

void configura_tamanho_caixa(struct Caixa *o,float i){
    o->tamanho = i;
}

void configura_largura_caixa(struct Caixa *o,float i){
    o->largura =i;
}

void configura_altura_caixa(struct Caixa *o,float i){
    o->altura = i;
}

int obj_getid(struct Caixa *o) {
    return o->id;
}

size_t obj_size(struct Caixa *o) {
    return sizeof (*o);
}

void imprime_caixa(struct Caixa *o){
    printf("Material de caixa: %s.\n"
        "Tamanho: %.1fcm\n"
        "Largura: %.1fcm\n"
        "Altura: %.1fcm\n"
        "Id da caixa %d\n"
        "Tamanhho do objeto %u\n\n",
        o->material,
        o->tamanho,
        o->largura,
        o->altura,
        obj_getid(o),
        (unsigned)obj_size(o)
    );
}

void imprime_id_caixa(struct Caixa *o){
    printf("Imprimindo apenas o Id da caixa\n"
           "Id da caixa %d\n", o->id);
}
