.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Chi-squared Distribution
========================

The density function of the Chi-squared distribution:

.. math::

   f(x; k) = \dfrac{x^{k/2 - 1} \exp(-x/2)}{ 2^{k/2} \Gamma(k/2)} \times \mathbf{1}[ x \geq 0]

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dchisq-func-ref1:
.. doxygenfunction:: dchisq(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dchisq-func-ref2:
.. doxygenfunction:: dchisq(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _dchisq-func-ref3:
.. doxygenfunction:: dchisq(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _dchisq-func-ref4:
.. doxygenfunction:: dchisq(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _dchisq-func-ref5:
.. doxygenfunction:: dchisq(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pchisq-func-ref1:
.. doxygenfunction:: pchisq(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pchisq-func-ref2:
.. doxygenfunction:: pchisq(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _pchisq-func-ref3:
.. doxygenfunction:: pchisq(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _pchisq-func-ref4:
.. doxygenfunction:: pchisq(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _pchisq-func-ref5:
.. doxygenfunction:: pchisq(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qchisq-func-ref1:
.. doxygenfunction:: qchisq(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qchisq-func-ref2:
.. doxygenfunction:: qchisq(const std::vector<eT>&, const T1)
   :project: statslib

2. Armadillo

.. _qchisq-func-ref3:
.. doxygenfunction:: qchisq(const ArmaMat<eT>&, const T1)
   :project: statslib

3. Blaze

.. _qchisq-func-ref4:
.. doxygenfunction:: qchisq(const BlazeMat<eT, To>&, const T1)
   :project: statslib

4. Eigen

.. _qchisq-func-ref5:
.. doxygenfunction:: qchisq(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

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
