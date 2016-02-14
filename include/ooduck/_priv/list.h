/* _priv/list.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_LIST_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *List_constructor (void *_self, va_list *app);
static void *List_destructor (void *_self);

static bool List_contains (const void *_self, const void *item);
static void List_clear (void *_self);
static void *List_next (const void *_self, const void *iterator);

static size_t List_length (const void *_self);
static void *List_get (const void *_self, int idx);
static void List_append (void *_self, const void *value);
static void List_prepend (void *_self, const void *value);
static void List_insert (void *_self, int idx, const void *value);
static void *List_pop (void *_self, int idx);

static void *_List_new_node (void *_self, const void *item);
static void *_List_get_node_by_idx (const void *_self, int idx);
static void *_List_get_node_by_item (const void *_self, const void *item);
static void _List_del_node (void *_self, void *_node);
