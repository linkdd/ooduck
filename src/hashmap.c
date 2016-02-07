/* hashmap.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_HASHMAP_PRIV_H
#include <ooduck/hashmap.h>
#include <ooduck/_defs/hashmap.h>
#include <ooduck/_priv/hashmap.h>

OODUCK_DEFINE_CLASS (
    Hashmap,
    new (
        Class (), "Hashmap",
        Iterable (), sizeof (struct Hashmap),
        "__constructor__", Hashmap_constructor,
        "__destructor__", Hashmap_destructor,
        "next", Hashmap_next,
        "get", Hashmap_get,
        "set", Hashmap_set,
        "del", Hashmap_del,
        "keys", Hashmap_keys,
        "values", Hashmap_values,
        NULL
    )
)

/* implementation */

static void *Hashmap_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Hashmap ()), "__constructor__");
    struct Hashmap *self = ctor (_self, app);

    self->keys = new (Collection ());
    self->values = new (Collection ());

    return self;
}

static void *Hashmap_destructor (void *_self)
{
    struct Hashmap *self = cast (Hashmap (), _self);
    Class_destructor_m dtor = method (super (Hashmap ()), "__destructor__");

    delete (self->keys);
    delete (self->values);

    return dtor (self);
}

static void *Hashmap_next (void *_self, const void *iterator)
{
    struct Hashmap *self = cast (Hashmap (), _self);
    Iterable_next_m next = method (classOf (self->keys), "next");

    return next (self->keys, iterator);
}

static void *Hashmap_get (const void *_self, const void *key)
{
    struct Hashmap *self = cast (Hashmap (), _self);
    void *item = NULL;
    int i = 0;

    void *it = new (Iterator (), self);
    Iterator_next_m next = method (classOf (it), "next");

    /* look for the key */
    Object_equal_m equal = method (classOf (key), "equal");

    for (; (item = next (it)) != NULL && !equal (key, item); ++i);

    delete (it);

    /* the value is at the same position */
    it = new (Iterator (), self->values);

    for (; i >= 0; --i)
    {
        item = next (it);
    }

    delete (it);

    /* return value */
    return ref (item);
}

static void Hashmap_set (void *_self, const void *key, void *value)
{
    struct Hashmap *self = cast (Hashmap (), _self);

    Collection_contains_m contains = method (classOf (self->keys), "contains");
    Collection_add_m add = method (classOf (self->keys), "add");

    if (contains (self->keys, key))
    {
        Hashmap_del (self, key);
    }

    add (self->keys, key);
    add (self->values, value);
}

static void Hashmap_del (void *_self, const void *key)
{
    struct Hashmap *self = cast (Hashmap (), _self);

    Collection_contains_m contains = method (classOf (self->keys), "contains");
    Collection_del_m del = method (classOf (self->keys), "del");

    if (contains (self->keys, key))
    {
        void *oldvalue = Hashmap_get (self, key);
        del (self->keys, key);
        del (self->values, oldvalue);
    }
}

static void *Hashmap_keys (const void *_self)
{
    struct Hashmap *self = cast (Hashmap (), _self);
    return self->keys;
}

static void *Hashmap_values (const void *_self)
{
    struct Hashmap *self = cast (Hashmap (), _self);
    return self->values;
}
