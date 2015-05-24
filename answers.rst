Chapter 1
=========

1-1
---
I experimented with commenting out each line of my program.
It still works if you leave out the return statement (which I only added to silence a compiler warning) or the include statement (because ``printf`` gets implicitly included).

.. code:: bash

    mkdir -p build
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

1-4
---
.. code:: bash

    git checkout 1-4; cc -Wall -std=c99 src/temperature-conversion.c -o build/temperature-conversion

1-5
---
.. code:: bash

    git checkout 1-5; cc -Wall -std=c99 src/temperature-conversion.c -o build/temperature-conversion

1-6
---
``getchar() != EOF`` is a boolean expression, so by definition it must evaluate to either 0 or 1.

1-7
---
.. code:: bash

    git checkout 1-7; cc -Wall -std=c99 src/print-eof.c -o build/print-eof.c

1-8
---
.. code:: bash

    git checkout 1-8; cc -Wall -std=c99 src/whitespace-count.c -o build/whitespace-count.c

1-9
---
.. code:: bash

    git checkout 1-9; cc -Wall -std=c99 src/whitespace-normalizer.c -o build/whitespace-normalizer

1-10
----
.. code:: bash

    git checkout 1-10; cc -Wall -std=c99 src/backslasher.c -o build/backslasher

1-11
----
I'd test it by hitting it with every corner case I could think of:  empty input, input consisting solely of sequences of newlines, spaces, and tab characters, and input containing sequences like that.

1-12
----
.. code:: bash

    git checkout 1-12; cc -Wall -std=c99 src/word-per-line.c -o build/word-per-line

1-13
----
I implemented both the horizontal and vertical versions; swap them out at the bottom of ``main`` to see.

.. code:: bash

    git checkout 1-13; cc -Wall -std=c99 src/word-length.c src/histogram.c -o build/word-length 

1-14
----
I moved the histogram functions into a separate file with a header and included it.

.. code:: bash

    git checkout 1-14; cc -Wall -std=c99 src/char-freq.c src/histogram.c -o build/char-freq 

1-15
----
.. code:: bash

    git checkout 1-15; cc -Wall -std=c99 src/temperature-conversion.c -o build/temperature-conversion

1-16
----
.. code:: bash

    git checkout 1-16; cc -Wall -std=c99 src/longest-line.c -o build/longest-line

1-17
----
.. code:: bash

    git checkout 1-17; cc -Wall -std=c99 src/too-long.c -o build/too-long

1-18
----
.. code:: bash

    git checkout 1-18; cc -Wall -std=c99 src/trailing-whitespace.c -o build/trailing-whitespace

1-19
----
.. code:: bash

    git checkout 1-19; cc -Wall -std=c99 src/reverse.c -o build/reverse
