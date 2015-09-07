#ifndef __OODUCK_DEF_STRING_H
#define __OODUCK_DEF_STRING_H

/* definitions */

#include <ooduck/_defs/object.h>

struct String
{
    struct Object _;

    char *data;
};

#endif /* __OODUCK_DEF_STRING_H */
