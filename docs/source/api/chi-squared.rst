.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Chi-squared Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Chi-squared distribution:

.. math::

   f(x; k) = \dfrac{x^{k/2 - 1} \exp(-x/2)}{ 2^{k/2} \Gamma(k/2)} \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dchisq-func-ref1:
.. doxygenfunction:: dchisq(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dchisq-func-ref2:
.. doxygenfunction:: dchisq(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _dchisq-func-ref3:
.. doxygenfunction:: dchisq(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _dchisq-func-ref4:
.. doxygenfunction:: dchisq(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _dchisq-func-ref5:
.. doxygenfunction:: dchisq(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Chi-squared distribution:

.. math::

   F(x; k) = \int_0^x f(z; k) dz = \frac{\gamma(k/2,x/2)}{\Gamma (k/2)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pchisq-func-ref1:
.. doxygenfunction:: pchisq(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pchisq-func-ref2:
.. doxygenfunction:: pchisq(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _pchisq-func-ref3:
.. doxygenfunction:: pchisq(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _pchisq-func-ref4:
.. doxygenfunction:: pchisq(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _pchisq-func-ref5:
.. doxygenfunction:: pchisq(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Chi-squared distribution:

.. math::

   q(p; k) = \inf \left\{ x : p \leq \gamma(k/2,x/2) / \Gamma (k/2) \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qchisq-func-ref1:
.. doxygenfunction:: qchisq(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qchisq-func-ref2:
.. doxygenfunction:: qchisq(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qchisq-func-ref3:
.. doxygenfunction:: qchisq(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qchisq-func-ref4:
.. doxygenfunction:: qchisq(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qchisq-func-ref5:
.. doxygenfunction:: qchisq(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rchisq-func-ref1:
.. doxygenfunction:: rchisq(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rchisq-func-ref2:
.. doxygenfunction:: rchisq(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rchisq-func-ref3:
.. doxygenfunction:: rchisq(const ullint_t, const ullint_t, const T1)
   :project: statslib
