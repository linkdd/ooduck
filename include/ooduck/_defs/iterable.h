/* _defs/iterable.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_ITERABLE_H
#define __OODUCK_DEF_ITERABLE_H

/* definitions */

#include <ooduck/_defs/object.h>

struct Iterable
{
    struct Object _;
};

struct IterableNode
{
    struct Object _;

    void *data;
};

struct Iterator
{
    struct Object _;

    struct Iterable *iterable;
    void *current;
};

#endif /* __OODUCK_DEF_ITERABLE_H */
