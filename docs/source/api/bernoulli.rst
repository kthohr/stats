.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Bernoulli Distribution
======================

The density function of the Bernoulli distribution:

.. math::

   f(x; p) = p^x (1-p)^{1-x} \mathbf{1}[x \in \{0,1\}]

PDF
---

.. _dbern-func-ref:
.. doxygenfunction:: dbern(const llint_t, const T, const bool)
   :project: statslib

CDF
---

.. _pbern-func-ref:
.. doxygenfunction:: pbern(const llint_t, const T, const bool)
   :project: statslib

Quantile
--------

.. _qbern-func-ref:
.. doxygenfunction:: qbern(const T1, const T2)
   :project: statslib

Sampling
--------

.. _rbern-func-ref1:
.. doxygenfunction:: rbern(const T, rand_engine_t&)
   :project: statslib

.. _rbern-func-ref2:
.. doxygenfunction:: rbern(const T, ullint_t)
   :project: statslib
