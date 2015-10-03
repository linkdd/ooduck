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

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class RuntimeError
 * \brief Baseclass for all exceptions.
 * \see Exceptions4C module.
 */

/**
 * \class NotImplementedError
 * \extends RuntimeError
 * \brief Raised when function or method isn't implemented.
 */
E4C_DECLARE_EXCEPTION (NotImplementedError);

/**
 * \class AbstractError
 * \extends RuntimeError
 * \brief Raised when an abstract class is instanciated.
 */
E4C_DECLARE_EXCEPTION (AbstractError);

#endif /* __OODUCK_EXCEPTIONS_H */