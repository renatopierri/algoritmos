#include <stdio.h>
#include <stdlib.h>

#include "tda.h"



/*
 * The caller will handle allocation.
 * Provide the required information only
 */


size_t obj_size(void) {
    return sizeof(struct td);
}

void obj_setid(struct td *o, int i) {
    o->id = i;
}

int obj_getid(struct td *o) {
    return o->id;
}

