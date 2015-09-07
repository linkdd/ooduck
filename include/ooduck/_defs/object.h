#ifndef __OODUCK_DEF_OBJECT_H
#define __OODUCK_DEF_OBJECT_H

/* definitions */
struct Object
{
    const struct Class *class;

    int refcount;
};

struct VTableEntry
{
    const struct Object _;

    char *name;
    void *func;
};

struct Class
{
    const struct Object _;
    const char *name;
    const struct Class *super;
    size_t size;

    struct VTableEntry **vtable;
};

#endif /* __OODUCK_DEF_OBJECT_H */
