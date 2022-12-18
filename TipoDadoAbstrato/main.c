#include <stdio.h>
#include "tda.h"



int main() {
int x,y;

td sbruble;

sbruble.id =5;

obj_setid(&sbruble, 88);
y = obj_getid(&sbruble);
x= obj_size();

printf("%d %d", x,y);
   return 0;
}



