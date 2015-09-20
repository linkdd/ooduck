#define __OODUCK_ITERABLE_PRIV_H
#include <ooduck/iterable.h>
#include <ooduck/_defs/iterable.h>
#include <ooduck/_priv/iterable.h>

static const void *_Iterable = NULL;
static const void *_Iterator = NULL;

const void *Iterable (void)
{
    if (_Iterable == NULL)
    {
        _Iterable = new (
            Class (), "Iterable",
            Object (), sizeof (struct Iterable),
            "__constructor__", Iterable_constructor,
            "__destructor__", Iterable_destructor,
            "__next__", Iterable_next,
            NULL
        );
    }

    return _Iterable;
}

const void *Iterator (void)
{
    if (_Iterator == NULL)
    {
        _Iterator = new (
            Class (), "Iterator",
            Object (), sizeof (struct Iterator),
            "__constructor__", Iterator_constructor,
            "__destructor__", Iterator_destructor,
            "next", Iterator_next,
            "get", Iterator_get,
            NULL
        );
    }

    return _Iterator;
}

/* implementation */

static void *Iterable_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Iterable ()), "__constructor__");
    struct Iterable *self = ctor (_self, app);

    if (isA (self, Iterable ()))
    {
        /* error: abstract class */
    }

    return self;
}

static void *Iterable_destructor (void *_self)
{
    struct Iterable *self = cast (Iterable (), _self);

    return self;
}

static void *Iterable_next (void *_self, const void *iterator)
{
    /* error: not implemented */
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

    unref (self->iterable);

    return self;
}

static void *Iterator_next (void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);
    Iterable_next_m nextm = method (classOf (self->iterable), "__next__");

    self->current = nextm (self->iterable, self);

    return Iterator_get (self);
}

static void *Iterator_get (const void *_self)
{
    struct Iterator *self = cast (Iterator (), _self);

    return self->current;
}
