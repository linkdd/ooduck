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
        "next", Iterable_next,
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

static void *Iterable_next (void *_self, const void *iterator)
{
    throw (NotImplementedError, "Iterable: next() method not implemented");
    return NULL;
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

    self->current = nextm (self->iterable, self);

    return Iterator_get (self);
}

static void *Iterator_get (const void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);

    return self->current;
}
