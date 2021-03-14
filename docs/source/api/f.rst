.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

F-Distribution
==============

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the F distribution:

.. math::

   f(x; d_1, d_2) = \frac{1}{\mathcal{B} \left( \frac{d_1}{2}, \frac{d_2}{2} \right)} \left( \frac{d_1}{d_2} \right)^{\frac{d_1}{2}} x^{d_1/2 - 1} \left(1 + \frac{d_1}{d_2} x \right)^{- \frac{d_1+d_2}{2}} \times \mathbf{1} [x \geq 0]

where :math:`\mathcal{B}(a,b)` denotes the Beta function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _df-func-ref1:
.. doxygenfunction:: df(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _df-func-ref2:
.. doxygenfunction:: df(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _df-func-ref3:
.. doxygenfunction:: df(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _df-func-ref4:
.. doxygenfunction:: df(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _df-func-ref5:
.. doxygenfunction:: df(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the F distribution:

.. math::

   F(x; d_1, d_2) = \int_0^x f(z; d_1, d_2) dz = I_{\frac{d_1 x}{d_2 + d_1 x}} (d_1 / 2, d_2 / 2)

where :math:`I_x (a,b)` denotes the regularized incomplete Beta function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pf-func-ref1:
.. doxygenfunction:: pf(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pf-func-ref2:
.. doxygenfunction:: pf(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pf-func-ref3:
.. doxygenfunction:: pf(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pf-func-ref4:
.. doxygenfunction:: pf(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pf-func-ref5:
.. doxygenfunction:: pf(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the F distribution:

.. math::

   q(p; a,b) = \inf \left\{ x : p \leq I_{\frac{d_1 x}{d_2 + d_1 x}} (d_1 / 2, d_2 / 2) \right\}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qf-func-ref1:
.. doxygenfunction:: qf(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qf-func-ref2:
.. doxygenfunction:: qf(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qf-func-ref3:
.. doxygenfunction:: qf(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qf-func-ref4:
.. doxygenfunction:: qf(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qf-func-ref5:
.. doxygenfunction:: qf(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Beta distribution is achieved by simulating two independent :math:`\chi^2`-distributed random variables, :math:`X \sim \chi^2(d_1), Y \sim \chi^2(d_2)`, then returning:

.. math::

   Z = \frac{d_1}{d_2} \frac{X}{Y}

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rf-func-ref1:
.. doxygenfunction:: rf(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rf-func-ref2:
.. doxygenfunction:: rf(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rf-func-ref3:
.. doxygenfunction:: rf(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
