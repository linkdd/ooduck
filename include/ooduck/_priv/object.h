#ifndef __OODUCK_OBJECT_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Object_constructor (void *_self, va_list *app);
static void *Object_destructor (void *_self);
static void *Object_ref (void *_self);
static void Object_unref (void *_self);

static void *VTableEntry_constructor (void *_self, va_list *app);
static void *VTableEntry_destructor (void *_self);
static struct VTableEntry **VTableEntry_add (struct VTableEntry **entries,
                                             int nentries,
                                             char *name,
                                             void *func);

static void *Class_constructor (void *_self, va_list *app);
static void *Class_destructor (void *_self);

/* static classes */
static struct Class object[] =
{
    {
        { object + 2 },
        "Object",
        object, sizeof (struct Object),
        NULL
    },
    {
        { object + 2 },
        "VTableEntry",
        object, sizeof (struct VTableEntry),
        NULL
    },
    {
        { object + 2},
        "Class",
        object, sizeof (struct Class),
        NULL
    }
};

/* static vtables */
#define N_OBJECT_VTABLE_STATIC_ENTRIES 4

static struct VTableEntry ObjectVTable[N_OBJECT_VTABLE_STATIC_ENTRIES] =
{
    { { object + 2 }, "__constructor__", Object_constructor },
    { { object + 2 }, "__destructor__", Object_destructor },
    { { object + 2 }, "ref", Object_ref },
    { { object + 2 }, "unref", Object_unref }
};

#define N_VTABLEENTRY_VTABLE_STATIC_ENTRIES 3

static struct VTableEntry VTableEntryVTable[N_VTABLEENTRY_VTABLE_STATIC_ENTRIES] =
{
    { { object + 2 }, "__constructor__", VTableEntry_constructor },
    { { object + 2 }, "__destructor__", VTableEntry_destructor },
    { { object + 2 }, "add", VTableEntry_add },
};

#define N_CLASS_VTABLE_STATIC_ENTRIES 2

static struct VTableEntry ClassVTable[N_CLASS_VTABLE_STATIC_ENTRIES] =
{
    { { object + 2 }, "__constructor__", Class_constructor },
    { { object + 2 }, "__destructor__", Class_destructor }
};
