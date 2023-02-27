.. Copyright (c) 2011-2023 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Gaussian Distribution
=============================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the inverse Gaussian distribution:

.. math::

   f(x; \mu, \lambda) = \sqrt{ \dfrac{\lambda}{2 \pi x^3} } \exp \left[ - \dfrac{\lambda(x - \mu)^2}{2 \mu^2 x} \right] \times \mathbf{1}[ x \geq 0 ]

where :math:`\mu` is the mean parameter and :math:`\lambda` is the shape parameter.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dinvgauss-func-ref1:
.. doxygenfunction:: dinvgauss(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dinvgauss-func-ref2:
.. doxygenfunction:: dinvgauss(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dinvgauss-func-ref3:
.. doxygenfunction:: dinvgauss(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dinvgauss-func-ref4:
.. doxygenfunction:: dinvgauss(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dinvgauss-func-ref5:
.. doxygenfunction:: dinvgauss(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the inverse Gaussian distribution:

.. math::

   F(x; \mu, \lambda) = \Phi \left( \sqrt{\dfrac{\lambda}{x}} \left( \frac{x}{\mu} - 1 \right) \right) + \exp \left( \dfrac{2 \lambda}{\mu} \right) \Phi \left( - \sqrt{\dfrac{\lambda}{x}} \left( \frac{x}{\mu} + 1 \right) \right)

where :math:`\Phi(\cdot)` denotes the standard Normal CDF.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pinvgauss-func-ref1:
.. doxygenfunction:: pinvgauss(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pinvgauss-func-ref2:
.. doxygenfunction:: pinvgauss(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pinvgauss-func-ref3:
.. doxygenfunction:: pinvgauss(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pinvgauss-func-ref4:
.. doxygenfunction:: pinvgauss(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pinvgauss-func-ref5:
.. doxygenfunction:: pinvgauss(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the inverse Gaussian distribution:

.. math::

   q(p; \mu, \lambda) = \inf \left\{ x : p \leq F(x; \mu, \lambda) \right\}

where :math:`F(\cdot)` denotes the CDF of the inverse Gaussian distribution.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qinvgauss-func-ref1:
.. doxygenfunction:: qinvgauss(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qinvgauss-func-ref2:
.. doxygenfunction:: qinvgauss(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qinvgauss-func-ref3:
.. doxygenfunction:: qinvgauss(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qinvgauss-func-ref4:
.. doxygenfunction:: qinvgauss(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qinvgauss-func-ref5:
.. doxygenfunction:: qinvgauss(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rinvgauss-func-ref1:
.. doxygenfunction:: rinvgauss(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rinvgauss-func-ref2:
.. doxygenfunction:: rinvgauss(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

1. Random number engines

.. _rinvgauss-func-ref3:
.. doxygenfunction:: rinvgauss(const ullint_t, const ullint_t, const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rinvgauss-func-ref4:
.. doxygenfunction:: rinvgauss(const ullint_t, const ullint_t, const T1, const T2, const ullint_t)
   :project: statslib
