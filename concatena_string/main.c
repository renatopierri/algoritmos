#include <stdio.h>
#include <stdlib.h>
movimenta(char origem[],char destino[],int *controle);

int main()
{
    int i=0;
    int val=1;
    char c1[]="5Hello";
    char c2[]="9Everybody";
    char c3[16];
    movimenta (c1,c3,&i);
    i=i+1;
    movimenta (c2,c3,&i);
    c3[0]=i;
    printf("%s\n%s\n",c1,c2);
    printf("%d",c3[0]);
    while (c3[val]!='\0'){
        printf ("%c",c3[val]);
        val++;
    }

    return 0;
}

movimenta(char origem[],char destino[],int *controle){
    int x = 0;
    if ((*controle)>1){x++;}
    while (origem[x] != '\0'){
        destino[(*controle)] = origem[x];
        (*controle)++;
        x++;
    }
    (*controle)--;
}
