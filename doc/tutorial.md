# Tutorial {#page}

This tutorial will teach you how to use OODuck and how to create custom Class.

## Using OODuck

In order to use the OODuck dynamic typing, you need the following skeleton:

~~~~~~~~~~~~~~~{.c}
#include <ooduck/object.h>


int main (void)
{
    /* OODuck not usable yet */

    ooduck_init ();

    /* code using OODuck */
}
~~~~~~~~~~~~~~~

Class are defined in their own header, which must be included to use them:

~~~~~~~~~~~~~~~{.c}
#include <ooduck/string.h>
~~~~~~~~~~~~~~~

All objects and classes are stored in a pointer, hiding implementation:

~~~~~~~~~~~~~~~{.c}
void *str = new (String (), "Hello world");
~~~~~~~~~~~~~~~

Methods are accessed dynamically, and their prototype is defined with the
help of ``typedef``:

~~~~~~~~~~~~~~~{.c}
String_cstr_m cstr = method (classOf (str), "cstr");
printf ("%s\n", cstr (str));
~~~~~~~~~~~~~~~

<b>NB:</b> the methods prototypes are located in the class header (here: ``ooduck/string.h``).

Finally, an object is freed with the ``delete()`` function:

~~~~~~~~~~~~~~~{.c}
delete (str);
~~~~~~~~~~~~~~~

## Reference counting

All objects (Class included) have a reference counter initialized to ``1``.
When this counter equals ``0``, the object is automatically deleted:

~~~~~~~~~~~~~~~{.c}
void *str = new (String (), "Hello world");
void *str2 = ref (str);

unref (str);   /* str2 is still accessible */
unref (str2);  /* the object has been deleted */
~~~~~~~~~~~~~~~

## Creating new classes

The first step is to define our Class structure:

~~~~~~~~~~~~~~~{.c}
#include <ooduck/_defs/object.h>

struct MyClass
{
    /* the parent class is Object, so we define a member to allow the pointer
     * to be casted to the parent class.
     */
    struct Object _;

    int mydata;
};
~~~~~~~~~~~~~~~

A Class is an Object, like everything else, then we can create it with ``new()``:

~~~~~~~~~~~~~~~{.c}
static const void *_MyClass = NULL;

const void *MyClass (void)
{
    if (_MyClass == NULL)
    {
        _MyClass = new (
            Class (),               /* we are creating a new Class */
            "MyClass",              /* our class name */
            Object (),              /* parent class */
            sizeof (struct MyClass) /* in-memory size of our class */

            /* VTable */
            "__constructor__", MyClass_constructor,
            "my_method", MyClass_my_method,

            /* End of VTable */
            NULL
        );
    }

    return _MyClass;
}
~~~~~~~~~~~~~~~

Now, we can proceed to implementation:

~~~~~~~~~~~~~~~{.c}
static void *MyClass_constructor (void *_self, va_list *app)
{
    /* get constructor arguments */
    int data = va_arg (*app, int);

    /* call parent constructor */
    Class_constructor_m ctor = method (super (MyClass ()), "__constructor__");
    struct MyClass *self = ctor (_self, app);

    /* do your stuff */
    self->mydata = data;

    return self;
}

static int MyClass_my_method (const void *_self)
{
    /* make sure we have the right object */
    struct MyClass *self = cast (MyClass (), _self);

    return self->mydata;
}
~~~~~~~~~~~~~~~

The last step is to define prototypes for our methods:

~~~~~~~~~~~~~~~{.c}
typedef int (*MyClass_my_method_m) (const void *);
~~~~~~~~~~~~~~~

Finally, we can use our new class:

~~~~~~~~~~~~~~~{.c}
void *obj = new (MyClass (), 42);
MyClass_my_method_m my_method = method (classOf (obj), "my_method");

assert (my_method (obj) == 42);
~~~~~~~~~~~~~~~

## Important notes

As you can see, we define our class in a ``static`` global variable, and make it
accessible with a function.

This is not <b>thread-safe</b> at all. You will need to call this function for each
class you use <b>before</b> starting new threads.

In a later release, I would like to implement a <b>lock-free</b> algorithm with
a set of <i>macros</i>, in order to ease the implementation.