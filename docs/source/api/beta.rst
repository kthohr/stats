.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Beta Distribution
=================

The density function of the Beta distribution:

.. math::

   f(x; a,b) = \frac{1}{\mathcal{B}(a,b)} x^{a-1} (1-x)^{b-1} \mathbf{1}[0 \leq x \leq 1]

where :math:`\mathcal{B}(a,b)` is the Beta function.

PDF
---

.. _dbeta-func-ref:
.. doxygenfunction:: dbeta(const T1, const T2, const T3, const bool)
   :project: statslib

CDF
---

.. _pbeta-func-ref:
.. doxygenfunction:: pbeta(const T1, const T2, const T3, const bool)
   :project: statslib

Quantile
--------

.. _qbeta-func-ref:
.. doxygenfunction:: qbeta(const T1, const T2, const T3)
   :project: statslib

Sampling
--------

.. _rbeta-func-ref1:
.. doxygenfunction:: rbeta(const T1, const T2, rand_engine_t&)
   :project: statslib

.. _rbeta-func-ref2:
.. doxygenfunction:: rbeta(const T1, const T2, ullint_t)
   :project: statslib
