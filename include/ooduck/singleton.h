/* singleton.h -- This file is part of ooduck
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#ifndef __OODUCK_SINGLETON_H
#define __OODUCK_SINGLETON_H

#include <ooduck/object.h>

/**
 * \addtogroup OODuck
 * @{
 */

/**
 * \class Singleton
 * \extends Class
 * \brief Singleton metaclass.
 *
 * This is used to build classes with one instance only.
 *
 * First call to ``new()`` with a Singleton class will create the instance and call
 * the constructor. Then, ``new()`` will return the allocated object, ignoring arguments.
 */
OODUCK_DECLARE_CLASS (Singleton);

/** @} */

#endif /* __OODUCK_SINGLETON_H */