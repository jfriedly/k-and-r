Chapter 1
=========

1-1
---
I experimented with commenting out each line of my program.
It still works if you leave out the return statement (which I only added to silence a compiler warning) or the include statement (because ``printf`` gets implicitly included).

.. code:: bash

    mkdir -p build
    git checkout 1-1; cc -std=c99 -Wall -o build/hello-world src/hello-world.c

1-2
---
I started out by writing a loop that created a string containing ``\\c: \c`` for every lowercase character ``c``, but it turns out that this doesn't work.
Apparently, the ``format`` argument to ``printf`` is evaluated at compile time, not run time.

Instead, I generated the code with a bit of Python and pasted it into the C source file so that it would be there at compile time.
One gets warnings about unknown escape sequences for most of them, errors for ``\u`` and ``\x`` because they're incomplete escape sequences, and some interesting output for the others.

.. code:: bash

    git checkout 1-2; cc -std=c99 -Wall -o build/hello-world src/hello-world.c

1-3
---
.. code:: bash

    git checkout 1-3; cc -std=c99 -Wall -o build/temperature-conversion src/temperature-conversion.c

1-4
---
.. code:: bash

    git checkout 1-4; cc -std=c99 -Wall -o build/temperature-conversion src/temperature-conversion.c

1-5
---
.. code:: bash

    git checkout 1-5; cc -std=c99 -Wall -o build/temperature-conversion src/temperature-conversion.c

1-6
---
``getchar() != EOF`` is a boolean expression, so by definition it must evaluate to either 0 or 1.

1-7
---
.. code:: bash

    git checkout 1-7; cc -std=c99 -Wall -o build/print-eof.c src/print-eof.c

1-8
---
.. code:: bash

    git checkout 1-8; cc -std=c99 -Wall -o build/whitespace-count.c src/whitespace-count.c

1-9
---
.. code:: bash

    git checkout 1-9; cc -std=c99 -Wall -o build/whitespace-normalizer src/whitespace-normalizer.c

1-10
----
.. code:: bash

    git checkout 1-10; cc -std=c99 -Wall -o build/backslasher src/backslasher.c

1-11
----
I'd test it by hitting it with every corner case I could think of:  empty input, input consisting solely of sequences of newlines, spaces, and tab characters, and input containing sequences like that.

1-12
----
.. code:: bash

    git checkout 1-12; cc -std=c99 -Wall -o build/word-per-line src/word-per-line.c

1-13
----
I implemented both the horizontal and vertical versions; swap them out at the bottom of ``main`` to see.

.. code:: bash

    git checkout 1-13; cc -std=c99 -Wall -o build/word-length src/word-length.c src/histogram.c
    git checkout 1-21; cc -std=c99 -Wall -o build/word-length src/word-length.c src/histogram.c src/common.c

1-14
----
I moved the histogram functions into a separate file with a header and included it.

.. code:: bash

    git checkout 1-14; cc -std=c99 -Wall -o build/char-freq src/char-freq.c src/histogram.c
    git checkout 1-21; cc -std=c99 -Wall -o build/char-freq src/char-freq.c src/histogram.c src/common.c 

1-15
----
.. code:: bash

    git checkout 1-15; cc -std=c99 -Wall -o build/temperature-conversion src/temperature-conversion.c

1-16
----
.. code:: bash

    git checkout 1-16; cc -std=c99 -Wall -o build/longest-line src/longest-line.c

1-17
----
.. code:: bash

    git checkout 1-17; cc -std=c99 -Wall -o build/too-long src/too-long.c

1-18
----
.. code:: bash

    git checkout 1-18; cc -std=c99 -Wall -o build/trailing-whitespace src/trailing-whitespace.c
    git checkout 1-21; cc -std=c99 -Wall -o build/trailing-whitespace src/trailing-whitespace.c src/common.c

1-19
----
.. code:: bash

    git checkout 1-19; cc -std=c99 -Wall -o build/reverse src/reverse.c

