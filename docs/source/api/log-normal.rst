.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Log-Normal Distribution
=======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the log-Normal distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{x} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(\ln x-\mu)^2}{2 \sigma^2} \right)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dlnorm-func-ref1:
.. doxygenfunction:: dlnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dlnorm-func-ref2:
.. doxygenfunction:: dlnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dlnorm-func-ref3:
.. doxygenfunction:: dlnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dlnorm-func-ref4:
.. doxygenfunction:: dlnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dlnorm-func-ref5:
.. doxygenfunction:: dlnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the log-Normal distribution:

.. math::

   F(x; \mu, \sigma) = \int_0^x f(z; \mu, \sigma) dz = \frac{1}{2} + \frac{1}{2} \times \text{erf} \left( \frac{\ln (x) - \mu}{\sigma} \right)

where :math:`\text{erf}(\cdot)` denotes the Gaussian error function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _plnorm-func-ref1:
.. doxygenfunction:: plnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _plnorm-func-ref2:
.. doxygenfunction:: plnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _plnorm-func-ref3:
.. doxygenfunction:: plnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _plnorm-func-ref4:
.. doxygenfunction:: plnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _plnorm-func-ref5:
.. doxygenfunction:: plnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the log-Normal distribution:

.. math::

   q(p; \mu, \sigma) = \exp \left( \mu + \sqrt{2} \sigma \times \text{erf}^{-1} \left( 2 p - 1 \right) \right)

where :math:`\text{erf}^{-1}(\cdot)` denotes the inverse Gaussian error function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qlnorm-func-ref1:
.. doxygenfunction:: qlnorm(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qlnorm-func-ref2:
.. doxygenfunction:: qlnorm(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qlnorm-func-ref3:
.. doxygenfunction:: qlnorm(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qlnorm-func-ref4:
.. doxygenfunction:: qlnorm(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qlnorm-func-ref5:
.. doxygenfunction:: qlnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the log-Normal distribution is achieved by simulating :math:`X \sim N(\mu, \sigma^2)`, then returning

.. math::

   Z = \exp( X ) \sim \text{Lognormal} (\mu, \sigma^2)

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rlnorm-func-ref1:
.. doxygenfunction:: rlnorm(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rlnorm-func-ref2:
.. doxygenfunction:: rlnorm(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rlnorm-func-ref3:
.. doxygenfunction:: rlnorm(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
