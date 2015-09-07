#ifndef __OODUCK_STRING_H
#define __OODUCK_STRING_H

#include <ooduck/object.h>

const void *String (void);

typedef void * (*String_constructor_m) (void *, va_list *);
typedef void * (*String_destructor_m) (void *);

typedef bool  (*String_equal_m) (const void *, const void *);
typedef void * (*String_copy_m) (const void *);
typedef void  (*String_format_m) (void *, const char *, ...);
typedef size_t  (*String_len_m) (const void *);
typedef const char * (*String_cstr_m) (const void *);

#endif /* __OODUCK_STRING_H */