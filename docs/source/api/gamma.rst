.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Gamma Distribution
==================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Gamma distribution:

.. math::

   f(x; k, \theta) = \dfrac{x^{k-1}\exp(-x/\theta)}{\theta^k \Gamma(k)} \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` denotes the Gamma function, :math:`k` is the shape parameter, and :math:`\theta` is the scale parameter.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dgamma-func-ref1:
.. doxygenfunction:: dgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dgamma-func-ref2:
.. doxygenfunction:: dgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dgamma-func-ref3:
.. doxygenfunction:: dgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dgamma-func-ref4:
.. doxygenfunction:: dgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dgamma-func-ref5:
.. doxygenfunction:: dgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Gamma distribution:

.. math::

   F(x; k, \theta) = \int_0^x f(z; k, \theta) dz = \frac{\gamma(k,x\theta)}{\Gamma (k)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pgamma-func-ref1:
.. doxygenfunction:: pgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pgamma-func-ref2:
.. doxygenfunction:: pgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pgamma-func-ref3:
.. doxygenfunction:: pgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pgamma-func-ref4:
.. doxygenfunction:: pgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pgamma-func-ref5:
.. doxygenfunction:: pgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Gamma distribution:

.. math::

   q(p; k, \theta) = \inf \left\{ x : p \leq \frac{\gamma(k,x\theta)}{\Gamma (k)} \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qgamma-func-ref1:
.. doxygenfunction:: qgamma(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qgamma-func-ref2:
.. doxygenfunction:: qgamma(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qgamma-func-ref3:
.. doxygenfunction:: qgamma(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qgamma-func-ref4:
.. doxygenfunction:: qgamma(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qgamma-func-ref5:
.. doxygenfunction:: qgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Gamma distribution is achieved via the Ziggurat method of Marsaglia and Tsang (2000).

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rgamma-func-ref1:
.. doxygenfunction:: rgamma(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rgamma-func-ref2:
.. doxygenfunction:: rgamma(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rgamma-func-ref3:
.. doxygenfunction:: rgamma(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
