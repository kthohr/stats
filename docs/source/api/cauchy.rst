.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Cauchy Distribution
===================

The density function of the Cauchy distribution:

.. math::

   f(x; \mu, \sigma) = \dfrac{1}{\pi \sigma \left[ 1 + \left( \frac{x - \mu}{\sigma} \right)^2 \right]}

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dcauchy-func-ref1:
.. doxygenfunction:: dcauchy(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dcauchy-func-ref2:
.. doxygenfunction:: dcauchy(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dcauchy-func-ref3:
.. doxygenfunction:: dcauchy(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dcauchy-func-ref4:
.. doxygenfunction:: dcauchy(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dcauchy-func-ref5:
.. doxygenfunction:: dcauchy(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pcauchy-func-ref1:
.. doxygenfunction:: pcauchy(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pcauchy-func-ref2:
.. doxygenfunction:: pcauchy(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _pcauchy-func-ref3:
.. doxygenfunction:: pcauchy(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _pcauchy-func-ref4:
.. doxygenfunction:: pcauchy(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _pcauchy-func-ref5:
.. doxygenfunction:: pcauchy(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qcauchy-func-ref1:
.. doxygenfunction:: qcauchy(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qcauchy-func-ref2:
.. doxygenfunction:: qcauchy(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qcauchy-func-ref3:
.. doxygenfunction:: qcauchy(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qcauchy-func-ref4:
.. doxygenfunction:: qcauchy(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qcauchy-func-ref5:
.. doxygenfunction:: qcauchy(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rcauchy-func-ref1:
.. doxygenfunction:: rcauchy(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rcauchy-func-ref2:
.. doxygenfunction:: rcauchy(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rcauchy-func-ref3:
.. doxygenfunction:: rcauchy(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
