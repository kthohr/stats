.. Copyright (c) 2011-2023 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Rademacher Distribution
=======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Rademacher distribution:

.. math::

   f(x; p) = p \times \mathbf{1}[x = 1] + (1-p) \times \mathbf{1}[x = -1]

Note that this is a somewhat more general definition of the Rademacher distribution than is standard in the statistics literature,
which assumes :math:`p = 0.5`.

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dradem-func-ref1:
.. doxygenfunction:: dradem(const llint_t x, const T prob_par, const bool log_form)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dradem-func-ref2:
.. doxygenfunction:: dradem(const std::vector<eT>& x, const T1 prob_par, const bool log_form)
   :project: statslib

Armadillo
_________

.. _dradem-func-ref3:
.. doxygenfunction:: dradem(const ArmaGen<mT,tT>& X, const T1 prob_par, const bool log_form)
   :project: statslib

Blaze
_____

.. _dradem-func-ref4:
.. doxygenfunction:: dradem(const BlazeMat<eT,To>& X, const T1 prob_par, const bool log_form)
   :project: statslib

Eigen
_____

.. _dradem-func-ref5:
.. doxygenfunction:: dradem(const EigenMat<eT,iTr,iTc>& X, const T1 prob_par, const bool log_form)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Rademacher distribution:

.. math::

   F(x; p) = \sum_{z \leq x} f(z; p) = \begin{cases} 0 & \text{ if } x < -1 \\ 1-p & \text{ if } x < 1 \\ 1 & \text{ if } x \geq 1 \end{cases}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pradem-func-ref1:
.. doxygenfunction:: pradem(const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pradem-func-ref2:
.. doxygenfunction:: pradem(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _pradem-func-ref3:
.. doxygenfunction:: pradem(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _pradem-func-ref4:
.. doxygenfunction:: pradem(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _pradem-func-ref5:
.. doxygenfunction:: pradem(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Rademacher distribution:

.. math::

   q(r; p) = \begin{cases} -1 & \text{ if } r \leq 1 - p \\ 1 & \text{ else } \end{cases}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qradem-func-ref1:
.. doxygenfunction:: qradem(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qradem-func-ref2:
.. doxygenfunction:: qradem(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qradem-func-ref3:
.. doxygenfunction:: qradem(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qradem-func-ref4:
.. doxygenfunction:: qradem(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qradem-func-ref5:
.. doxygenfunction:: qradem(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Rademacher distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rradem-func-ref1:
.. doxygenfunction:: rradem(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rradem-func-ref2:
.. doxygenfunction:: rradem(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

1. Random number engines

.. _rradem-func-ref3:
.. doxygenfunction:: rradem(const ullint_t, const ullint_t, const T1, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rradem-func-ref4:
.. doxygenfunction:: rradem(const ullint_t, const ullint_t, const T1, const ullint_t)
   :project: statslib
