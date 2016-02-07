/* main.c -- This file is an example of ooduck usage
 *
 * Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <ooduck/string.h>
#include <ooduck/collection.h>
#include <ooduck/singleton.h>
#include <ooduck/value.h>

struct
{
    Collection_add_m add;
    Collection_del_m del;
    Collection_contains_m contains;
    Iterator_next_m next;

    void *col;
    void *str;
    void *it;
} global;

void setup (void)
{
    global.col = new (Collection ());
    global.str = new (String (), "Hello world!");
    global.it = new (Iterator (), global.col);

    global.contains = method (classOf (global.col), "contains");
    global.add = method (classOf (global.col), "add");
    global.del = method (classOf (global.col), "del");
    global.next = method (classOf (global.it), "next");
}

void teardown (void)
{
    delete (global.it);
    delete (global.str);
    delete (global.col);

    memset (&global, 0, sizeof (global));
}

static void test_class_hierarchy (void)
{
    assert (isA (global.str, String ()));
    assert (isOf (global.col, Iterable ()));
}

static void test_collection (void)
{
    global.add (global.col, global.str);
    assert (global.contains (global.col, global.str));

    global.del (global.col, global.str);
    assert (!global.contains (global.col, global.str));
}

static void test_iterable (void)
{
    String_cstr_m cstr;
    Item_deref_m deref;

    void *item = NULL;

    item = new (String (), "Hello");
    global.add (global.col, item);
    unref (item);

    item = new (String (), "world!");
    global.add (global.col, item);
    unref (item);

    while ((item = global.next (global.it)) != NULL)
    {
        void *itemstr = NULL;

        deref = method (classOf (item), "deref");
        itemstr = deref (item);

        cstr = method (classOf (itemstr), "cstr");
        printf ("%s ", cstr (itemstr));
    }

    printf ("\n");
}

static void test_singleton (void)
{
    void *singletoncls = new (
        Singleton (), "TestSingleton",
        String (), sizeOf (global.str),
        NULL
    );

    void *a = new (singletoncls, "test");
    void *b = new (singletoncls, "test");

    assert (a == b);
}

static void test_value (void)
{
    int i = 42, test = -1;
    void *a = new (Value (), &i, sizeof (int));
    void *b = new (Value (), &i, sizeof (int));

    Value_get_m get = method (classOf (a), "get");
    Object_equal_m equal = method (classOf (a), "equal");

    get (a, &test, sizeof (int));

    assert (i == test);
    assert (equal (a, b));

    delete (a);
    delete (b);
}

typedef void (*testcase) (void);

static struct
{
    char *name;
    testcase test;
} unittests[] = {
    { "class-hierarchy", test_class_hierarchy },
    { "collection", test_collection },
    { "iterable", test_iterable },
    { "singleton", test_singleton },
    { "value", test_value },
    { NULL, NULL }
};

int main (int argc, char *argv[])
{
    int i;

    ooduck_init ();

    try
    {
        for (i = 0; unittests[i].name != NULL; ++i)
        {
            printf ("-- Test: %s\n", unittests[i].name);

            setup ();
            unittests[i].test ();
            teardown ();
        }
    }
    catch (RuntimeException)
    {
        e4c_print_exception (e4c_get_exception ());
    }

    return 0;
}
