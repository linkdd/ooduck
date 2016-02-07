/* _priv/value.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_VALUE_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Value_constructor (void *_self, va_list *app);
static void *Value_destructor (void *_self);

static bool Value_equal (const void *_self, const void *_other);

static void Value_get (const void *_self, void *dest, size_t size);
static void Value_set (void *_self, void *src, size_t size);
