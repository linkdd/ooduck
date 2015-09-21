/* _priv/collection.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_COLLECTION_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Collection_constructor (void *_self, va_list *app);
static void *Collection_destructor (void *_self);

static void *Collection_next (void *_self, const void *iterator);
static void Collection_clear (void *_self);
static void Collection_add (void *_self, const void *item);
static void Collection_del (void *_self, const void *item);
static bool Collection_contains (void *_self, const void *item);

static struct Item *_Collection_getitem (void *_self, const void *item);

static void *Item_constructor (void *_self, va_list *app);
static void *Item_destructor (void *_self);

static void *Item_deref (void *_self);
