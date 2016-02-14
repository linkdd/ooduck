/* iterable.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_ITERABLE_H
#define __OODUCK_ITERABLE_H

#include <ooduck/object.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class Iterable
 * \extends Object
 * \brief Abstract class which allow to iterate over object.
 * \throws AbstractError
 *
 * <b>MUST</b> be subclassed.
 */
OODUCK_DECLARE_CLASS (Iterable);

/**
 * \class IterableNode
 * \extends Object
 * \brief Abstract class to encapsulate item objects.
 *
 * <b>MUST</b> be subclassed.
 */
OODUCK_DECLARE_CLASS (IterableNode);

/**
 * \class Iterator
 * \extends Object
 * \relates Iterable
 * \brief Object used to iterate over Iterable.
 */
OODUCK_DECLARE_CLASS (Iterator);

/** @} */

/**
 * \fn bool Iterable::contains (const void *self, const void *object)
 * \param object Object instance (will be unreferenced).void *self, const void *object)
 * \memberof Iterable
 * \brief Check if ``object`` is in the collection.
 * \param self Iterable object.
 * \param object Object instance.
 * \return ``TRUE`` if object is in collection, ``FALSE`` otherwise.
 *
 * <b>MUST</b> be implemented in a subclass.
 */
typedef bool (*Iterable_contains_m) (const void *, const void *);

/**
 * \fn void Iterable::clear (void *self)
 * \memberof Iterable
 * \brief Remove all items from iterable.
 * \param self Iterable object.
 *
 * <b>MUST</b> be implemented in a subclass.
 */
typedef void (*Iterable_clear_m) (void *);

/**
 * \fn void *Iterable::next (const void *self, const void *iterator)
 * \memberof Iterable
 * \param self Iterable object.
 * \param iterator Iterator object pointing to current item.
 * \return Next item.
 * \throws NotImplementedError
 *
 * <b>MUST</b> be implemented in a subclass.
 */
typedef void *(*Iterable_next_m) (const void *, const void *);

/**
 * \fn void *IterableNode::__constructor__ (void *self, const void *data)
 * \memberof IterableNode
 * \brief Build new node.
 * \param self IterableNode instance.
 * \param data Data to encapsulate.
 * \return Initialized instance.
 */

/**
 * \fn void *IterableNode::data (const void *self)
 * \memberof IterableNode
 * \brief Get a new reference on encapsulated data.
 * \param self IterableNode instance.
 * \return New reference on encapsulated data.
 */
typedef void *(*IterableNode_data_m) (const void *);

/**
 * \fn void *Iterator::__constructor__ (void *self, const void *iterable)
 * \memberof Iterator
 * \brief Build new iterator from iterable.
 * \param self Iterator instance.
 * \param iterable Iterable object.
 * \return Initialized instance.
 */

/**
 * \fn void *Iterator::next (void *self)
 * \memberof Iterator
 * \brief Get next item in Iterable object.
 * \param self Iterator object.
 * \return Next item or ``NULL`` if no more items.
 *
 * Calls ``Iterable::next()``.
 */
typedef void *(*Iterator_next_m) (void *);

/**
 * \fn void *Iterator::get (const void *self)
 * \memberof Iterator
 * \brief Get current item.
 * \param self Iterator object./
 * \return Current item or ``NULL`` if ``Iterator::next()`` hasn't been called (or no more items).
 */
typedef void *(*Iterator_get_m) (const void *);

#endif /* __OODUCK_ITERABLE_H */