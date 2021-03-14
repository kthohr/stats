.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Compiler Options
================

The following options should be declared **before** including the StatsLib header files. 

- For inline-only functionality (i.e., no ``constexpr`` specifiers):

.. code:: cpp

    #define STATS_GO_INLINE


- OpenMP functionality is enabled by default if the ``_OPENMP`` macro is detected (e.g., by invoking ``-fopenmp`` with GCC or Clang). To explicitly enable OpenMP features use:

.. code:: cpp

    #define STATS_USE_OPENMP


- To disable OpenMP functionality:

.. code:: cpp

    #define STATS_DONT_USE_OPENMP

- To use StatsLib with Armadillo, Blaze or Eigen:

.. code:: cpp

    #define STATS_ENABLE_ARMA_WRAPPERS
    #define STATS_ENABLE_BLAZE_WRAPPERS
    #define STATS_ENABLE_EIGEN_WRAPPERS


- To enable wrappers for ``std::vector``:

.. code:: cpp

    #define STATS_ENABLE_STDVEC_WRAPPERS