1-20
----
I believe that the number of spaces per tab should be a variable, because it would be nice to make it runtime configurable.
This version doesn't support that though.

.. code:: bash

    git checkout 1-20; cc -std=c99 -Wall -o build/detab src/detab.c
    git checkout 1-21; cc -std=c99 -Wall -o build/detab src/detab.c src/common.c

1-21
----
When either a tab or a space would work, I'd prefer to use a space character, because that removes any ambiguity about what a single-character blank could be.

I refactored the while loop that I'd been using everywhere into the common header and added compilation commands for earlier exercises to use it.

.. code:: bash

    git checkout 1-21; cc -std=c99 -Wall -o build/entab src/entab.c src/common.c

1-22
----
.. code:: bash

    git checkout 1-22; cc -std=c99 -Wall -o build/fold src/fold.c src/common.c

1-23
----
.. code:: bash

    git checkout 1-23; cc -std=c99 -Wall -Wno-unused-variable -o build/comment-stripper src/comment-stripper.c src/common.c

1-24
----
.. code:: bash

    git checkout 1-24; cc -std=c99 -Wall -o build/syntax-checker src/syntax-checker.c src/common.c


Chapter 2
=========

2-1
---
For the floating point values, the headers contained the minimum *normalized* value for each type.
Normalized floating point numbers are ones that can be expressed with a stable, discrete difference between two consecutive values.
When the numbers get too close to zero, however, *denormal* or *subnormal* values are expressed, where the difference between two consecutive expressible values varies and the precision falls off.
I went ahead and attempted to calculate the *normal* minimums.

I was, however, unable to come up with any arithmetic way of calculating these, and had to resort to reading the Wikipedia pages for the floating point specifications.
By reading those pages, I was able to write out the hex values of the smallest normalized and largest floating point numbers, and then print these.

Note, the location of the link argument to ``cc`` matters and the command below works.

.. code:: bash

    git checkout 1-25; cc -std=c99 -Wall -Wno-incompatible-pointer-types -o build/limits src/limits.c -lm

2-2
---
I tested this by replacing the for loop inside ``getline`` in ``longest-line.c`` (exercise 1-16).
The need for ``break`` statements caught me off-guard.

.. code:: c

    #define MAXLINE 1000

    char s[MAXLINE];
    int lim = MAXLINE;
    int c;
    for (i = 0; i < lim - 1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            } else {
                break;
            }
        } else {
            break;
        }
    }

2-3
---
.. code:: bash

    git checkout 2-3; cc -std=c99 -Wall -o build/htoi src/htoi.c src/common.c

2-4
---
I tested this by writing a program for it.
The need to write the new null character to the end of ``s1`` after every iteration of the outer loop caught me off-guard.
Note:  this program acts on its arguments rather than ``stdin``.

.. code:: bash

    git checkout 2-4; cc -std=c99 -Wall -o build/squeeze src/squeeze.c

.. code:: c

    void squeeze(char s1[], char s2[])
    {
        int i, j, k;

        for (i = 0; s2[i] != '\0'; i++) {
            for (j = k = 0; s1[j] != '\0'; j++) {
                if (s1[j] != s2[i])
                    s1[k++] = s1[j];
            }
            s1[k] = '\0';
        }
    }

2-5
---
I tested this by writing a program for it.
Note:  this program acts on its arguments rather than ``stdin``.

.. code:: bash

    git checkout 2-5; cc -std=c99 -Wall -o build/any src/any.c

.. code:: c

    
    int any(char s1[], char s2[])
    {
        for (int i = 0; s1[i] != '\0'; i++) {
            for (int j = 0; s2[j] != '\0'; j++) {
                if (s1[i] == s2[j])
                    return i;
            }
        }
        return -1;
    }

2-6
---
I tested this and the next two programs with a `bitshifting` program.

.. code:: bash

    git checkout 2-6; cc -std=c99 -Wall -o build/bitshifting src/bitshifting.c

