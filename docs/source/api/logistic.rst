.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Logistic Distribution
=====================

The density function of the Logistic distribution:

.. math::

   f(x; \mu, \sigma) = \dfrac{\exp\left( - \frac{x-\mu}{\sigma} \right)}{\sigma \left( 1 + \exp\left( - \frac{x-\mu}{\sigma} \right) \right)^2 }

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dlogis-func-ref1:
.. doxygenfunction:: dlogis(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dlogis-func-ref2:
.. doxygenfunction:: dlogis(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dlogis-func-ref3:
.. doxygenfunction:: dlogis(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dlogis-func-ref4:
.. doxygenfunction:: dlogis(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dlogis-func-ref5:
.. doxygenfunction:: dlogis(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _plogis-func-ref1:
.. doxygenfunction:: plogis(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _plogis-func-ref2:
.. doxygenfunction:: plogis(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _plogis-func-ref3:
.. doxygenfunction:: plogis(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _plogis-func-ref4:
.. doxygenfunction:: plogis(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _plogis-func-ref5:
.. doxygenfunction:: plogis(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qlogis-func-ref1:
.. doxygenfunction:: qlogis(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qlogis-func-ref2:
.. doxygenfunction:: qlogis(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qlogis-func-ref3:
.. doxygenfunction:: qlogis(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qlogis-func-ref4:
.. doxygenfunction:: qlogis(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qlogis-func-ref5:
.. doxygenfunction:: qlogis(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rlogis-func-ref1:
.. doxygenfunction:: rlogis(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rlogis-func-ref2:
.. doxygenfunction:: rlogis(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rlogis-func-ref3:
.. doxygenfunction:: rlogis(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
