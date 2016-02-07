/* string.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_VALUE_PRIV_H
#include <ooduck/value.h>
#include <ooduck/_defs/value.h>
#include <ooduck/_priv/value.h>

OODUCK_DEFINE_CLASS (
    Value,
    new (
        Class (), "Value",
        Object (), sizeof (struct Value),
        "__constructor__", Value_constructor,
        "__destructor__", Value_destructor,
        "equal", Value_equal,
        "get", Value_get,
        "set", Value_set,
        NULL
    )
)

/* implementation */

static void *Value_constructor (void *_self, va_list *app)
{
    void *valptr = va_arg (*app, void *);
    size_t valsz = va_arg (*app, size_t);

    Class_constructor_m ctor = method (super (Value ()), "__constructor__");
    struct Value *self = ctor (_self, app);

    self->val = NULL;

    Value_set (self, valptr, valsz);

    return self;
}

static void *Value_destructor (void *_self)
{
    struct Value *self = cast (Value (), _self);
    Class_destructor_m dtor = method (super (Value ()), "__destructor__");

    Value_set (self, NULL, 0);

    return dtor (self);
}

static bool Value_equal (const void *_self, const void *_other)
{
    struct Value *self = cast (Value (), _self);
    struct Value *other = cast (Value (), _other);

    return (self->size == other->size && memcmp (self->val, other->val, self->size) == 0);
}

static void Value_get (const void *_self, void *dest, size_t size)
{
    const struct Value *self = cast (Value (), _self);

    if (dest != NULL && self->val != NULL)
    {
        memcpy (dest, self->val, size);
    }
}

static void Value_set (void *_self, void *src, size_t size)
{
    struct Value *self = cast (Value (), _self);

    if (self->val != NULL)
    {
        free (self->val);
        self->val = NULL;
    }

    if (src != NULL)
    {
        self->val = calloc (1, size);
        memcpy (self->val, src, size);
    }
}
