.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Gamma Distribution
==========================

The density function of the inverse-Gamma distribution:

.. math::

   f(x; \alpha, \beta) = \dfrac{\beta^{\alpha}}{\Gamma(\alpha)} x^{-\alpha-1} \exp\left(-\frac{\beta}{x}\right) \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` is the Gamma function.

PDF
---

Scalar Input
~~~~~~~~~~~~

.. _dinvgamma-func-ref1:
.. doxygenfunction:: dinvgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _dinvgamma-func-ref2:
.. doxygenfunction:: dinvgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _dinvgamma-func-ref3:
.. doxygenfunction:: dinvgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _dinvgamma-func-ref4:
.. doxygenfunction:: dinvgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _dinvgamma-func-ref5:
.. doxygenfunction:: dinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

CDF
---

Scalar Input
~~~~~~~~~~~~

.. _pinvgamma-func-ref1:
.. doxygenfunction:: pinvgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _pinvgamma-func-ref2:
.. doxygenfunction:: pinvgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

2. Armadillo

.. _pinvgamma-func-ref3:
.. doxygenfunction:: pinvgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

3. Blaze

.. _pinvgamma-func-ref4:
.. doxygenfunction:: pinvgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

4. Eigen

.. _pinvgamma-func-ref5:
.. doxygenfunction:: pinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

Quantile
--------

Scalar Input
~~~~~~~~~~~~

.. _qinvgamma-func-ref1:
.. doxygenfunction:: qinvgamma(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

1. STL Containers

.. _qinvgamma-func-ref2:
.. doxygenfunction:: qinvgamma(const std::vector<eT>&, const T1, const T2)
   :project: statslib

2. Armadillo

.. _qinvgamma-func-ref3:
.. doxygenfunction:: qinvgamma(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

3. Blaze

.. _qinvgamma-func-ref4:
.. doxygenfunction:: qinvgamma(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

4. Eigen

.. _qinvgamma-func-ref5:
.. doxygenfunction:: qinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rinvgamma-func-ref1:
.. doxygenfunction:: rinvgamma(const T1, const T2, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rinvgamma-func-ref2:
.. doxygenfunction:: rinvgamma(const T1, const T2, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rinvgamma-func-ref3:
.. doxygenfunction:: rinvgamma(const ullint_t, const ullint_t, const T1, const T2)
   :project: statslib
