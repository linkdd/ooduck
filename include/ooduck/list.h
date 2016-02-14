/* list.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_LIST_H
#define __OODUCK_LIST_H

#include <ooduck/collection.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class List
 * \extends Iterable
 * \brief List implementation.
 */
OODUCK_DECLARE_CLASS (List);

/**
 * \class ListNode
 * \extends IterableNode
 * \brief ListNode implementation.
 */
OODUCK_DECLARE_CLASS (ListNode);

/** @} */

/**
 * \fn size_t List::length (const void *self)
 * \memberof List
 * \brief Get list length.
 * \param self List object.
 * \return List size.
 */
typedef size_t (*List_length_m) (const void *);

/**
 * \fn void *List::get (const void *self, int idx)
 * \memberof List
 * \brief Get list item.
 * \param self List object.
 * \param idx Item index.
 * \return Item object.
 */
typedef void *(*List_get_m) (const void *, int);

/**
 * \fn void List::append (void *self, const void *obj)
 * \memberof List
 * \brief Append object to list.
 * \param self List object.
 * \param obj Object to append.
 */
typedef void (*List_append_m) (void *, const void *);

/**
 * \fn void List::preprend (void *self, const void *obj)
 * \memberof List
 * \brief Prepend object to list.
 * \param self List object.
 * \param obj Object to preprend.
 */
typedef void (*List_prepend_m) (void *, const void *);

/**
 * \fn void List::insert (void *self, int i, const void *obj)
 * \memberof List
 * \brief Insert object into list.
 * \param self List object.
 * \param i Position at which the object must be inserted.
 * \param obj Object to insert.
 */
typedef void (*List_insert_m) (void *, int, const void *);

/**
 * \fn void *List::pop (const void *self, int i)
 * \memberof List
 * \brief Remove object from list and return it.
 * \param self List object.
 * \param i Position of the object to pop (or -1 for the last one)
 * \return Item object.
 */
typedef void *(*List_pop_m) (void *, int);

#endif /* __OODUCK_LIST_H */