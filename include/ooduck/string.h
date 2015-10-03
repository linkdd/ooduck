/* string.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_STRING_H
#define __OODUCK_STRING_H

#include <ooduck/object.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class String
 * \extends Object
 * \brief String utility class.
 */
const void *String (void);

/** @} */

/**
 * \fn void *String::__constructor__ (void *self, char *data)
 * \memberof String
 * \brief Build new string from data.
 * \param self String instance.
 * \param data String content or NULL.
 * \return Initialized instance.
 */

/**
 * \fn void *String::copy (const void *self)
 * \memberof String
 * \brief Copy string in a new String object.
 * \param self String object to copy.
 * \return New String object.
 */
typedef void * (*String_copy_m) (const void *);

/**
 * \fn void String::format (void *self, const char *fmt, ...)
 * \memberof String
 * \brief Format String content.
 * \param self String object.
 * \param fmt Format string.
 * \param ... Argument list used to format string.
 *
 * Uses vasprintf().
 */
typedef void  (*String_format_m) (void *, const char *, ...);

/**
 * \fn size_t String::len (const void *self)
 * \memberof String
 * \brief Get String length.
 * \param self String object.
 * \return String length.
 */
typedef size_t  (*String_len_m) (const void *);

/**
 * \fn const char *String::cstr (const void *self)
 * \memberof String
 * \brief Get String content.
 * \param self String object.
 * \return Pointer to String content.
 */
typedef const char * (*String_cstr_m) (const void *);

#endif /* __OODUCK_STRING_H */