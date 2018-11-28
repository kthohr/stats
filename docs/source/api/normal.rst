.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Normal Distribution
===================

The density function of the Normal (Gaussian) distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(x-\mu)^2}{2 \sigma^2} \right)

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dnorm-func-ref1:
.. doxygenfunction:: dnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dnorm-func-ref2:
.. doxygenfunction:: dnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dnorm-func-ref3:
.. doxygenfunction:: dnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dnorm-func-ref4:
.. doxygenfunction:: dnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dnorm-func-ref5:
.. doxygenfunction:: dnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pnorm-func-ref1:
.. doxygenfunction:: pnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pnorm-func-ref2:
.. doxygenfunction:: pnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _pnorm-func-ref3:
.. doxygenfunction:: pnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _pnorm-func-ref4:
.. doxygenfunction:: pnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _pnorm-func-ref5:
.. doxygenfunction:: pnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qnorm-func-ref1:
.. doxygenfunction:: qnorm(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qnorm-func-ref2:
.. doxygenfunction:: qnorm(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qnorm-func-ref3:
.. doxygenfunction:: qnorm(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qnorm-func-ref4:
.. doxygenfunction:: qnorm(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qnorm-func-ref5:
.. doxygenfunction:: qnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rnorm-func-ref1:
.. doxygenfunction:: rnorm(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rnorm-func-ref2:
.. doxygenfunction:: rnorm(const T1, const T2, const ullint_t)
   :project: statslib

3. Convenience

.. _rnorm-func-ref3:
.. doxygenfunction:: rnorm()
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rnorm-func-ref4:
.. doxygenfunction:: rnorm(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
