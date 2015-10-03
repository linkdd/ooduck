/* hashmap.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_HASHMAP_H
#define __OODUCK_HASHMAP_H

#include <ooduck/iterable.h>
#include <ooduck/collection.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class Hashmap
 * \extends Iterable
 * \see Collection
 * \brief Hashmap implementation.
 *
 * Uses a Collection for keys and values.
 */
const void *Hashmap (void);

/** @} */

/**
 * \fn void *Hashmap::get (const void *self, const void *key)
 * \brief Get object mapped to ``key``.
 * \param self Hashmap object.
 * \param key Object instance used to map value object.
 * \return Object instance mapped to ``key``, or ``NULL`` if not found.
 */
typedef void *(*Hashmap_get_m) (const void *, const void *);

/**
 * \fn void Hashmap::set (void *self, const void *key, void *value)
 * \brief Map ``value`` to ``key``.
 * \param self Hashmap object.
 * \param key Object instance used to map value object (will be referenced).
 * \param value Object instance (will be referenced).
 * \return Object instance mapped to ``key``, or ``NULL`` if not found.
 */
typedef void (*Hashmap_set_m) (void *, const void *, void *);

/**
 * \fn void Hashmap::del (void *self, const void *key)
 * \brief Unmap ``value`` from ``key``.
 * \param self Hashmap object.
 * \param key Object instance used to map value object (will be unreferenced).
 *
 * Value Object will be unreferenced.
 */
typedef void (*Hashmap_del_m) (void *, const void *);

/**
 * \fn void *Hashmap::keys (const void *self)
 * \brief Get keys collection.
 * \param self Hashmap object.
 * \return Collection instance containing all Hashmap keys.
 */
typedef void *(*Hashmap_keys_m) (const void *);

/**
 * \fn void *Hashmap::values (const void *self)
 * \brief Get values collection.
 * \param self Hashmap object.
 * \return Collection instance containing all Hashmap values.
 */
typedef void *(*Hashmap_values_m) (const void *);

#endif /* __OODUCK_HASHMAP_H */
