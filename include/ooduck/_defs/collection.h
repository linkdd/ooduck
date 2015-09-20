#ifndef __OODUCK_DEF_COLLECTION_H
#define __OODUCK_DEF_COLLECTION_H

/* definitions */

#include <ooduck/_defs/iterable.h>

struct Item
{
    struct Object _;

    struct Object *itptr;

    struct Item *prev;
    struct Item *next;
};

struct Collection
{
    struct Iterable _;

    struct Item *items;
    struct Item *head;
    struct Item *tail;
};

#endif /* __OODUCK_DEF_COLLECTION_H */
