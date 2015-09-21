/* iterable.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_ITERABLE_H
#define __OODUCK_ITERABLE_H

#include <ooduck/object.h>

const void *Iterable (void);

typedef void *(*Iterable_next_m) (void *, const void *);

const void *Iterator (void);

typedef void *(*Iterator_next_m) (void *);
typedef void *(*Iterator_get_m) (const void *);

#endif /* __OODUCK_ITERABLE_H */