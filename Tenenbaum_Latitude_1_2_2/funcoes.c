#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "Teste_unitario/CuTest.h"
#include "Teste_unitario/Teste_Latitude_122.h"

typedef struct Lat_temp{
    double temperaturas[36];
    double latitudes[36];
    double media_hemisferio_norte;
    double media_hemisferio_sul;
};

tipo_lat_temp Lat_temp_new(void){
    tipo_lat_temp lat_temp = malloc(sizeof(struct Lat_temp));
    lat_temp->media_hemisferio_sul = 0;
    lat_temp->media_hemisferio_norte = 0;
return lat_temp;
}

void insere_lat_temp(struct Lat_temp *o,double lat,double temp, int controle){
    o->latitudes[controle]=lat;
    o->temperaturas[controle]=temp;
}


size_t obj_size(struct Lat_temp *o) {
    return sizeof (*o);
}

void destroi_lat_temp(struct Lat_temp *o){
    free(o);
}




void le_dados(double vlat[], double vtemp[]){

    const char * lat[] = {"-87.5","-82.5","-77.5","-72.5","-67.5","-62.5",
                          "-57.5","-52.5","-47.5","-42.5","-37.5","-32.5",
                          "-27.5","-22.5","-17.5","-12.5","-7.5" , "-2.5",
                          "2.5"  ,"7.5"  ,"12.5" ,"17.5" ,"22.5" , "27.5",
                          "32.5" ,"37.5" ,"42.5" ,"47.5" ,"52.5" , "57.5",
                          "62.5" ,"67.5" ,"72.5" ,"77.5" ,"82.5" , "87.5"};
    const char * temp[] ={
                  "-46.175"         ,"-38.95"           , "-34.6583333333333",
                 "-24.6916666666667","-10.7666666666667", "-3.34166666666667",
                   "0.925"          ,  "4.325"          ,  "7.85"            ,
                  "11.5416666666667", "15.0166666666667", "17.7666666666667" ,
                  "20.2416666666667", "22.2416666666667", "23.7666666666667" ,
                  "24.9083333333333", "25.7666666666667", "25.975"           ,
                  "26.15"           , "26.3416666666667", "26.4333333333333" ,
                  "25.6666666666667", "24.05"           , "21.2833333333333" ,
                  "17.1"            , "13.6166666666667", "10.075"           ,
                   "6.15"           , "3.125"           ,  "0.5"             ,
                  "-4.6"            ,"-8.83333333333333", "-12.0833333333333",
                 "-15.1416666666667","-16.7416666666667", "-17.0666666666667"};
    int controle;
    char *ptr;
    int tamanho_lat  = (sizeof (lat)  / sizeof (const char *));
    int tamanho_temp = (sizeof (temp) / sizeof (const char *));

    if(AUTOMATICO){
        printf("Lendo automaticamente os dados \n");
        for(controle = 0;controle<tamanho_lat;controle++){
          //  printf("Latitude: %s\t| Temperatura: %s\n",
          //  lat[controle],temp[controle]);
            vlat [controle] = strtod(lat [controle],&ptr);
            vtemp[controle] = strtod(temp[controle],&ptr);


        }
    }else{
        printf("Entrada manual de dados \n");
    }

return;
}
