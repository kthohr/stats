.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Laplace Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Laplace distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{2 \sigma} \exp \left( - \frac{|x-\mu|}{\sigma} \right)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dlaplace-func-ref1:
.. doxygenfunction:: dlaplace(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dlaplace-func-ref2:
.. doxygenfunction:: dlaplace(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dlaplace-func-ref3:
.. doxygenfunction:: dlaplace(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dlaplace-func-ref4:
.. doxygenfunction:: dlaplace(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dlaplace-func-ref5:
.. doxygenfunction:: dlaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Laplace distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz = \frac{1}{2} + \frac{1}{2} \times \text{sign} ( x - \mu ) \times \left( 1 - \exp \left( - \frac{|x - \mu|}{\sigma} \right) \right)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _plaplace-func-ref1:
.. doxygenfunction:: plaplace(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _plaplace-func-ref2:
.. doxygenfunction:: plaplace(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _plaplace-func-ref3:
.. doxygenfunction:: plaplace(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _plaplace-func-ref4:
.. doxygenfunction:: plaplace(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _plaplace-func-ref5:
.. doxygenfunction:: plaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Laplace distribution:

.. math::

   q(p; \mu, \sigma) = \mu - \sigma \times \text{sign}(p - 0.5) \times \ln(1 - 2 | p - 0.5 |)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qlaplace-func-ref1:
.. doxygenfunction:: qlaplace(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qlaplace-func-ref2:
.. doxygenfunction:: qlaplace(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qlaplace-func-ref3:
.. doxygenfunction:: qlaplace(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qlaplace-func-ref4:
.. doxygenfunction:: qlaplace(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qlaplace-func-ref5:
.. doxygenfunction:: qlaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Laplace distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rlaplace-func-ref1:
.. doxygenfunction:: rlaplace(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rlaplace-func-ref2:
.. doxygenfunction:: rlaplace(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rlaplace-func-ref3:
.. doxygenfunction:: rlaplace(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
