/* list.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_LIST_PRIV_H
#include <ooduck/list.h>
#include <ooduck/_defs/list.h>
#include <ooduck/_priv/list.h>

OODUCK_DEFINE_CLASS (
    List,
    new (
        Class (), "List",
        Iterable (), sizeof (struct List),
        "__constructor__", List_constructor,
        "__destructor__", List_destructor,
        "contains", List_contains,
        "clear", List_clear,
        "next", List_next,
        "length", List_length,
        "get", List_get,
        "append", List_append,
        "preprend", List_prepend,
        "insert", List_insert,
        "pop", List_pop,
        NULL
    )
)

OODUCK_DEFINE_CLASS (
    ListNode,
    new (
        Class (), "ListNode",
        IterableNode (), sizeof (ListNode_t),
        NULL
    )
)

/* implementatioon */

static void *List_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (List ()), "__constructor__");
    struct List *self = ctor (_self, app);

    TAILQ_INIT (&(self->items));
}

static void *List_destructor (void *_self)
{
    struct List *self = cast (List (), _self);
    Class_destructor_m dtor = method (super (List ()), "__destructor__");

    Iterable_clear_m clear = method (classOf (self), "clear");
    clear (self);

    return dtor (self);
}

static bool List_contains (const void *_self, const void *item)
{
    return (_List_get_node_by_item (_self, item) != NULL);
}

static void List_clear (void *_self)
{
    struct List *self = cast (List (), _self);

    while (!TAILQ_EMPTY (&(self->items)))
    {
        void *node = TAILQ_FIRST (&(self->items));
        _List_del_node (self, node);
    }
}

static void *List_next (const void *_self, const void *iterator)
{
    struct List *self = cast (List (), _self);

    ListNode_t *next_node = NULL;

    Iterator_get_m get = method (classOf (iterator), "get");
    void *current = get (iterator);

    if (current != NULL)
    {
        ListNode_t *node = _List_get_node_by_item (self, current);
        next_node = TAILQ_NEXT (node, next);
    }
    else
    {
        next_node = TAILQ_FIRST (&(self->items));
    }

    if (next_node != NULL)
    {
        IterableNode_data_m data = method (classOf (next_node), "data");
        return data (next_node);
    }

    return NULL;
}

static size_t List_length (const void *_self)
{
    struct List *self = cast (List (), _self);
    return self->length;
}

static void *List_get (const void *_self, int idx)
{
    struct List *self = cast (List (), _self);
    void *node = _List_get_node_by_idx (self, idx);

    if (node != NULL)
    {
        IterableNode_data_m data = method (classOf (node), "data");
        return data (node);
    }

    return NULL;
}

static void List_append (void *_self, const void *item)
{
    struct List *self = cast (List (), _self);
    ListNode_t *node = cast (ListNode (), _List_new_node (self, item));

    TAILQ_INSERT_TAIL (&(self->items), node, next);
}

static void List_prepend (void *_self, const void *item)
{
    struct List *self = cast (List (), _self);
    ListNode_t *node = cast (ListNode (), _List_new_node (self, item));

    TAILQ_INSERT_HEAD (&(self->items), node, next);
}

static void List_insert (void *_self, int idx, const void *item)
{
    struct List *self = cast (List (), _self);

    if (idx == 0 || idx <= -self->length)
    {
        List_prepend_m prepend = method (classOf (self), "prepend");
        prepend (self, item);
    }
    else if (idx >= self->length)
    {
        List_append_m append = method (classOf (self), "append");
        append (self, item);
    }
    else
    {
        ListNode_t *new_node = cast (ListNode (), _List_new_node (self, item));
        ListNode_t *next_node = cast (ListNode (), _List_get_node_by_idx (self, idx));

        TAILQ_INSERT_BEFORE (next_node, new_node, next);
    }
}

static void *List_pop (void *_self, int idx)
{
    struct List *self = cast (List (), _self);
    void *node = _List_get_node_by_idx (self, idx);
    void *item = NULL;

    if (node != NULL)
    {
        IterableNode_data_m data = method (classOf (node), "data");
        item = data (node);
        _List_del_node (self, node);
    }

    return item;
}


static void *_List_new_node (void *_self, const void *item)
{
    struct List *self = cast (List (), _self);

    self->length++;

    return new (ListNode (), item);
}

static void *_List_get_node_by_idx (const void *_self, int idx)
{
    struct List *self = cast (List (), _self);
    ListNode_t *node = NULL;
    int i;

    if (idx >= 0 && idx < self->length)
    {
        node = TAILQ_FIRST (&(self->items));

        for (i = 0; i < idx; ++i)
        {
            node = TAILQ_NEXT (node, next);
        }
    }
    else if (idx < 0 && idx > -self->length)
    {
        node = TAILQ_LAST (&(self->items), ListNodes);

        for (i = 0; i > idx; --i)
        {
            node = TAILQ_PREV (node, ListNodes, next);
        }
    }

    return node;
}

static void *_List_get_node_by_item (const void *_self, const void *item)
{
    struct List *self = cast (List (), _self);
    ListNode_t *node = NULL;

    TAILQ_FOREACH (node, &(self->items), next)
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

static void _List_del_node (void *_self, void *_node)
{
    struct List *self = cast (List (), _self);
    ListNode_t *node = cast (ListNode (), _node);

    TAILQ_REMOVE (&(self->items), node, next);
    delete (node);

    self->length--;
}
