/* _defs/list.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_LIST_H
#define __OODUCK_DEF_LIST_H

/* definitions */

#include <ooduck/_defs/iterable.h>
#include <sys/queue.h>

typedef struct ListNode_t
{
    struct IterableNode _;

    TAILQ_ENTRY (ListNode_t) next;
} ListNode_t;

struct List
{
    struct Iterable _;

    TAILQ_HEAD (ListNodes, ListNode_t) items;
    size_t length;
};

#endif /* __OODUCK_DEF_LIST_H */
