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
 * \brief Collection of item.
 */
OODUCK_DECLARE_CLASS (Collection);

/**
 * \class CollectionNode
 * \extends IterableNode
 * \brief Collection item.
 */
OODUCK_DECLARE_CLASS (CollectionNode);

/** @} */

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

#endif /* __OODUCK_COLLECTION_H */