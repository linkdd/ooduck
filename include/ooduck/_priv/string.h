/* _priv/string.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_STRING_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *String_constructor (void *_self, va_list *app);
static void *String_destructor (void *_self);

static bool String_equal (const void *_self, const void *_other);
static void *String_copy (const void *_self);
static void String_format (void *_self, const char *fmt, ...);
static size_t String_len (const void *_self);
static const char *String_cstr (const void *_self);
