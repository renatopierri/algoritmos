#include <stdio.h>
#include <stdlib.h>

int main()
{

    struct caixa{
        char tipo[10];
        float tamanho;
        float largura;
        float altura;
    }caixa;
    strcpy (caixa.tipo, "madeira");
    caixa.tamanho = 10.0;
    caixa.largura = 12.5;
    caixa.altura = 7;

    printf(
        "Tipo de caixa: %s.\n"
        "Tamanho: %.2f\n"
        "Largura: %.2f\n"
        "Altura: %.2f\n",
        caixa.tipo,
        caixa.tamanho,
        caixa.largura,
        caixa.altura
    );
}
