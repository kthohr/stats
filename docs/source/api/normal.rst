.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Normal Distribution
===================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Normal (Gaussian) distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(x-\mu)^2}{2 \sigma^2} \right)

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dnorm-func-ref1:
.. doxygenfunction:: dnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dnorm-func-ref2:
.. doxygenfunction:: dnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dnorm-func-ref3:
.. doxygenfunction:: dnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dnorm-func-ref4:
.. doxygenfunction:: dnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dnorm-func-ref5:
.. doxygenfunction:: dnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Normal (Gaussian) distribution:

.. math::

   F(x; \mu, \sigma) = \int_{-\infty}^x f(z; \mu, \sigma) dz = \frac{1}{2} \times \left( 1 +  \text{erf} \left( \frac{x - \mu}{\sqrt{2} \sigma} \right) \right)

where :math:`\text{erf}(\cdot)` denotes the Gaussian error function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pnorm-func-ref1:
.. doxygenfunction:: pnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pnorm-func-ref2:
.. doxygenfunction:: pnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pnorm-func-ref3:
.. doxygenfunction:: pnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pnorm-func-ref4:
.. doxygenfunction:: pnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pnorm-func-ref5:
.. doxygenfunction:: pnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the log-Normal distribution:

.. math::

   q(p; \mu, \sigma) = \mu + \sqrt{2} \sigma \times \text{erf}^{-1} \left( 2 p - 1 \right)

where :math:`\text{erf}^{-1}(\cdot)` denotes the inverse Gaussian error function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qnorm-func-ref1:
.. doxygenfunction:: qnorm(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qnorm-func-ref2:
.. doxygenfunction:: qnorm(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qnorm-func-ref3:
.. doxygenfunction:: qnorm(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qnorm-func-ref4:
.. doxygenfunction:: qnorm(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qnorm-func-ref5:
.. doxygenfunction:: qnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Normal distribution is achieved via the ``normal_distribution`` class from the C++ standard library, imported from ``<random>``.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rnorm-func-ref1:
.. doxygenfunction:: rnorm(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rnorm-func-ref2:
.. doxygenfunction:: rnorm(const T1, const T2, const ullint_t)
   :project: statslib

3. Convenience

.. _rnorm-func-ref3:
.. doxygenfunction:: rnorm()
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rnorm-func-ref4:
.. doxygenfunction:: rnorm(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
