.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Beta Distribution
=================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Beta distribution:

.. math::

   f(x; a,b) = \frac{1}{\mathcal{B}(a,b)} x^{a-1} (1-x)^{b-1} \times \mathbf{1}[0 \leq x \leq 1]

where :math:`\mathcal{B}(a,b)` denotes the Beta function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbeta-func-ref1:
.. doxygenfunction:: dbeta(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dbeta-func-ref2:
.. doxygenfunction:: dbeta(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dbeta-func-ref3:
.. doxygenfunction:: dbeta(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dbeta-func-ref4:
.. doxygenfunction:: dbeta(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dbeta-func-ref5:
.. doxygenfunction:: dbeta(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Beta distribution:

.. math::

   F(x; a, b) = \int_0^x f(z; a,b) dz = I_x (a,b)

where :math:`I_x (a,b)` denotes the regularized incomplete Beta function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pbeta-func-ref1:
.. doxygenfunction:: pbeta(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pbeta-func-ref2:
.. doxygenfunction:: pbeta(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pbeta-func-ref3:
.. doxygenfunction:: pbeta(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pbeta-func-ref4:
.. doxygenfunction:: pbeta(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pbeta-func-ref5:
.. doxygenfunction:: pbeta(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Beta distribution:

.. math::

   q(p; a,b) = \inf \left\{ x : p \leq I_x (a,b) \right\}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qbeta-func-ref1:
.. doxygenfunction:: qbeta(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qbeta-func-ref2:
.. doxygenfunction:: qbeta(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qbeta-func-ref3:
.. doxygenfunction:: qbeta(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qbeta-func-ref4:
.. doxygenfunction:: qbeta(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qbeta-func-ref5:
.. doxygenfunction:: qbeta(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Beta distribution is achieved by simulating two independent gamma-distributed random variables, :math:`X \sim G(a,1), Y \sim G(a,1)`, then returning:

.. math::

   Z = \frac{X}{X+Y} \sim B(a,b)

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rbeta-func-ref1:
.. doxygenfunction:: rbeta(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rbeta-func-ref2:
.. doxygenfunction:: rbeta(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rbeta-func-ref3:
.. doxygenfunction:: rbeta(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
