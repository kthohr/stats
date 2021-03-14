.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Gamma Distribution
==========================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the inverse-Gamma distribution:

.. math::

   f(x; \alpha, \beta) = \dfrac{\beta^{\alpha}}{\Gamma(\alpha)} x^{-\alpha-1} \exp\left(-\frac{\beta}{x}\right) \times \mathbf{1}[ x \geq 0 ]

where :math:`\Gamma(\cdot)` denotes the Gamma function, :math:`\alpha` is the shape parameter, and :math:`\beta` is the rate parameter.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dinvgamma-func-ref1:
.. doxygenfunction:: dinvgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dinvgamma-func-ref2:
.. doxygenfunction:: dinvgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _dinvgamma-func-ref3:
.. doxygenfunction:: dinvgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _dinvgamma-func-ref4:
.. doxygenfunction:: dinvgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _dinvgamma-func-ref5:
.. doxygenfunction:: dinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the inverse-Gamma distribution:

.. math::

   F(x; \alpha, \beta) = \int_0^x f(z; \alpha, \beta) dz = 1 - \frac{\gamma(1/x,\beta/x)}{\Gamma (\alpha)}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pinvgamma-func-ref1:
.. doxygenfunction:: pinvgamma(const T1, const T2, const T3, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pinvgamma-func-ref2:
.. doxygenfunction:: pinvgamma(const std::vector<eT>&, const T1, const T2, const bool)
   :project: statslib

Armadillo
_________

.. _pinvgamma-func-ref3:
.. doxygenfunction:: pinvgamma(const ArmaMat<eT>&, const T1, const T2, const bool)
   :project: statslib

Blaze
_____

.. _pinvgamma-func-ref4:
.. doxygenfunction:: pinvgamma(const BlazeMat<eT, To>&, const T1, const T2, const bool)
   :project: statslib

Eigen
_____

.. _pinvgamma-func-ref5:
.. doxygenfunction:: pinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the inverse-Gamma distribution:

.. math::

   q(p; \alpha, \beta) = \inf \left\{ x : p \leq 1 - \frac{\gamma(1/x,\beta/x)}{\Gamma (\alpha)} \right\}

where :math:`\Gamma(\cdot)` denotes the gamma function and :math:`\gamma(\cdot, \cdot)` denotes the incomplete gamma function.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qinvgamma-func-ref1:
.. doxygenfunction:: qinvgamma(const T1, const T2, const T3)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qinvgamma-func-ref2:
.. doxygenfunction:: qinvgamma(const std::vector<eT>&, const T1, const T2)
   :project: statslib

Armadillo
_________

.. _qinvgamma-func-ref3:
.. doxygenfunction:: qinvgamma(const ArmaMat<eT>&, const T1, const T2)
   :project: statslib

Blaze
_____

.. _qinvgamma-func-ref4:
.. doxygenfunction:: qinvgamma(const BlazeMat<eT, To>&, const T1, const T2)
   :project: statslib

Eigen
_____

.. _qinvgamma-func-ref5:
.. doxygenfunction:: qinvgamma(const EigenMat<eT, iTr, iTc>&, const T1, const T2)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the inverse-Gamma distribution is achieved by simulating :math:`X \sim G(\alpha, 1/\beta)`, then returning

.. math::

   Z = \frac{1}{X} \sim \text{IG}(\alpha,\beta)


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
