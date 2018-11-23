.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Chi-squared Distribution
========================

The density function of the Chi-squared distribution:

.. math::

   f(x; k) = \dfrac{x^{k/2 - 1} \exp(-x/2)}{ 2^{k/2} \Gamma(k/2)} \times \mathbf{1}[ x \geq 0]

PDF
---

.. _dchisq-func-ref:
.. doxygenfunction:: dchisq(const T1, const T2, const bool)
   :project: statslib

CDF
---

.. _pchisq-func-ref:
.. doxygenfunction:: pchisq(const T1, const T2, const bool)
   :project: statslib

Quantile
--------

.. _qchisq-func-ref:
.. doxygenfunction:: qchisq(const T1, const T2)
   :project: statslib

Sampling
--------

.. _rchisq-func-ref1:
.. doxygenfunction:: rchisq(const T, rand_engine_t&)
   :project: statslib

.. _rchisq-func-ref2:
.. doxygenfunction:: rchisq(const T, ullint_t)
   :project: statslib
