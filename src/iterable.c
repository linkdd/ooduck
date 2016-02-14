/* iterable.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_ITERABLE_PRIV_H
#include <ooduck/iterable.h>
#include <ooduck/_defs/iterable.h>
#include <ooduck/_priv/iterable.h>

OODUCK_DEFINE_CLASS (
    Iterable,
    new (
        Class (), "Iterable",
        Object (), sizeof (struct Iterable),
        "__constructor__", Iterable_constructor,
        "__destructor__", Iterable_destructor,
        "contains", Iterable_contains,
        "clear", Iterable_clear,
        "next", Iterable_next,
        NULL
    )
)

OODUCK_DEFINE_CLASS (
    IterableNode,
    new (
        Class (), "IterableNode",
        Object (), sizeof (struct IterableNode),
        "__constructor__", IterableNode_constructor,
        "__destructor__", IterableNode_destructor,
        "data", IterableNode_data,
        NULL
    )
)

OODUCK_DEFINE_CLASS(
    Iterator,
    new (
        Class (), "Iterator",
        Object (), sizeof (struct Iterator),
        "__constructor__", Iterator_constructor,
        "__destructor__", Iterator_destructor,
        "next", Iterator_next,
        "get", Iterator_get,
        NULL
    )
)

/* implementation */

static void *Iterable_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Iterable ()), "__constructor__");
    struct Iterable *self = ctor (_self, app);

    if (isA (self, Iterable ()))
    {
        throw (AbstractError, "Iterable: cannot instantiate abstract class");
    }

    return self;
}

static void *Iterable_destructor (void *_self)
{
    struct Iterable *self = cast (Iterable (), _self);
    Class_destructor_m dtor = method (super (Iterable ()), "__destructor__");

    return dtor (self);
}

static bool Iterable_contains (const void *_self, const void *item)
{
    throw (NotImplementedError, "Iterable: contains() method not implemented");
    return false;
}

static void Iterable_clear (void *_self)
{
    throw (NotImplementedError, "Iterable: clear() method not implemented");
}

static void *Iterable_next (const void *_self, const void *iterator)
{
    throw (NotImplementedError, "Iterable: next() method not implemented");
    return NULL;
}

static void *IterableNode_constructor (void *_self, va_list *app)
{
    void *data = va_arg (*app, void *);
    Class_constructor_m ctor = method (super (IterableNode ()), "__constructor__");
    struct IterableNode *self = ctor (_self, app);
    self->data = ref (cast (Object (), data));

    return self;
}

static void *IterableNode_destructor (void *_self)
{
    struct IterableNode *self = cast (IterableNode (), _self);
    Class_destructor_m dtor = method (super (IterableNode ()), "__destructor__");

    unref (self->data);

    return dtor (self);
}

static void *IterableNode_data (const void *_self)
{
    struct IterableNode *self = cast (IterableNode (), _self);
    
    return ref (self->data);
}

static void *Iterator_constructor (void *_self, va_list *app)
{
    void *iterable = cast (Iterable (), va_arg (*app, void *));
    Class_constructor_m ctor = method (super (Iterator ()), "__constructor__");
    struct Iterator *self = ctor (_self, app);

    self->iterable = ref (iterable);
    self->current = NULL;

    return self;
}

static void *Iterator_destructor (void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);
    Class_destructor_m dtor = method (super (Iterator ()), "__destructor__");

    unref (self->iterable);

    return dtor (self);
}

static void *Iterator_next (void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);
    Iterable_next_m nextm = method (classOf (self->iterable), "next");
    Iterator_get_m get = method (classOf (self), "get");

    self->current = nextm (self->iterable, self);

    return get (self);
}

static void *Iterator_get (const void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);

    return self->current;
}
