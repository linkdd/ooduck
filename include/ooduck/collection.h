/* collection.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_COLLECTION_H
#define __OODUCK_COLLECTION_H

#include <ooduck/iterable.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class Collection
 * \extends Iterable
 * \see Item
 * \brief Collection of item.
 */
const void *Collection (void);

/**
 * \class Item
 * \extends Object
 * \brief Collection item.
 *
 * Implements a doubly linked list of Item objects.
 */
const void *Item (void);

/** @} */

/**
 * \fn void Collection::clear (void *self)
 * \memberof Collection
 * \brief Remove all items from collection.
 * \param self Collection object.
 */
typedef void (*Collection_clear_m) (void *);

/**
 * \fn void Collection::add (void *self, const void *object)
 * \memberof Collection
 * \brief Add object to collection if not already in it.
 * \param self Collection object.
 * \param object Object instance (will be referenced).
 *
 * The object will be encapsulated in ``Item`` object.
 * Calls ``Collection::contains()``.
 */
typedef void (*Collection_add_m) (void *, const void *);

/**
 * \fn void Collection::del (void *self, const void *object)
 * \memberof Collection
 * \brief Remove item from collection.
 * \param self Collection object.
 * \param object Object instance (will be unreferenced).
 *
 * Does nothing if ``object`` is not in the collection.
 */
typedef void (*Collection_del_m) (void *, const void *);

/**
 * \fn bool Collection::contains (
 * \param object Object instance (will be unreferenced).void *self, const void *object)
 * \memberof Collection
 * \brief Check if ``object`` is in the collection.
 * \param self Collection object.
 * \param object Object instance.
 * \return ``TRUE`` if object is in collection, ``FALSE`` otherwise.
 *
 * Calls ``Object::equal()`` to determine if ``object`` match any items.
 */
typedef bool (*Collection_contains_m) (void *, const void *);

/**
 * \fn void *Item::__constructor__ (void *self, void *object)
 * \memberof Item
 * \brief Build new Item instance.
 * \param self Item object.
 * \param object Object instance to encapsulate.
 * \return Initialized instance.
 */

/**
 * \fn void *Item::deref (void *self)
 * \memberof Item
 * \brief Get encapsulated object
 * \param self Item object.
 * \return Object instance.
 */
typedef void *(*Item_deref_m) (void *);

#endif /* __OODUCK_COLLECTION_H */