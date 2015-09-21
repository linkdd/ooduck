/* _priv/hashmap.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_HASHMAP_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Hashmap_constructor (void *_self, va_list *app);
static void *Hashmap_destructor (void *_self);

static void *Hashmap_next (void *_self, const void *iterator);
static void *Hashmap_get (const void *_self, const void *key);
static void Hashmap_set (void *_self, const void *key, void *value);
static void Hashmap_del (void *_self, const void *key);
static void *Hashmap_keys (const void *_self);
static void *Hashmap_values (const void *_self);
