#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "Teste_unitario/CuTest.h"
#include "Teste_unitario/Teste_Latitude_122.h"

int le_dados(double vlat[], double vtemp[]){

    const char * lat[] = {"-82.5","-87.5","-77.5","-72.5","-67.5","-62.5",
                          "-57.5","-52.5","-47.5","-42.5","-37.5","-32.5",
                          "-27.5","-22.5","-17.5","-12.5","-7.5" , "-2.5",
                          "2.5"  ,"7.5"  ,"12.5" ,"17.5" ,"22.5" , "27.5",
                          "32.5" ,"37.5" ,"42.5" ,"47.5" ,"52.5" , "57.5",
                          "62.5" ,"67.5" ,"72.5" ,"77.5" ,"82.5" , "87.5"};
    const char * temp[] ={
                "-38.95"           ,"-46.175"          ,"-34.6583333333333",
                "-24.6916666666667","-10.7666666666667","-3.34166666666667",
                "0.925"            ,"4.325"            ,"7.85"             ,
                "11.5416666666667" ,"15.0166666666667" ,"17.7666666666667" ,
                "20.2416666666667" ,"22.2416666666667" ,"23.7666666666667" ,
                "24.9083333333333" ,"25.7666666666667" ,"25.975"           ,
                "26.15"            ,"26.3416666666667" ,"26.4333333333333" ,
                "25.6666666666667" ,"24.05"            ,"21.2833333333333" ,
                "17.1"             ,"13.6166666666667" ,"10.075"           ,
                "6.15"             ,"3.125"            ,"0.5"              ,
                "-4.6"             ,"-8.83333333333333","-12.0833333333333",
                "-15.1416666666667","-16.7416666666667","-17.0666666666667"};
    int controle;
    int check = 0;
    char *ptr;
    int tamanho_lat = (sizeof(lat)/sizeof (const char *));

    if(AUTOMATICO){
        printf("Lendo automaticamente os dados \n");
        for(controle = 0;controle<tamanho_lat;controle++){
            vlat [controle] = strtod(lat [controle],&ptr);
            vtemp[controle] = strtod(temp[controle],&ptr);
        }
    }else{
        printf("Entrada manual de dados nao implementada \n");
        check = 1;
        for(controle = 0;controle<tamanho_lat;controle++){
            vlat [controle] = strtod(lat [controle],&ptr);
            vtemp[controle] = strtod(temp[controle],&ptr);

        }
    }
 return check;
}

void classifica_dados(double vlat[], double vtemp[], size_t tamanho){
    double *inter[tamanho];
    size_t i, j, k;
    double va,  vb;

    /* Salvando os ponteiros que indicam os endereços das variaveis  vlat[] */
    for(i = 0; i < tamanho; i++)
        inter[i] = &vlat[i];
    /* Classificando array de ponteiros */
    qsort(inter, tamanho, sizeof(inter[0]), compare);

    /* Alinhando vlat[] e vtemp[] de acordo com a classificacao de inter*/
    for(i = 0; i < tamanho; i++){
        if(i != inter[i]-vlat){
            va = vlat [i];
            vb = vtemp[i];
            k = i;
            while(i != (j = inter[k]-vlat)){
                vlat[k]  =  vlat[j];
                vtemp[k] = vtemp[j];
                inter[k] = &vlat[k];
                k = j;
            }
            vlat[k] =  va;
            vtemp[k] = vb;
            inter[k] = &vlat[k];
        }
    }

    for(i = 0; i < tamanho; i++){
        printf(" %+05.1lf\t%+05.1lf\n", vlat[i], vtemp[i]);
    }
return;
}

int compare(const void *pp0, const void *pp1){
    double i0 = **(double **)pp0;
    double i1 = **(double **)pp1;
    if(i0 > i1)return -1;
    if(i0 < i1)return  1;
    return 0;
}

