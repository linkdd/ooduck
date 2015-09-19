#ifndef __OODUCK_COLLECTION_PRIV_H
#   error "Can't include private section"
#endif

/* declarations */
static void *Collection_constructor (void *_self, va_list *app);
static void *Collection_destructor (void *_self);

static void Collection_clear (void *_self);
static void Collection_add (void *_self, const void *item);
static void Collection_del (void *_self, const void *item);
static bool Collection_contains (void *_self, const void *item);

static struct Item *_Collection_getitem (void *_self, const void *item);

static void *Item_constructor (void *_self, va_list *app);
static void *Item_destructor (void *_self);

static void *Item_deref (void *_self);
