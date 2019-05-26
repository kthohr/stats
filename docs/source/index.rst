.. Copyright (c) 2011-2019 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Introduction
============

StatsLib is a templated C++ library of statistical distribution functions, featuring unique compile-time computing capabilities and seamless integration with several popular linear algebra libraries.

**Features**

* A header-only library of probability density functions, cumulative distribution functions, quantile functions, and random sampling methods.
* The core features are written in C++11 `constexpr` format, enabling the library to operate as both a compile-time and run-time computation engine.
* Designed with a simple **R**\ -like syntax.
* Optional vector-matrix functionality with wrappers to support:
    * STL vectors
    * `Armadillo <http://arma.sourceforge.net/>`_
    * `Blaze <https://bitbucket.org/blaze-lib/blaze>`_
    * `Eigen <http://eigen.tuxfamily.org/index.php>`_
* Matrix-based operations are parallelizable with OpenMP.
* Released under a permissive, non-GPL license.

Author: Keith O'Hara

License: Apache Version 2.0

Contents
--------

.. toctree::
   :titlesonly:
   :caption: API
   :maxdepth: 2
   
   api/dist_index
