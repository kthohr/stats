.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Weibull Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Weibull distribution:

.. math::

   f(x; k, \theta) = \frac{k}{\theta} \left( \frac{x}{\theta} \right)^{k-1} \exp \left( - \left( \frac{x}{\theta} \right)^k \right) \times \mathbf{1}[ x \geq 0 ]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dweibull-func-ref1:
.. doxygenfunction:: dweibull(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dweibull-func-ref2:
.. doxygenfunction:: dweibull(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dweibull-func-ref3:
.. doxygenfunction:: dweibull(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dweibull-func-ref4:
.. doxygenfunction:: dweibull(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dweibull-func-ref5:
.. doxygenfunction:: dweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Weibull distribution:

.. math::

   F(x; k, \theta) = \int_0^x f(z; k, \theta) dz = 1 - \exp \left( - \left( \frac{x}{\theta} \right)^k \times \mathbf{1}[x \geq 0] \right)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pweibull-func-ref1:
.. doxygenfunction:: pweibull(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pweibull-func-ref2:
.. doxygenfunction:: pweibull(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pweibull-func-ref3:
.. doxygenfunction:: pweibull(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pweibull-func-ref4:
.. doxygenfunction:: pweibull(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pweibull-func-ref5:
.. doxygenfunction:: pweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Weibull distribution:

.. math::

   q(p; k, \theta) = \lambda \times (- \ln(1 - p))^{1/k}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qweibull-func-ref1:
.. doxygenfunction:: qweibull(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qweibull-func-ref2:
.. doxygenfunction:: qweibull(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qweibull-func-ref3:
.. doxygenfunction:: qweibull(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qweibull-func-ref4:
.. doxygenfunction:: qweibull(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qweibull-func-ref5:
.. doxygenfunction:: qweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Weibull distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rweibull-func-ref1:
.. doxygenfunction:: rweibull(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rweibull-func-ref2:
.. doxygenfunction:: rweibull(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rweibull-func-ref3:
.. doxygenfunction:: rweibull(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
