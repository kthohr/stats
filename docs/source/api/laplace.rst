.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Laplace Distribution
====================

The density function of the Laplace distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{2 \sigma} \exp \left( - \frac{|x-\mu|}{\sigma} \right)

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dlaplace-func-ref1:
.. doxygenfunction:: dlaplace(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dlaplace-func-ref2:
.. doxygenfunction:: dlaplace(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dlaplace-func-ref3:
.. doxygenfunction:: dlaplace(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dlaplace-func-ref4:
.. doxygenfunction:: dlaplace(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dlaplace-func-ref5:
.. doxygenfunction:: dlaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _plaplace-func-ref1:
.. doxygenfunction:: plaplace(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _plaplace-func-ref2:
.. doxygenfunction:: plaplace(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _plaplace-func-ref3:
.. doxygenfunction:: plaplace(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _plaplace-func-ref4:
.. doxygenfunction:: plaplace(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _plaplace-func-ref5:
.. doxygenfunction:: plaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qlaplace-func-ref1:
.. doxygenfunction:: qlaplace(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qlaplace-func-ref2:
.. doxygenfunction:: qlaplace(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qlaplace-func-ref3:
.. doxygenfunction:: qlaplace(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qlaplace-func-ref4:
.. doxygenfunction:: qlaplace(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qlaplace-func-ref5:
.. doxygenfunction:: qlaplace(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rlaplace-func-ref1:
.. doxygenfunction:: rlaplace(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rlaplace-func-ref2:
.. doxygenfunction:: rlaplace(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rlaplace-func-ref3:
.. doxygenfunction:: rlaplace(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