.. code:: c

    unsigned long p_to_n_bitmask(short p, short n)
    {
        if (n == 0)
            return 0L;
        unsigned long mask = 0xffffffffffffffff;
        mask <<= (8 * sizeof(long) - p - 1);
        mask >>= (8 * sizeof(long) - p - 1);
        mask >>= (p + 1 - n);
        mask <<= (p + 1 - n);
        return mask;
    }

    unsigned long setbits(unsigned long x, short p, short n, unsigned long y)
    {
        unsigned long mask = p_to_n_bitmask(p, n);
        mask <<= (8 * sizeof(long) - p - 1);
        mask >>= (8 * sizeof(long) - p - 1);
        mask >>= (p + 1 - n);
        mask <<= (p + 1 - n);
        x &= ~mask;
        mask &= y << (p - n);
        return x | mask;
    }

2-7
---
I tested this, the previous program, and the next program with a `bitshifting` program.

.. code:: bash

    git checkout 2-7; cc -std=c99 -Wall -o build/bitshifting src/bitshifting.c

.. code:: c

    unsigned long invert(unsigned long x, short p, short n)
    {
        unsigned long mask = p_to_n_bitmask(p, n);
        mask &= x;
        debug("mask is 0x%.16lx", mask);
        x ^= mask;
        debug("x    is 0x%.16lx", x);
        mask = p_to_n_bitmask(p, n) & ~mask;
        return x | mask;
    }

2-8
---
I tested this and the two previous programs with a `bitshifting` program.

.. code:: bash

    git checkout 2-8; cc -std=c99 -Wall -o build/bitshifting src/bitshifting.c

.. code:: c

    unsigned long rightrot(unsigned long x, short n)
    {
        n %= (8 * sizeof(long));
        unsigned long mask = p_to_n_bitmask(n - 1, n);
        mask &= x;
        x >>= n;
        mask <<= (8 * sizeof(long) - n);
        return x | mask;
    }

2-9
---
The expression `x-1` sets the rightmost one bit in `x` to a zero, and all the zero bits after it to ones.
Computing the AND of `x` and `x-1` will naturally leave all the bits after the rightmost one bit as zeroes, but will also zero out the rightmost one bit.
I didn't test this exercise, I just googled after I wrote it to ensure that I had the answer right.

.. code:: c

    int bitcount(unsigned int x)
    {
        int b;
        for (b = 0; x != 0; b++)
            x &= x - 1;
        return b;
    }

2-10
----

.. code:: bash

    git checkout 2-10; cc -std=c99 -Wall -o build/lower src/lower.c


Chapter 3
=========

3-1
---

.. code:: c

    int fastbinsearch(int x, int v[], int n)
    {
        int low, high, mid;

        low = 0;
        high = n - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (x < v[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (high >= 0 && x == v[high])
            return high;
        else
            return -1;
    }

To measure the difference in runtime, I wrote a program `binsearch` that performs binary search as many times as you ask it to using either the book's `binsearch` implementation, or my (not so) `fastbinsearch` implementation.
The program always searches for a static number *x* in a static array of the *n* integers from zero to *n*.
Each test was performed 100,000,000 times, because that took single-digit seconds to run, which seemed like a good compromise between testing efficiency and eliminating noisy data.

Time testing with x = 11 in a 1024 value array, I found that the original version took a consistent 4.1 seconds to run the test 100,000,000 times, while the `fastbinsearch` version took a consistent 5.2 seconds.

Time testing with x = 21 in a 1048576 value array, I found that the original version took a consistent 10.8 seconds, while the `fastbinsearch` version took a consistent 11.3 seconds.

Time testing each with x = 1013 in a 1024 value array, I found that the original version took a consistent 4.9 seconds, while the `fastbinsearch` version took a consistent 5.2 seconds.

Time testing each with x = 1023 in a 1024 value array, I found that the original version took a consistent 6.3 seconds, while the `fastbinsearch` version took a consistent 5.7 seconds.

.. code:: bash

    git checkout 3-1; cc -std=c99 -Wall -o build/binsearch src/binsearch.c
