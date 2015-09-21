/* _defs/string.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

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
