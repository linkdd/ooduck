/* value.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_VALUE_H
#define __OODUCK_VALUE_H

#include <ooduck/object.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class Value
 * \extends Object
 * \brief Classic C types encapsulation.
 *
 * Using ``memcpy()`` to copy memory of C object to OODuck object.
 * Using ``memcmp()`` to determine equality.
 */
const void *Value (void);

/** @} */

/**
 * \fn void *Value::__constructor__ (void *self, void *ptr, size_t size)
 * \memberof Value
 * \brief Build new value from pointer.
 * \param self Value instance.
 * \param ptr Pointer to the C object to copy.
 * \param size Size of the C object to copy.
 * \return Initialized instance.
 *
 * Calls ``Value::set()``.
 */

/**
 * \fn void Value::get (const void *self, void *dest, size_t size)
 * \memberof Value
 * \brief Copy encapsulated object to ``dest``.
 * \param self Value instance.
 * \param dest Destination (must be pre-allocated).
 * \param size Size of the C object.
 */
typedef void (*Value_get_m) (const void *, void *, size_t);

/**
 * \fn void Value::set (void *self, void *src, size_t size)
 * \memberof Value
 * \brief Encapsulate new object from ``src``.
 * \param self Value instance.
 * \param src C object to copy.
 * \param size Size of the C object.
 */
typedef void (*Value_set_m) (void *, void *, size_t);

#endif /* __OODUCK_VALUE_H */