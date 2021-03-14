.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Uniform Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Uniform distribution:

.. math::

   f(x; a, b) = \frac{1}{b-a} \times \mathbf{1}[ a \leq x \leq b]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dunif-func-ref1:
.. doxygenfunction:: dunif(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dunif-func-ref2:
.. doxygenfunction:: dunif(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dunif-func-ref3:
.. doxygenfunction:: dunif(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dunif-func-ref4:
.. doxygenfunction:: dunif(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dunif-func-ref5:
.. doxygenfunction:: dunif(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Uniform distribution:

.. math::

   F(x; a, b) = \int_{a}^x f(z; a, b) dz = \frac{x - a}{b-a} \times \mathbf{1}[ a \leq x \leq b] + \times \mathbf{1}[x > b]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _punif-func-ref1:
.. doxygenfunction:: punif(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _punif-func-ref2:
.. doxygenfunction:: punif(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _punif-func-ref3:
.. doxygenfunction:: punif(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _punif-func-ref4:
.. doxygenfunction:: punif(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _punif-func-ref5:
.. doxygenfunction:: punif(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Uniform distribution:

.. math::

   q(p; a, b) = a + p(b-a)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qunif-func-ref1:
.. doxygenfunction:: qunif(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qunif-func-ref2:
.. doxygenfunction:: qunif(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qunif-func-ref3:
.. doxygenfunction:: qunif(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qunif-func-ref4:
.. doxygenfunction:: qunif(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qunif-func-ref5:
.. doxygenfunction:: qunif(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Uniform distribution is achieved via the ``uniform_real_distribution`` class from the C++ standard library, imported from ``<random>``.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _runif-func-ref1:
.. doxygenfunction:: runif(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _runif-func-ref2:
.. doxygenfunction:: runif(const T1, const T2, const ullint_t)
   :project: statslib

.. _runif-func-ref3:
.. doxygenfunction:: runif()
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _runif-func-ref4:
.. doxygenfunction:: runif(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
