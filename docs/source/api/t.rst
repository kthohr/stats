.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Student's t-Distribution
========================

The density function of the t-distribution:

.. math::

   f(x; \nu) = \dfrac{\Gamma \left( \frac{\nu + 1}{2} \right)}{ \sqrt{\nu \pi} \Gamma \left( \frac{\nu}{2} \right)} \left( 1 + \frac{x^2}{\nu} \right)^{- \frac{\nu+1}{2}}

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dt-func-ref1:
.. doxygenfunction:: dt(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dt-func-ref2:
.. doxygenfunction:: dt(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _dt-func-ref3:
.. doxygenfunction:: dt(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _dt-func-ref4:
.. doxygenfunction:: dt(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _dt-func-ref5:
.. doxygenfunction:: dt(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pt-func-ref1:
.. doxygenfunction:: pt(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pt-func-ref2:
.. doxygenfunction:: pt(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _pt-func-ref3:
.. doxygenfunction:: pt(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _pt-func-ref4:
.. doxygenfunction:: pt(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _pt-func-ref5:
.. doxygenfunction:: pt(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qt-func-ref1:
.. doxygenfunction:: qt(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qt-func-ref2:
.. doxygenfunction:: qt(const std::vector<eT>&, const T1)
   :project: statslib

2. Armadillo

.. _qt-func-ref3:
.. doxygenfunction:: qt(const ArmaMat<eT>&, const T1)
   :project: statslib

3. Blaze

.. _qt-func-ref4:
.. doxygenfunction:: qt(const BlazeMat<eT, To>&, const T1)
   :project: statslib

4. Eigen

.. _qt-func-ref5:
.. doxygenfunction:: qt(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

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
