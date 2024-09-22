#include "Teste_unitario/TesteLojas20.h"
#include "Teste_unitario/CuTest.h"
#include "funcoes.h"

int valida_valor(const char *palavra, int tipo){
    int controle = 0;
    int pula = 0;
    int resp = 1;
    switch (tipo){
        case CODIGO:
            for (; palavra[controle]!= '\0';controle++){
                if(!isdigit(palavra[controle])) {
                    resp = -1;
                    break;
                }
            }
        break;

        case VALOR:
            if ((palavra[0] == '-')|(palavra[0] == '+')) controle =1;
            for (; palavra[controle]!= '\0';controle++){
                if(!(isdigit(palavra[controle]))) {
                    if(palavra[controle]=='.'){
                        if(pula >= 1){
                            resp = -1;
                            break;
                        }
                        pula++;
                    }else{
                        resp = -1;
                        break;
                    }
                }
            }
        break;

        default:
            resp = -1;
    }
return resp;
}
