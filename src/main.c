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

    cstr = method (String (), "cstr");
    add = method (Collection (), "add");
    del = method (Collection (), "del");
    contains = method (Collection (), "contains");
    next = method (Iterator (), "next");
    deref = method (Item (), "deref");

    col = new (Collection ());
    str = new (String (), "Hello world!");

    assert (isA (str, String ()));
    assert (isOf (col, Iterable ()));

    add (col, str);
    assert (contains (col, str));
    del (col, str);
    assert (!contains (col, str));

    item = new (String (), "Hello");
    add (col, item);
    unref (item);

    item = new (String (), "world!");
    add (col, item);
    unref (item);

    it = new (Iterator (), col);

    while ((item = next (it)) != NULL)
    {
        printf ("%s ", cstr (deref (item)));
    }

    printf ("\n");

    delete (it);
    delete (str);
    delete (col);

    return 0;
}
