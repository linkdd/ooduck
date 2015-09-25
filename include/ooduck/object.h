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

/** \file */

/**
 * \class Object
 * \brief Base class for everything.
 */
const void *Object (void);

/**
 * \class VTableEntry
 * \extends Object
 * \brief Entry for dynamic VTable.
 */
const void *VTableEntry (void);

/**
 * \class Class
 * \extends Object
 * \brief Class used to build new class dynamically.
 */
const void *Class (void);

/**
 * \fn void *Object::ref (void *self)
 * \memberof Object
 * \brief Increment object's reference counter.
 * \param self Object instance.
 * \return Same Object instance.
 */
typedef void * (*Object_ref_m) (void *);

/**
 * \fn void *Object::unref (void *self)
 * \memberof Object
 * \brief Decrement object's reference counter, if equals 0, delete the object.
 * \param self Object instance.
 */
typedef void (*Object_unref_m) (void *);

/**
 * \fn bool Object::equal (const void *self, const void *other)
 * \memberof Object
 * \brief Check objects equality
 * \param self Object instance.
 * \param other Object instance.
 * \return ``TRUE`` if objects are equal, ``FALSE`` otherwise.
 */
typedef bool (*Object_equal_m) (const void *, const void *);

/**
 * \fn void *Class::__constructor__ (void *self, va_list *app)
 * \memberof Class
 * \brief Build new instance.
 * \param self Object instance.
 * \param app Constructor parameters.
 * \return Initialized instance.
 */
typedef void * (*Class_constructor_m) (void *, va_list *);

/**
 * \fn void *Class::__destructor__ (void *self)
 * \memberof Class
 * \brief Destroy instance.
 * \param self Object instance.
 * \return Instance.
 */
typedef void * (*Class_destructor_m) (void *);

/**
 * \fn bool isA (const void *self, const void *class)
 * \brief Check if object is an instance of class.
 * \param self Object instance.
 * \param class Class object.
 * \return ``TRUE`` if object is an instance of class, ``FALSE`` otherwise.
 */
bool isA (const void *_self, const void *class);

/**
 * \fn bool isOf (const void *self, const void *class)
 * \brief Check if object is an instance of class or any derivated class.
 * \param self Object instance.
 * \param class Class object.
 * \return ``TRUE`` if object is an instance of class/derivated class, ``FALSE`` otherwise.
 */
bool isOf (const void *_self, const void *class);

/**
 * \fn void *cast (const void *class, const void *self)
 * \brief Assert that object is of specified class.
 * \param class Class object.
 * \param self Object instance.
 * \return Casted object instance.
 */
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