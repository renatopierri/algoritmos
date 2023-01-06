#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

int le_dado(char word[]);
void alinha_direita(word,tipo);
char* soma(char valor_1[], char valor_2[]);
const char * compl_1(char v2[]);
const char * compl_2(char comp_1[]);
char * subtrai(char valor_1[], char valor_2[]);
char * multiplica(char valor_1[], char valor_2[]);
char invert(char bit);
int verifica_erro(char res[]);
void completa(char saida[],char entrada[] );
void encurta(char word[]);
void alinha_direita(char word[],int tipo);
#endif // CALC_H_INCLUDED


