#ifndef __OODUCK_DEF_ITERABLE_H
#define __OODUCK_DEF_ITERABLE_H

/* definitions */

#include <ooduck/_defs/object.h>

struct Iterable
{
    struct Object _;
};

struct Iterator
{
    struct Object _;

    struct Iterable *iterable;
    void *current;
};

#endif /* __OODUCK_DEF_ITERABLE_H */
