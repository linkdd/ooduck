/* _priv/iterable.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_ITERABLE_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Iterable_constructor (void *_self, va_list *app);
static void *Iterable_destructor (void *_self);

static bool Iterable_contains (const void *_self, const void *item);
static void Iterable_clear (void *_self);
static void *Iterable_next (const void *_self, const void *iterator);

static void *IterableNode_constructor (void *_self, va_list *app);
static void *IterableNode_destructor (void *_self);
static void *IterableNode_data (const void *_self);

static void *Iterator_constructor (void *_self, va_list *app);
static void *Iterator_destructor (void *_self);

static void *Iterator_next (void *_self);
static void *Iterator_get (const void *_self);
