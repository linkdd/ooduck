/* collection.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_COLLECTION_PRIV_H
#include <ooduck/collection.h>
#include <ooduck/_defs/collection.h>
#include <ooduck/_priv/collection.h>

OODUCK_DEFINE_CLASS (
    Collection,
    new (
        Class (), "Collection",
        Iterable (), sizeof (struct Collection),
        "__constructor__", Collection_constructor,
        "__destructor__", Collection_destructor,
        "contains", Collection_contains,
        "clear", Collection_clear,
        "next", Collection_next,
        "add", Collection_add,
        "del", Collection_del,
        NULL
    )
)

OODUCK_DEFINE_CLASS (
    CollectionNode,
    new (
        Class (), "CollectionNode",
        IterableNode (), sizeof (CollectionNode_t),
        NULL
    )
)

/* implementation */

static void *Collection_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Collection ()), "__constructor__");
    struct Collection *self = ctor (_self, app);

    SLIST_INIT (&(self->items));

    return self;
}

static void *Collection_destructor (void *_self)
{
    struct Collection *self = cast (Collection (), _self);
    Class_destructor_m dtor = method (super (Collection ()), "__destructor__");

    Iterable_clear_m clear = method (classOf (self), "clear");
    clear (self);

    return dtor (self);
}

static bool Collection_contains (const void *_self, const void *item)
{
    return (_Collection_get_node (_self, item) != NULL);
}

static void Collection_clear (void *_self)
{
    struct Collection *self = cast (Collection (), _self);

    while (!SLIST_EMPTY (&(self->items)))
    {
        void *node = SLIST_FIRST (&(self->items));
        _Collection_del_node (self, node);
    }
}

static void *Collection_next (const void *_self, const void *iterator)
{
    struct Collection *self = cast (Collection (), _self);
    
    CollectionNode_t *next_node = NULL;

    Iterator_get_m get = method (classOf (iterator), "get");
    void *current = get (iterator);

    if (current != NULL)
    {
        CollectionNode_t *node = _Collection_get_node (self, current);
        next_node = SLIST_NEXT (node, next);
    }
    else
    {
        next_node = SLIST_FIRST (&(self->items));
    }

    if (next_node != NULL)
    {
        IterableNode_data_m data = method (classOf (next_node), "data");
        return data (next_node);
    }

    return NULL;
}

static void Collection_add (void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);
    Iterable_contains_m contains = method (classOf (self), "contains");

    if (!contains (self, item))
    {
        CollectionNode_t *node = new (CollectionNode (), item);
        SLIST_INSERT_HEAD (&(self->items), node, next);
    }
}

static void Collection_del (void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);
    Iterable_contains_m contains = method (classOf (self), "contains");

    if (contains (self, item))
    {
        void *node = _Collection_get_node (self, item);
        _Collection_del_node (self, node);
    }
}

static void *_Collection_get_node (const void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);
    CollectionNode_t *node = NULL;

    SLIST_FOREACH (node, &(self->items), next)
    {
        IterableNode_data_m data = method (classOf (node), "data");        
        void *d = data (node);

        Object_equal_m cmp = method (classOf (d), "equal");
        bool found = cmp (d, item);

        unref (d);

        if (found)
        {
            return node;
        }
    }

    return NULL;
}

static void _Collection_del_node (void *_self, void *_node)
{
    struct Collection *self = cast (Collection (), _self);
    CollectionNode_t *node = cast (CollectionNode (), _node);

    SLIST_REMOVE (&(self->items), node, CollectionNode_t, next);
    delete (node);
}
