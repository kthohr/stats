.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Student's t-Distribution
========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Student's t distribution:

.. math::

   f(x; \nu) = \dfrac{\Gamma \left( \frac{\nu + 1}{2} \right)}{ \sqrt{\nu \pi} \Gamma \left( \frac{\nu}{2} \right)} \left( 1 + \frac{x^2}{\nu} \right)^{- \frac{\nu+1}{2}}

where :math:`\Gamma(\cdot)` denotes the gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dt-func-ref1:
.. doxygenfunction:: dt(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dt-func-ref2:
.. doxygenfunction:: dt(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _dt-func-ref3:
.. doxygenfunction:: dt(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _dt-func-ref4:
.. doxygenfunction:: dt(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _dt-func-ref5:
.. doxygenfunction:: dt(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Student's t distribution:

.. math::

   F(x; \nu) = \int_{-\infty}^x f(z; \nu) dz = \frac{1}{2} + x \Gamma \left( \frac{\nu + 1}{2} \right) + \dfrac{ {}_2 F_1 \left( \frac{1}{2}, \frac{\nu+1}{2}; \frac{3}{\nu}; - \frac{x^2}{\nu} \right) }{ \sqrt{\nu \pi} \Gamma \left( \frac{\nu}{2} \right)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`{}_2 F_1` denotes the hypergeometric function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pt-func-ref1:
.. doxygenfunction:: pt(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pt-func-ref2:
.. doxygenfunction:: pt(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _pt-func-ref3:
.. doxygenfunction:: pt(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _pt-func-ref4:
.. doxygenfunction:: pt(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _pt-func-ref5:
.. doxygenfunction:: pt(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Student's t distribution:

.. math::

   q(p; \nu) = \inf \left\{ x : p \leq F(x; \nu) \right\}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qt-func-ref1:
.. doxygenfunction:: qt(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qt-func-ref2:
.. doxygenfunction:: qt(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qt-func-ref3:
.. doxygenfunction:: qt(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qt-func-ref4:
.. doxygenfunction:: qt(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qt-func-ref5:
.. doxygenfunction:: qt(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rt-func-ref1:
.. doxygenfunction:: rt(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rt-func-ref2:
.. doxygenfunction:: rt(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rt-func-ref3:
.. doxygenfunction:: rt(const ullint_t, const ullint_t, const T1)
   :project: statslib
