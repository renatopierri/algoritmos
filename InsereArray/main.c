#include <stdio.h>
#include <stdlib.h>
int main()
{

    char ponteiro[5]="ABCDE";

    printf("Comandos equivalentes em C\n\n");

    printf("Considerando 'char ponteiro[5]=\"ABCDE\";'\n\n");

    printf("Primeiro endereco do ponteiro:%p \n\n",ponteiro);

    printf("Primeiro conteudo de ponteiro[0]: %c\n",ponteiro[0]);
    printf("Primeiro conteudo de   *ponteiro: %c\n\n",*ponteiro);

    printf("Conteudo de ponteiro[1]  : %c\n",ponteiro[1]);
    printf("Conteudo de *(ponteiro+1): %c\n\n",*(ponteiro+1));

    printf("Endereco de memoria de (&ponteiro[1]):%p\n",(&ponteiro[1]));
    printf("Endereco de memoria de (&ponteiro+1) :%p\n\n",(ponteiro+1));

  return 0;
}
