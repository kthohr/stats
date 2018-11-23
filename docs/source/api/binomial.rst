.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Binomial Distribution
=====================

The density function of the Binomial distribution:

.. math::

   f(x; n, p) = \binom{n}{x} p^x (1-p)^{n-x}

PDF
---

.. _dbinom-func-ref:
.. doxygenfunction:: dbinom(const llint_t, const llint_t, const T, const bool)
   :project: statslib

CDF
---

.. _pbinom-func-ref:
.. doxygenfunction:: pbinom(const llint_t, const llint_t, const T, const bool)
   :project: statslib

Quantile
--------

.. _qbinom-func-ref:
.. doxygenfunction:: qbinom(const T1, const llint_t, const T2)
   :project: statslib

Sampling
--------

.. _rbinom-func-ref1:
.. doxygenfunction:: rbinom(const llint_t, const T, rand_engine_t&)
   :project: statslib

.. _rbinom-func-ref2:
.. doxygenfunction:: rbinom(const llint_t, const T, ullint_t)
   :project: statslib
