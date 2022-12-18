#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct td {
    int id;
}td;


/*
 * The compiler considers struct obj an incomplete type. Incomplete types
 * can be used in declarations.
 */

size_t obj_size(void);

void obj_setid(struct td *, int);

int obj_getid(struct td *);

#endif // TDA_H_INCLUDED
