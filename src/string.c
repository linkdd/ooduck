#define __OODUCK_STRING_PRIV_H
#include <ooduck/string.h>
#include <ooduck/_defs/string.h>
#include <ooduck/_priv/string.h>
#include <ooduck/asprintf.h>

static const void *_String = NULL;

const void *String (void)
{
    if (_String == NULL)
    {
        _String = new (
            Class, "String",
            Object, sizeof (struct String),
            "__constructor__", String_constructor,
            "__destructor__", String_destructor,
            "__equal__", String_equal,
            "copy", String_copy,
            "format", String_format,
            "len", String_len,
            "cstr", String_cstr,
            NULL
        );
    }

    return _String;
}

/* implementation */

static void *String_constructor (void *_self, va_list *app)
{
    char *data = va_arg (*app, char *);
    Class_constructor_m ctor = method (super (String ()), "__constructor__");
    struct String *self = ctor (_self, app);

    if (data)
    {
        self->data = strdup (data);
    }

    return self;
}

static void *String_destructor (void *_self)
{
    struct String *self = cast (String (), _self);
    
    free (self->data);

    return self;
}

static bool String_equal (const void *_self, const void *_other)
{
    String_cstr_m a, b;

    a = method (classOf (_self), "cstr");
    b = method (classOf (_other), "cstr");

    return (!strcmp (a (_self), b (_other)));
}

static void *String_copy (const void *_self)
{
    String_cstr_m cstr = method (classOf (_self), "cstr");

    return new (String (), cstr (_self));
}

static void String_format (void *_self, const char *fmt, ...)
{
    struct String *self = cast (String (), _self);
    va_list ap;
    
    if (self->data)
    {
        free (self->data);
    }

    if (fmt == NULL)
    {
        self->data = NULL;
        return;
    }

    va_start (ap, fmt);
    vasprintf (&(self->data), fmt, ap);
    va_end (ap);
}

static size_t String_len (const void *_self)
{
    String_cstr_m cstr = method (classOf (_self), "cstr");
    const char *data = cstr (data);

    if (data)
    {
        return strlen (data);
    }

    return 0;
}

static const char *String_cstr (const void *_self)
{
    const struct String *self = cast (String (), _self);
    return self->data;
}
