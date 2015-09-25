# OODuck

![ ](doc/static/logo.png)

[![Travis-CI build](https://travis-ci.org/linkdd/ooduck.svg)](https://travis-ci.org/linkdd/ooduck)

OODuck is an **O**bject **O**riented framework in C with **D**uck typing support.

It is inspired of the famous [ooc.pdf](http://www.cs.rit.edu/~ats/books/ooc.pdf)
and is using [exceptions4c](https://github.com/guillermocalvo/exceptions4c)

## Build library

Build system is based on CMake:

    $ mkdir __build__ && cd __build__
    $ cmake ..
    $ make

Or in debug mode:

    $ mkdir __build__ && cd __build__
    $ cmake .. -DWITH_DEBUG=1
    $ make

## Installation

Once the project is built, you can install it:

    $ make install

To change default installation location, run ``cmake`` with the following option:

    $ cmake .. -DCMAKE_INSTALL_PREFIX:PATH=/usr

To install in another directory:

    $ make install DESTDIR=/opt/fakeroot

## Documentation

Documentation isn't available yet.

## License

OODuck is released under the terms of the MIT license. See the LICENSE file for details.