int remove_inconsistencias(double vlat[], double vtemp[], size_t tamanho){
    int controle;
    int sobe, desce, erro, erro_total;
    erro  =0;
    sobe  = ((int)tamanho/2)-1;
    desce = sobe + 1;
    for (controle = sobe;controle>=0;controle--){
        if((vtemp[sobe]==99)|(vtemp[desce]==99)){
            printf("Inconsistencia na temperatura: %+05.1lf %+05.1lf e "
                   "%+05.1lf %+05.1lf\n",
                   vlat[sobe],vtemp[sobe],vlat[desce],vtemp[desce]);
            erro = erro  +  4;
            erro = erro  + 16;
            vtemp[sobe]  = 99;
            vtemp[desce] = 99;
        }
        if(vlat[sobe]+vlat[desce]!=0){
            erro = erro +  1;
            erro = erro + 16;
            printf("Desalinhamento entre latitude: %+05.1lf %+05.1lf e "
                   "%+05.1lf %+05.1lf\n",
                   vlat[sobe],vtemp[sobe],vlat[desce],vtemp[desce]);
            vtemp[sobe]  = 99;
            vtemp[desce] = 99;
        }
        erro_total = erro >>4;
            if(erro_total >=3){
            printf("\nerro irrecuperavel: %i \n",erro);
                break;
        }
        sobe--;
        desce++;
    }
    printf("\n");
return erro;
}

int calcula_media(double vlat[],double vtemp[],size_t tamanho){
    int controle, sobe, desce,check, elementos = 0;
    double media_total, media_hemisferio_norte, media_hemisferio_sul;
    media_total=0;
    media_hemisferio_norte=0;
    media_hemisferio_sul=0;
    sobe  = ((int)tamanho/2)-1;
    desce = sobe + 1;
    for (controle = sobe;controle>=0;controle--){
        if(vtemp[sobe]!=99){
            media_hemisferio_norte = media_hemisferio_norte +   vtemp[sobe];
            media_hemisferio_sul   = media_hemisferio_sul   +  vtemp[desce];
            media_total = media_total + vtemp[sobe] + vtemp[desce];
            elementos++;
        }
        sobe --;
        desce++;
    }

    media_hemisferio_sul   = media_hemisferio_sul/elementos;
    media_hemisferio_norte = media_hemisferio_norte/elementos;
    media_total            = media_total/(elementos*2);

    printf("Media geral\t\t: %+05.1lf.\n", media_total                     );
    printf("Media hemisferio Norte\t: %+05.1lf.\n", media_hemisferio_norte );
    printf("Media hemisferio Sul\t: %+05.1lf.\n\n", media_hemisferio_sul   );

    if(media_hemisferio_sul > media_hemisferio_norte){
       printf("O hemisferio Sul   tem uma temperatura media maior\n");
       printf("O hemisferio Norte tem uma temperatura media menor\n");
    }else{
        if(media_hemisferio_sul == media_hemisferio_norte){
            printf("A média nos hemisferios Sul e Norte sao iguais" );
        }else{
            printf("O hemisferio Norte\t:tem uma temperatura media maior.\n");
            printf("O hemisferio Sul  \t:tem uma temperatura media menor.\n\n");
        }
    }
    check=(int)((media_hemisferio_sul+media_hemisferio_norte+media_total)*1000);

return check;
}

int print_erro(int erro){
    //Decodifica e imprime o detalhe do erro
    int erro_vlat, erro_vtemp, erro_total = 0;
    int check;
    erro_vlat =   erro  & 3;
    erro_vtemp = (erro >> 2)&3;
    erro_total =  erro >> 4;
    printf("Erros na latitude\t: %i.\n",   erro_vlat   );
    printf("Erros na temperatura\t: %i.\n",erro_vtemp  );
    printf("Total de erros\t\t: %i.\n\n",    erro_total);
    check = erro_vlat+erro_vtemp+erro_total;
return check;
}
