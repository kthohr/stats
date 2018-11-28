.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Binomial Distribution
=====================

The density function of the Binomial distribution:

.. math::

   f(x; n, p) = \binom{n}{x} p^x (1-p)^{n-x} \times \mathbf{1}[x \in \{0,\ldots,n\}]

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dbinom-func-ref1:
.. doxygenfunction:: dbinom(const llint_t, const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dbinom-func-ref2:
.. doxygenfunction:: dbinom(const std::vector<eT>&, const llint_t, const T1, const bool)
   :project: statslib

2. Armadillo

.. _dbinom-func-ref3:
.. doxygenfunction:: dbinom(const ArmaMat<eT>&, const llint_t, const T1, const bool)
   :project: statslib

3. Blaze

.. _dbinom-func-ref4:
.. doxygenfunction:: dbinom(const BlazeMat<eT, To>&, const llint_t, const T1, const bool)
   :project: statslib

4. Eigen

.. _dbinom-func-ref5:
.. doxygenfunction:: dbinom(const EigenMat<eT, iTr, iTc>&, const llint_t, const T1, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pbinom-func-ref1:
.. doxygenfunction:: pbinom(const llint_t, const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pbinom-func-ref2:
.. doxygenfunction:: pbinom(const std::vector<eT>&, const llint_t, const T1, const bool)
   :project: statslib

2. Armadillo

.. _pbinom-func-ref3:
.. doxygenfunction:: pbinom(const ArmaMat<eT>&, const llint_t, const T1, const bool)
   :project: statslib

3. Blaze

.. _pbinom-func-ref4:
.. doxygenfunction:: pbinom(const BlazeMat<eT, To>&, const llint_t, const T1, const bool)
   :project: statslib

4. Eigen

.. _pbinom-func-ref5:
.. doxygenfunction:: pbinom(const EigenMat<eT, iTr, iTc>&, const llint_t, const T1, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qbinom-func-ref1:
.. doxygenfunction:: qbinom(const T1, const llint_t, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qbinom-func-ref2:
.. doxygenfunction:: qbinom(const std::vector<eT>&, const llint_t, const T1)
   :project: statslib

2. Armadillo

.. _qbinom-func-ref3:
.. doxygenfunction:: qbinom(const ArmaMat<eT>&, const llint_t, const T1)
   :project: statslib

3. Blaze

.. _qbinom-func-ref4:
.. doxygenfunction:: qbinom(const BlazeMat<eT, To>&, const llint_t, const T1)
   :project: statslib

4. Eigen

.. _qbinom-func-ref5:
.. doxygenfunction:: qbinom(const EigenMat<eT, iTr, iTc>&, const llint_t, const T1)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rbinom-func-ref1:
.. doxygenfunction:: rbinom(const llint_t, const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rbinom-func-ref2:
.. doxygenfunction:: rbinom(const llint_t, const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rbinom-func-ref3:
.. doxygenfunction:: rbinom(const ullint_t, const ullint_t, const llint_t, const T1)
   :project: statslib
