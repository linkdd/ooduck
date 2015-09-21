/* exceptions.c -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <ooduck/exceptions.h>

E4C_DEFINE_EXCEPTION (NotImplementedError, "Not implemented", RuntimeException);
E4C_DEFINE_EXCEPTION (AbstractError, "Cannot instantiate abstract class", RuntimeException);
