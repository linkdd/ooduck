/* _defs/collection.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_DEF_COLLECTION_H
#define __OODUCK_DEF_COLLECTION_H

/* definitions */

#include <ooduck/_defs/iterable.h>
#include <sys/queue.h>

typedef struct CollectionNode_t
{
    struct IterableNode _;

    SLIST_ENTRY (CollectionNode_t) next;
} CollectionNode_t;

struct Collection
{
    struct Iterable _;

    SLIST_HEAD (, CollectionNode_t) items;
};

#endif /* __OODUCK_DEF_COLLECTION_H */
