/* asprintf.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* if va_copy isn't defined, use GCC macro __va_copy() */
#ifndef va_copy
#   define va_copy(d,s)      __va_copy(d,s)
#endif

int vasprintf (char **ret, const char *fmt, va_list args)
{
    va_list ap;
    char c = 0;
    int size = 0;

    if (ret == NULL)
    {
        return -1;
    }

    /* copy args list before call to *printf() */
    va_copy (ap, args);
    size = vsnprintf (&c, 1, fmt, args);
    *ret = calloc (size + 1, 1);

    if (!(*ret))
    {
        return -1;
    }

    /* here, we use the copied list */
    size = vsprintf (*ret, fmt, ap);

    return size;
}

int asprintf (char **ret, const char *fmt, ...)
{
    va_list args;
    int sz = 0;

    va_start (args, fmt);
    sz = vasprintf (ret, fmt, args);
    va_end (args);

    return sz;
}
