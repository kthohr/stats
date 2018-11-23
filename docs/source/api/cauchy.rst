.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Cauchy Distribution
===================

The density function of the Cauchy distribution:

.. math::

   f(x; \mu, \sigma) = \dfrac{1}{\pi \sigma \left[ 1 + \left( \frac{x - \mu}{\sigma} \right)^2 \right]}

PDF
---

.. _dcauchy-func-ref:
.. doxygenfunction:: dcauchy(const T1, const T2, const T3, const bool)
   :project: statslib

CDF
---

.. _pcauchy-func-ref:
.. doxygenfunction:: pcauchy(const T1, const T2, const T3, const bool)
   :project: statslib

Quantile
--------

.. _qcauchy-func-ref:
.. doxygenfunction:: qcauchy(const T1, const T2, const T3)
   :project: statslib

Sampling
--------

.. _rcauchy-func-ref1:
.. doxygenfunction:: rcauchy(const T1, const T2, rand_engine_t&)
   :project: statslib

.. _rcauchy-func-ref2:
.. doxygenfunction:: rcauchy(const T1, const T2, ullint_t)
   :project: statslib
