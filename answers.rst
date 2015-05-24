Chapter 1
=========

1-1
---
I experimented with commenting out each line of my program.
It still works if you leave out the return statement (which I only added to silence a compiler warning) or the include statement (because ``printf`` gets implicitly included).

.. code:: bash

    git checkout 1-1; cc -Wall src/hello-world.c -o build/hello-world
