#ifndef __OODUCK_OBJECT_H
#define __OODUCK_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

extern const void *Object;
extern const void *Class;

/* dynamic API */
typedef void * (*Object_ref_m) (void *);
typedef void (*Object_unref_m) (void *);

typedef void * (*Class_constructor_m) (void *, va_list *);
typedef void * (*Class_destructor_m) (void *);

/* static API */

bool isA (const void *_self, const void *class);
bool isOf (const void *_self, const void *class);
void *cast (const void *class, const void *_self);

const void *super (const void *_class);
void *method (const void *_self, const char *name);

const void *classOf (const void *_self);
size_t sizeOf (const void *_self);

void *new (const void *_class, ...);
void delete (void *_self);

void *ref (void *_self);
void unref (void *_self);

void ooduck_init (void);

#endif /* __OODUCK_OBJECT_H */