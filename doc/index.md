# Main Page {#mainpage}

![ ](https://raw.githubusercontent.com/linkdd/ooduck/master/doc/static/logo-48x48.png)
![Travis-CI build](https://travis-ci.org/linkdd/ooduck.svg)

OODuck is an <b>O</b>bject <b>O</b>riented framework in C with <b>D</b>uck typing support.

It is inspired of the famous [ooc.pdf](http://www.cs.rit.edu/~ats/books/ooc.pdf)
and is using [exceptions4c](https://github.com/guillermocalvo/exceptions4c)

**TODO:** [Github Issues Tracker](https://github.com/linkdd/ooduck/issues)

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

To build documentation, you will need ``doxygen`` installed:

    $ cd doc
    $ make

Then, open the file ``doc/html/index.html`` in your browser.

## License

OODuck is released under the terms of the MIT license:

    Copyright (C) 2015 David Delassus <david.jose.delassus@gmail.com>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
