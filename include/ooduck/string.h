/* string.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_STRING_H
#define __OODUCK_STRING_H

#include <ooduck/object.h>

const void *String (void);

typedef void * (*String_copy_m) (const void *);
typedef void  (*String_format_m) (void *, const char *, ...);
typedef size_t  (*String_len_m) (const void *);
typedef const char * (*String_cstr_m) (const void *);

#endif /* __OODUCK_STRING_H */