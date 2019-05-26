.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Gamma Distribution
==================

The density function of the Gamma distribution:

.. math::

   f(x; k, \theta) = \dfrac{x^{k-1}\exp(-x/\theta)}{\theta^k \Gamma(k)} \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` is the Gamma function.

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dgamma-func-ref1:
.. doxygenfunction:: dgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dgamma-func-ref2:
.. doxygenfunction:: dgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dgamma-func-ref3:
.. doxygenfunction:: dgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dgamma-func-ref4:
.. doxygenfunction:: dgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dgamma-func-ref5:
.. doxygenfunction:: dgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pgamma-func-ref1:
.. doxygenfunction:: pgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pgamma-func-ref2:
.. doxygenfunction:: pgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _pgamma-func-ref3:
.. doxygenfunction:: pgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _pgamma-func-ref4:
.. doxygenfunction:: pgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _pgamma-func-ref5:
.. doxygenfunction:: pgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qgamma-func-ref1:
.. doxygenfunction:: qgamma(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qgamma-func-ref2:
.. doxygenfunction:: qgamma(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qgamma-func-ref3:
.. doxygenfunction:: qgamma(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qgamma-func-ref4:
.. doxygenfunction:: qgamma(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qgamma-func-ref5:
.. doxygenfunction:: qgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rgamma-func-ref1:
.. doxygenfunction:: rgamma(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rgamma-func-ref2:
.. doxygenfunction:: rgamma(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rgamma-func-ref3:
.. doxygenfunction:: rgamma(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
