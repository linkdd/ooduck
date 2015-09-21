/* hashmap.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_HASHMAP_H
#define __OODUCK_HASHMAP_H

#include <ooduck/iterable.h>
#include <ooduck/collection.h>

const void *Hashmap (void);

typedef void *(*Hashmap_next_m) (void *, const void *);
typedef void *(*Hashmap_get_m) (const void *, const void *);
typedef void (*Hashmap_set_m) (void *, const void *, void *);
typedef void (*Hashmap_del_m) (const void *, const void *);
typedef void *(*Hashmap_keys_m) (const void *);
typedef void *(*Hashmap_values_m) (const void *);

#endif /* __OODUCK_HASHMAP_H */