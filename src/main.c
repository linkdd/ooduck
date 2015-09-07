#include <ooduck/string.h>


int main (int argc, char *argv[])
{
    String_cstr_m cstr;
    void *str = NULL;

    ooduck_init ();

    str = new (String (), "Hello world!");
    cstr = method (classOf (str), "cstr");

    printf ("%s\n", cstr (str));

    return 0;
}
