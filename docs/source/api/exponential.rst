.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Exponential Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Exponential distribution:

.. math::

   f(x; \lambda) = \lambda \exp(-\lambda x) \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dexp-func-ref1:
.. doxygenfunction:: dexp(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dexp-func-ref2:
.. doxygenfunction:: dexp(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _dexp-func-ref3:
.. doxygenfunction:: dexp(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _dexp-func-ref4:
.. doxygenfunction:: dexp(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _dexp-func-ref5:
.. doxygenfunction:: dexp(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Exponential distribution:

.. math::

   \int_0^x f(z; \lambda) dz = 1 - \exp(-\lambda x \times \mathbf{1}[ x \geq 0])

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pexp-func-ref1:
.. doxygenfunction:: pexp(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pexp-func-ref2:
.. doxygenfunction:: pexp(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _pexp-func-ref3:
.. doxygenfunction:: pexp(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _pexp-func-ref4:
.. doxygenfunction:: pexp(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _pexp-func-ref5:
.. doxygenfunction:: pexp(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Exponential distribution:

.. math::

   q(p; \lambda) = - \ln (1 - p) / \lambda

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qexp-func-ref1:
.. doxygenfunction:: qexp(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qexp-func-ref2:
.. doxygenfunction:: qexp(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qexp-func-ref3:
.. doxygenfunction:: qexp(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qexp-func-ref4:
.. doxygenfunction:: qexp(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qexp-func-ref5:
.. doxygenfunction:: qexp(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Cauchy distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rexp-func-ref1:
.. doxygenfunction:: rexp(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rexp-func-ref2:
.. doxygenfunction:: rexp(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rexp-func-ref3:
.. doxygenfunction:: rexp(const ullint_t, const ullint_t, const T1)
   :project: statslib
