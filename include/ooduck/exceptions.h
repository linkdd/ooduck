/* exceptions.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_EXCEPTIONS_H
#define __OODUCK_EXCEPTIONS_H

#include <ooduck/e4c.h>

E4C_DECLARE_EXCEPTION (NotImplementedError);
E4C_DECLARE_EXCEPTION (AbstractError);

#endif /* __OODUCK_EXCEPTIONS_H */