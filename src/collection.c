#define __OODUCK_COLLECTION_PRIV_H
#include <ooduck/collection.h>
#include <ooduck/_defs/collection.h>
#include <ooduck/_priv/collection.h>

static const void *_Collection = NULL;
static const void *_Item = NULL;

const void *Collection (void)
{
    if (_Collection == NULL)
    {
        _Collection = new (
            Class, "Collection",
            Iterable (), sizeof (struct Collection),
            "__constructor__", Collection_constructor,
            "__destructor__", Collection_destructor,
            "__next__", Collection_next,
            "clear", Collection_clear,
            "add", Collection_add,
            "del", Collection_del,
            "contains", Collection_contains,
            NULL
        );
    }

    return _Collection;
}

const void *Item (void)
{
    if (_Item == NULL)
    {
        _Item = new (
            Class, "Item",
            Object, sizeof (struct Item),
            "__constructor__", Item_constructor,
            "__destructor__", Item_destructor,
            "deref", Item_deref,
            NULL
        );
    }

    return _Item;
}

/* implementation */

static void *Collection_constructor (void *_self, va_list *app)
{
    Class_constructor_m ctor = method (super (Collection ()), "__constructor__");
    struct Collection *self = ctor (_self, app);

    self->items = NULL;
    self->head = NULL;
    self->tail = NULL;

    return self;
}

static void *Collection_destructor (void *_self)
{
    struct Collection *self = cast (Collection (), _self);

    Collection_clear (self);

    return self;
}

static void *Collection_next (void *_self, const void *iterator)
{
    struct Collection *self = cast (Collection (), _self);
    Iterator_get_m getm = method (classOf (iterator), "get");
    void *current = getm (iterator);

    if (current != NULL)
    {
        struct Item *item = cast (Item (), getm (iterator));

        return item->next;
    }

    return self->items;
}

static void Collection_clear (void *_self)
{
    struct Collection *self = cast (Collection (), _self);

    if (self->items != NULL)
    {
        while (self->items != NULL)
        {
            Collection_del (self, Item_deref (self->items));
        }
    }
}

static void Collection_add (void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);

    if (!Collection_contains (self, item))
    {
        void *itemobj = new (Item (), item);

        if (self->items == NULL)
        {
            self->items = itemobj;
            self->items->prev = NULL;
            self->items->next = NULL;

            self->head = self->items;
            self->tail = self->items;
        }
        else
        {
            self->tail->next = itemobj;
            self->tail->next->prev = self->tail;
            self->tail->next->next = NULL;
            self->tail = self->tail->next;
        }
    }
}

static void Collection_del (void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);
    struct Item *itemobj = _Collection_getitem (self, item);

    if (itemobj != NULL)
    {
        if (itemobj != self->head)
        {
            itemobj->prev->next = itemobj->next;
        }
        else
        {
            self->head = itemobj->next;
        }

        if (itemobj != self->tail)
        {
            itemobj->next->prev = itemobj->prev;
        }
        else
        {
            self->tail = itemobj->prev;
        }

        self->items = self->head;

        if (self->head == NULL || self->tail == NULL)
        {
            self->items = NULL;

            self->head = self->items;
            self->tail = self->items;
        }

        delete (itemobj);
    }
}

static bool Collection_contains (void *_self, const void *item)
{
    return _Collection_getitem (_self, item) != NULL;
}

static struct Item *_Collection_getitem (void *_self, const void *item)
{
    struct Collection *self = cast (Collection (), _self);
    struct Item *tmp = self->head;

    while (tmp != NULL)
    {
        void *obj = Item_deref (tmp);
        Object_equal_m cmp = method (classOf (obj), "__equal__");

        if (cmp (obj, item))
        {
            break;
        }

        tmp = tmp->next;
    }

    return tmp;
}

static void *Item_constructor (void *_self, va_list *app)
{
    void *obj = va_arg (*app, void *);
    Class_constructor_m ctor = method (super (Item ()), "__constructor__");
    struct Item *self = ctor (_self, app);

    self->itptr = ref (obj);

    return self;
}

static void *Item_destructor (void *_self)
{
    struct Item *self = cast (Item (), _self);

    unref (self->itptr);

    return self;
}

static void *Item_deref (void *_self)
{
    struct Item *self = cast (Item (), _self);

    return self->itptr;
}
