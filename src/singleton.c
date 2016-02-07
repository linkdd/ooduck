/* singleton.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define __OODUCK_SINGLETON_PRIV_H
#include <ooduck/singleton.h>
#include <ooduck/_defs/singleton.h>
#include <ooduck/_priv/singleton.h>

OODUCK_DEFINE_CLASS (
    Singleton,
    new (
        Class (), "Singleton",
        Class (), sizeof (struct Singleton),
        "__alloc__", Singleton_alloc,
        "__constructor__", Singleton_constructor,
        NULL
    )
)

/* implementation */

static bool Singleton_alloc (void *_class, void **instance)
{
    struct Singleton *class = cast (Singleton (), _class);
    bool did_alloc = false;

    assert (instance != NULL);

    if (class->instance == NULL)
    {
        Class_alloc_m alloc = method (super (Singleton ()), "__alloc__");

        did_alloc = alloc (class, &(class->instance));
    }

    *instance = class->instance;

    return did_alloc;
}

static void *Singleton_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Singleton ()), "__constructor__");
    struct Singleton *self = ctor (_self, app);

    self->instance = NULL;

    return self;
}
