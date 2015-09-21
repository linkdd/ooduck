/* collection.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_COLLECTION_H
#define __OODUCK_COLLECTION_H

#include <ooduck/iterable.h>

const void *Collection (void);

typedef void (*Collection_clear_m) (void *);
typedef void (*Collection_add_m) (void *, const void *);
typedef void (*Collection_del_m) (void *, const void *);
typedef bool (*Collection_contains_m) (void *, const void *);

const void *Item (void);

typedef void *(*Item_deref_m) (void *);

#endif /* __OODUCK_COLLECTION_H */