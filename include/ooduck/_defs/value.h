/* _defs/value.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_VALUE_H
#define __OODUCK_DEF_VALUE_H

/* definitions */

#include <ooduck/_defs/object.h>

struct Value
{
    struct Object _;

    void *val;
    size_t size;
};

#endif /* __OODUCK_DEF_VALUE_H */
