#ifndef __OODUCK_ITERABLE_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Iterable_constructor (void *_self, va_list *app);
static void *Iterable_destructor (void *_self);

static void *Iterable_next (void *_self, const void *iterator);

static void *Iterator_constructor (void *_self, va_list *app);
static void *Iterator_destructor (void *_self);

static void *Iterator_next (void *_self);
static void *Iterator_get (const void *_self);
