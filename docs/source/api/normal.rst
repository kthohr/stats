.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Normal Distribution
===================

The density function of the Normal (Gaussian) distribution:

.. math::

   f(x; \mu, \sigma) = \frac{1}{\sqrt{2 \pi} \sigma} \exp \left( - \frac{(x-\mu)^2}{2 \sigma^2} \right)

.. _dnorm-func-ref:
.. doxygenfunction:: dnorm(const T1, const T2, const T3, const bool)
   :project: statslib

.. _pnorm-func-ref:
.. doxygenfunction:: pnorm(const T1, const T2, const T3, const bool)
   :project: statslib

.. _qnorm-func-ref:
.. doxygenfunction:: qnorm(const T1, const T2, const T3)
   :project: statslib

.. _rnorm-func-ref:
.. doxygenfunction:: rnorm(const T1, const T2, ullint_t)
   :project: statslib

.. _rnorm-func-ref2:
.. doxygenfunction:: rnorm(const T1, const T2, rand_engine_t&)
   :project: statslib
