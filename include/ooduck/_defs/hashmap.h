/* _defs/hashmap.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

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
