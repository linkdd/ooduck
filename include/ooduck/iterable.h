#ifndef __OODUCK_ITERABLE_H
#define __OODUCK_ITERABLE_H

#include <ooduck/object.h>

const void *Iterable (void);

typedef void *(*Iterable_next_m) (void *, const void *);

const void *Iterator (void);

typedef void *(*Iterator_next_m) (void *);
typedef void *(*Iterator_get_m) (const void *);

#endif /* __OODUCK_ITERABLE_H */