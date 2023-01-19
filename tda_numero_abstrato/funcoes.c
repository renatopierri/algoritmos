#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funcoes.h"

void gera_randomico(double val[]){
    val[0] =  rand() % 10;
    val[1] =  rand() % 10;
    val[2] =  rand() % 10;
    val[3] =  rand() % 10;
}

