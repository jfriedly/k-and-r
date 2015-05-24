Chapter 1
=========

1-1
---
I experimented with commenting out each line of my program.
It still works if you leave out the return statement (which I only added to silence a compiler warning) or the include statement (because ``printf`` gets implicitly included).

.. code:: bash

    git checkout 1-1; cc -Wall -std=c99 src/hello-world.c -o build/hello-world

1-2
---
I started out by writing a loop that created a string containing ``\\c: \c`` for every lowercase character ``c``, but it turns out that this doesn't work.
Apparently, the ``format`` argument to ``printf`` is evaluated at compile time, not run time.

Instead, I generated the code with a bit of Python and pasted it into the C source file so that it would be there at compile time.
One gets warnings about unknown escape sequences for most of them, errors for ``\u`` and ``\x`` because they're incomplete escape sequences, and some interesting output for the others.

.. code:: bash

    git checkout 1-2; cc -Wall -std=c99 src/hello-world.c -o build/hello-world

1-3
---
.. code:: bash

    git checkout 1-3; cc -Wall -std=c99 src/temperature-conversion.c -o build/temperature-conversion
