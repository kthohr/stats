.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Bernoulli Distribution
======================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Bernoulli distribution:

.. math::

   f(x; p) = p^x (1-p)^{1-x} \times \mathbf{1}[x \in \{0,1\}]

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _dbern-func-ref1:
.. doxygenfunction:: dbern(const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _dbern-func-ref2:
.. doxygenfunction:: dbern(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _dbern-func-ref3:
.. doxygenfunction:: dbern(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _dbern-func-ref4:
.. doxygenfunction:: dbern(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _dbern-func-ref5:
.. doxygenfunction:: dbern(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Cumulative Distribution Function
--------------------------------

The cumulative distribution function of the Bernoulli distribution:

.. math::

   F(x; p) = \sum_{z \leq x} f(z; p) = \begin{cases} 0 & \text{ if } x < 0 \\ 1-p & \text{ if } 0 \leq x < 1 \\ 1 & \text{ if } x \geq 1 \end{cases}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _pbern-func-ref1:
.. doxygenfunction:: pbern(const llint_t, const T, const bool)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _pbern-func-ref2:
.. doxygenfunction:: pbern(const std::vector<eT>&, const T1, const bool)
   :project: statslib

Armadillo
_________

.. _pbern-func-ref3:
.. doxygenfunction:: pbern(const ArmaMat<eT>&, const T1, const bool)
   :project: statslib

Blaze
_____

.. _pbern-func-ref4:
.. doxygenfunction:: pbern(const BlazeMat<eT, To>&, const T1, const bool)
   :project: statslib

Eigen
_____

.. _pbern-func-ref5:
.. doxygenfunction:: pbern(const EigenMat<eT, iTr, iTc>&, const T1, const bool)
   :project: statslib

----

Quantile Function
-----------------

The quantile function of the Bernoulli distribution:

.. math::

   q(r; p) = \begin{cases} 0 & \text{ if } r \leq 1 - p \\ 1 & \text{ else } \end{cases}

Methods for scalar input, as well as for vector/matrix input, are listed below.

Scalar Input
~~~~~~~~~~~~

.. _qbern-func-ref1:
.. doxygenfunction:: qbern(const T1, const T2)
   :project: statslib

Vector/Matrix Input
~~~~~~~~~~~~~~~~~~~

STL Containers
______________

.. _qbern-func-ref2:
.. doxygenfunction:: qbern(const std::vector<eT>&, const T1)
   :project: statslib

Armadillo
_________

.. _qbern-func-ref3:
.. doxygenfunction:: qbern(const ArmaMat<eT>&, const T1)
   :project: statslib

Blaze
_____

.. _qbern-func-ref4:
.. doxygenfunction:: qbern(const BlazeMat<eT, To>&, const T1)
   :project: statslib

Eigen
_____

.. _qbern-func-ref5:
.. doxygenfunction:: qbern(const EigenMat<eT, iTr, iTc>&, const T1)
   :project: statslib

----

Random Sampling
---------------

Random sampling for the Bernoulli distribution is achieved via the inverse probability integral transform.

Scalar Output
~~~~~~~~~~~~~

1. Random number engines

.. _rbern-func-ref1:
.. doxygenfunction:: rbern(const T, rand_engine_t&)
   :project: statslib

2. Seed values

.. _rbern-func-ref2:
.. doxygenfunction:: rbern(const T, const ullint_t)
   :project: statslib

Vector/Matrix Output
~~~~~~~~~~~~~~~~~~~~

.. _rbern-func-ref3:
.. doxygenfunction:: rbern(const ullint_t, const ullint_t, const T1)
   :project: statslib
