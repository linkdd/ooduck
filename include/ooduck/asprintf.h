/* asprintf.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_ASPRINTF_H
#define __OODUCK_ASPRINTF_H

int vasprintf (char **ret, const char *fmt, va_list args);
int asprintf (char **ret, const char *fmt, ...);

#endif /* __OODUCK_ASPRINTF_H */
