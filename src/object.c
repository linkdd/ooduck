#define __OODUCK_OBJECT_PRIV_H
#include <ooduck/object.h>
#include <ooduck/_defs/object.h>
#include <ooduck/_priv/object.h>

const void *Object = object;
const void *VTableEntry = object + 1;
const void *Class = object + 2;

void ooduck_init (void)
{
    int i;

    struct VTableEntry **_Object = calloc (
        N_OBJECT_VTABLE_STATIC_ENTRIES + 1,
        sizeof (struct VTableEntry *)
    );
    struct VTableEntry **_VTableEntry = calloc (
        N_VTABLEENTRY_VTABLE_STATIC_ENTRIES + 1,
        sizeof (struct VTableEntry *)
    );
    struct VTableEntry **_Class = calloc (
        N_CLASS_VTABLE_STATIC_ENTRIES + 1,
        sizeof (struct VTableEntry *)
    );

    for (i = 0; i < N_OBJECT_VTABLE_STATIC_ENTRIES; ++i)
    {
        _Object[i] = &(ObjectVTable[i]);
    }

    for (i = 0; i < N_VTABLEENTRY_VTABLE_STATIC_ENTRIES; ++i)
    {
        _VTableEntry[i] = &(VTableEntryVTable[i]);
    }

    for (i = 0; i < N_CLASS_VTABLE_STATIC_ENTRIES; ++i)
    {
        _Class[i] = &(ClassVTable[i]);
    }

    object[0].vtable = _Object;
    object[1].vtable = _VTableEntry;
    object[2].vtable = _Class;
}

bool isA (const void *_self, const void *class)
{
    return _self && classOf (_self) == class;
}

bool isOf (const void *_self, const void *class)
{
    if (_self)
    {
        const struct Class *selfClass = classOf (_self);

        if (selfClass != Object)
        {
            while (selfClass != class)
            {
                if (selfClass != Object)
                {
                    selfClass = super (selfClass);
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

void *cast (const void *class, const void *_self)
{
    assert (isOf (_self, class));
    return (void *) _self;
}

const void *super (const void *_class)
{
    const struct Class *class = _class;
    return class->super;
}

void *method (const void *_class, const char *name)
{
    const struct Class *class = cast (Class, _class);
    int i;

    for (i = 0; class->vtable[i] != NULL; ++i)
    {
        if (!strcmp (class->vtable[i]->name, name))
        {
            return class->vtable[i]->func;
        }
    }

    if (class == Object)
    {
        return NULL;
    }

    return method (super (class), name);
}

const void *classOf (const void *_self)
{
    const struct Object *self = _self;
    assert (self->class != NULL);
    return self->class;
}

size_t sizeOf (const void *_self)
{
    const struct Class *class = classOf (_self);
    return class->size;
}

void *new (const void *_class, ...)
{
    const struct Class *class = cast (Class, _class);
    Class_constructor_m ctor = NULL;
    struct Object *obj = NULL;
    va_list ap;

    obj = calloc (1, class->size);
    obj->class = class;

    va_start (ap, _class);
    ctor = method (class, "__constructor__");
    obj = ctor (obj, &ap);
    va_end (ap);

    return obj;
}

void delete (void *_self)
{
    if (_self)
    {
        Class_destructor_m dtor = method (classOf (_self), "__destructor__");
        free (dtor (_self));
    }
}

void *ref (void *_self)
{
    Object_ref_m _ref = method (classOf (_self), "ref");
    return _ref (_self);
}

void unref (void *_self)
{
    Object_unref_m _unref = method (classOf (_self), "unref");
    _unref (_self);
}

/* implementation */
static void *Object_constructor (void *_self, va_list *app)
{
    struct Object *self = cast (Object, _self);
    self->refcount = 1;
    return _self;
}

static void *Object_destructor (void *_self)
{
    return _self;
}

static void *Object_ref (void *_self)
{
    struct Object *self = cast (Object, _self);
    self->refcount++;
    return self;
}

static void Object_unref (void *_self)
{
    struct Object *self = cast (Object, _self);
    self->refcount--;

    if (self->refcount <= 0)
    {
        delete (self);
    }
}

static bool Object_equal (const void *_self, const void *other)
{
    return (_self == other);
}

static void *VTableEntry_constructor (void *_self, va_list *app)
{
    struct VTableEntry *self = _self;

    self->name = strdup (va_arg (*app, char *));
    self->func = va_arg (*app, void *);

    return self;
}

static void *VTableEntry_destructor (void *_self)
{
    struct VTableEntry *self = cast (VTableEntry, _self);

    free (self->name);

    return self;
}

static struct VTableEntry **VTableEntry_add (
    struct VTableEntry **entries,
    int nentries,
    char *name,
    void *func)
{
    struct VTableEntry **new_entries = realloc (
        entries,
        sizeof (struct VTableEntry *) * (nentries + 1)
    );
    new_entries[nentries - 1] = new (VTableEntry, name, func);
    new_entries[nentries] = NULL;

    return new_entries;
}

static void *Class_constructor (void *_self, va_list *app)
{
    struct Class *self = _self;
    int nentries = 1;
    struct VTableEntry **entries = calloc (1, sizeof (struct VTableEntry *));
    char *name = NULL;

    self->name = va_arg (*app, char *);
    self->super = cast (Class, va_arg (*app, void *));
    self->size = va_arg (*app, size_t);

    while ((name = va_arg (*app, char *)) != NULL)
    {
        void *func = va_arg (*app, void *);
        entries = VTableEntry_add (entries, nentries++, name, func);
    }

    self->vtable = entries;

    return self;
}

static void *Class_destructor (void *_self)
{
    struct Class *self = cast (Class, _self);
    fprintf (stderr, "%s: cannot destroy class\n", self->name);
    return NULL;
}
