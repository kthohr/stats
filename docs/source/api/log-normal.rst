.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Log-Normal Distribution
=======================

The density function of the log-Normal distribution:

.. math::

   f(x; \mu, \sigma) = f(x; \mu, \sigma) = \frac{1}{x} \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(\ln x-\mu)^2}{2 \sigma^2} \right)

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dlnorm-func-ref1:
.. doxygenfunction:: dlnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dlnorm-func-ref2:
.. doxygenfunction:: dlnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dlnorm-func-ref3:
.. doxygenfunction:: dlnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dlnorm-func-ref4:
.. doxygenfunction:: dlnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dlnorm-func-ref5:
.. doxygenfunction:: dlnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _plnorm-func-ref1:
.. doxygenfunction:: plnorm(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _plnorm-func-ref2:
.. doxygenfunction:: plnorm(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _plnorm-func-ref3:
.. doxygenfunction:: plnorm(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _plnorm-func-ref4:
.. doxygenfunction:: plnorm(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _plnorm-func-ref5:
.. doxygenfunction:: plnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qlnorm-func-ref1:
.. doxygenfunction:: qlnorm(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qlnorm-func-ref2:
.. doxygenfunction:: qlnorm(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qlnorm-func-ref3:
.. doxygenfunction:: qlnorm(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qlnorm-func-ref4:
.. doxygenfunction:: qlnorm(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qlnorm-func-ref5:
.. doxygenfunction:: qlnorm(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rlnorm-func-ref1:
.. doxygenfunction:: rlnorm(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rlnorm-func-ref2:
.. doxygenfunction:: rlnorm(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rlnorm-func-ref3:
.. doxygenfunction:: rlnorm(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
