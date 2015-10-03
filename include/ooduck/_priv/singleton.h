/* _priv/singleton.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_SINGLETON_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static bool Singleton_alloc (void *_class, void **instance);
static void *Singleton_constructor (void *_self, va_list *app);
