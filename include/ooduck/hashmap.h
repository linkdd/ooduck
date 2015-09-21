#ifndef __OODUCK_HASHMAP_H
#define __OODUCK_HASHMAP_H

#include <ooduck/iterable.h>
#include <ooduck/collection.h>

const void *Hashmap (void);

typedef void *(*Hashmap_next_m) (void *, const void *);
typedef void *(*Hashmap_get_m) (const void *, const void *);
typedef void (*Hashmap_set_m) (void *, const void *, void *);
typedef void (*Hashmap_del_m) (const void *, const void *);
typedef void *(*Hashmap_keys_m) (const void *);
typedef void *(*Hashmap_values_m) (const void *);

#endif /* __OODUCK_HASHMAP_H */