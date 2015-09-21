#ifndef __OODUCK_DEF_HASHMAP_H
#define __OODUCK_DEF_HASHMAP_H

/* definitions */

#include <ooduck/_defs/iterable.h>

struct Hashmap
{
    struct Iterable _;

    void *keys;
    void *values;
};

#endif /* __OODUCK_DEF_HASHMAP_H */
