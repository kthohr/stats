.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Weibull Distribution
====================

The density function of the Weibull distribution:

.. math::

   f(x; k, \theta) = \frac{k}{\theta} \left( \frac{x}{\theta} \right)^{k-1} \exp \left( - \left( \frac{x}{\theta} \right)^k \right) \times \mathbf{1}[ x \geq 0 ]

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dweibull-func-ref1:
.. doxygenfunction:: dweibull(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dweibull-func-ref2:
.. doxygenfunction:: dweibull(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dweibull-func-ref3:
.. doxygenfunction:: dweibull(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dweibull-func-ref4:
.. doxygenfunction:: dweibull(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dweibull-func-ref5:
.. doxygenfunction:: dweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pweibull-func-ref1:
.. doxygenfunction:: pweibull(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pweibull-func-ref2:
.. doxygenfunction:: pweibull(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _pweibull-func-ref3:
.. doxygenfunction:: pweibull(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _pweibull-func-ref4:
.. doxygenfunction:: pweibull(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _pweibull-func-ref5:
.. doxygenfunction:: pweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qweibull-func-ref1:
.. doxygenfunction:: qweibull(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qweibull-func-ref2:
.. doxygenfunction:: qweibull(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qweibull-func-ref3:
.. doxygenfunction:: qweibull(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qweibull-func-ref4:
.. doxygenfunction:: qweibull(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qweibull-func-ref5:
.. doxygenfunction:: qweibull(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rweibull-func-ref1:
.. doxygenfunction:: rweibull(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rweibull-func-ref2:
.. doxygenfunction:: rweibull(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rweibull-func-ref3:
.. doxygenfunction:: rweibull(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
