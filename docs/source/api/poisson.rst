.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Poisson Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Poisson distribution:

.. math::

   f(x; \lambda) = \dfrac{\lambda^x \exp(-\lambda)}{x!} \times \mathbf{1}[ x \geq 0]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dpois-func-ref1:
.. doxygenfunction:: dpois(const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dpois-func-ref2:
.. doxygenfunction:: dpois(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _dpois-func-ref3:
.. doxygenfunction:: dpois(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _dpois-func-ref4:
.. doxygenfunction:: dpois(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _dpois-func-ref5:
.. doxygenfunction:: dpois(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Poisson distribution:

.. math::

   F(x; \lambda) = \sum_{z \leq x} f(z; \lambda) = \exp(-\lambda) \sum_{z \leq x} \dfrac{\lambda^z}{z!} \times \mathbf{1}[ z \geq 0]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _ppois-func-ref1:
.. doxygenfunction:: ppois(const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _ppois-func-ref2:
.. doxygenfunction:: ppois(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _ppois-func-ref3:
.. doxygenfunction:: ppois(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _ppois-func-ref4:
.. doxygenfunction:: ppois(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _ppois-func-ref5:
.. doxygenfunction:: ppois(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Poisson distribution:

.. math::

   q(p; \lambda) = \inf \left\{ x : p \leq F(x; \lambda) \right\}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qpois-func-ref1:
.. doxygenfunction:: qpois(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qpois-func-ref2:
.. doxygenfunction:: qpois(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qpois-func-ref3:
.. doxygenfunction:: qpois(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qpois-func-ref4:
.. doxygenfunction:: qpois(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qpois-func-ref5:
.. doxygenfunction:: qpois(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rpois-func-ref1:
.. doxygenfunction:: rpois(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rpois-func-ref2:
.. doxygenfunction:: rpois(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rpois-func-ref3:
.. doxygenfunction:: rpois(const ullint_t, const ullint_t, const T1)
   :project: statslib
