/* object.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_OBJECT_H
#define __OODUCK_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include <ooduck/exceptions.h>

const void *Object (void);
const void *VTableEntry (void);
const void *Class (void);

/* dynamic API */
typedef void * (*Object_ref_m) (void *);
typedef void (*Object_unref_m) (void *);
typedef bool (*Object_equal_m) (const void *, const void *);

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