/* main.c -- This file is an example of ooduck usage
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <ooduck/string.h>
#include <ooduck/collection.h>

int main (int argc, char *argv[])
{
    String_cstr_m cstr;
    Collection_add_m add;
    Collection_del_m del;
    Collection_contains_m contains;
    Iterator_next_m next;
    Item_deref_m deref;

    void *col = NULL;
    void *str = NULL;
    void *it = NULL;
    void *item = NULL;

    ooduck_init ();

    col = new (Collection ());
    str = new (String (), "Hello world!");

    /* test class hierarchy */
    assert (isA (str, String ()));
    assert (isOf (col, Iterable ()));

    /* test collection */
    contains = method (classOf (col), "contains");

    add = method (classOf (col), "add");
    add (col, str);
    assert (contains (col, str));

    del = method (classOf (col), "del");
    del (col, str);
    assert (!contains (col, str));

    item = new (String (), "Hello");
    add (col, item);
    unref (item);

    item = new (String (), "world!");
    add (col, item);
    unref (item);

    /* test iterable */
    it = new (Iterator (), col);
    next = method (classOf (it), "next");

    while ((item = next (it)) != NULL)
    {
        void *itemstr = NULL;

        deref = method (classOf (item), "deref");
        itemstr = deref (item);

        cstr = method (classOf (itemstr), "cstr");
        printf ("%s ", cstr (itemstr));
    }

    printf ("\n");

    delete (it);
    delete (str);
    delete (col);

    return 0;
}
