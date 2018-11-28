.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Uniform Distribution
====================

The density function of the Uniform distribution:

.. math::

   f(x; a,b) = \frac{1}{b-a} \times \mathbf{1}[ a \leq x \leq b]

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dunif-func-ref1:
.. doxygenfunction:: dunif(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dunif-func-ref2:
.. doxygenfunction:: dunif(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dunif-func-ref3:
.. doxygenfunction:: dunif(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dunif-func-ref4:
.. doxygenfunction:: dunif(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dunif-func-ref5:
.. doxygenfunction:: dunif(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _punif-func-ref1:
.. doxygenfunction:: punif(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _punif-func-ref2:
.. doxygenfunction:: punif(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _punif-func-ref3:
.. doxygenfunction:: punif(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _punif-func-ref4:
.. doxygenfunction:: punif(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _punif-func-ref5:
.. doxygenfunction:: punif(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qunif-func-ref1:
.. doxygenfunction:: qunif(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qunif-func-ref2:
.. doxygenfunction:: qunif(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qunif-func-ref3:
.. doxygenfunction:: qunif(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qunif-func-ref4:
.. doxygenfunction:: qunif(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qunif-func-ref5:
.. doxygenfunction:: qunif(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _runif-func-ref1:
.. doxygenfunction:: runif(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _runif-func-ref2:
.. doxygenfunction:: runif(const T1, const T2, const ullint_t)
   :project: statslib

.. _runif-func-ref3:
.. doxygenfunction:: runif()
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _runif-func-ref4:
.. doxygenfunction:: runif(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
