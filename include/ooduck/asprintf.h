/* asprintf.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_ASPRINTF_H
#define __OODUCK_ASPRINTF_H

/**
 * \addtogroup static
 * @{
 */

/**
 * \fn int vasprintf (char **ret, const char *fmt, va_list args)
 * \brief Allocate new formatted string.
 * \param ret Address to store newly allocated string.
 * \param fmt Format string
 * \param args Argument list used to format the string.
 * \return Number of characters written in string.
 */
int vasprintf (char **ret, const char *fmt, va_list args);


/**
 * \fn int asprintf (char **ret, const char *fmt, ...)
 * \brief Allocate new formatted string.
 * \param ret Address to store newly allocated string.
 * \param fmt Format string
 * \param ... Argument list used to format the string.
 * \return Number of characters written in string.
 *
 * Calls vasprintf().
 */
int asprintf (char **ret, const char *fmt, ...);

/** @} */

#endif /* __OODUCK_ASPRINTF_H */
