.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Exponential Distribution
========================

The density function of the Exponential distribution:

.. math::

   f(x; \lambda) = \lambda \exp(-\lambda x) \times \mathbf{1}[ x \geq 0]

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dexp-func-ref1:
.. doxygenfunction:: dexp(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dexp-func-ref2:
.. doxygenfunction:: dexp(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _dexp-func-ref3:
.. doxygenfunction:: dexp(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _dexp-func-ref4:
.. doxygenfunction:: dexp(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _dexp-func-ref5:
.. doxygenfunction:: dexp(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pexp-func-ref1:
.. doxygenfunction:: pexp(const T1, const T2, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pexp-func-ref2:
.. doxygenfunction:: pexp(const std::vector<eT>&, const T1, const bool)
   :project: statslib

2. Armadillo

.. _pexp-func-ref3:
.. doxygenfunction:: pexp(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

3. Blaze

.. _pexp-func-ref4:
.. doxygenfunction:: pexp(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

4. Eigen

.. _pexp-func-ref5:
.. doxygenfunction:: pexp(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qexp-func-ref1:
.. doxygenfunction:: qexp(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qexp-func-ref2:
.. doxygenfunction:: qexp(const std::vector<eT>&, const T1)
   :project: statslib

2. Armadillo

.. _qexp-func-ref3:
.. doxygenfunction:: qexp(const ArmaMat<eT>&, const T1)
   :project: statslib

3. Blaze

.. _qexp-func-ref4:
.. doxygenfunction:: qexp(const BlazeMat<eT, To>&, const T1)
   :project: statslib

4. Eigen

.. _qexp-func-ref5:
.. doxygenfunction:: qexp(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rexp-func-ref1:
.. doxygenfunction:: rexp(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rexp-func-ref2:
.. doxygenfunction:: rexp(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rexp-func-ref3:
.. doxygenfunction:: rexp(const ullint_t, const ullint_t, const T1)
   :project: statslib
