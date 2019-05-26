.. Copyright (c) 2011--2018 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Inverse-Wishart Distribution
============================

The density function of the inverse-Wishart distribution:

.. math::

   f(\mathbf{X}; \boldsymbol{\Psi}, \nu) = \dfrac{|\boldsymbol{\Psi}|^{\frac{\nu}{2}}}{2^{\frac{\nu p}{2}} \Gamma_p\left( \frac{\nu}{2} \right)} | \mathbf{X} |^{-\frac{\nu + p + 1}{2}} \exp \left( - \frac{1}{2} \text{tr} (\boldsymbol{\Psi} \mathbf{X}^{-1}) \right)

where :math:`\Gamma_p` is the Multivariate Gamma function.

PDF
---

.. _dinvwish-func-ref1:
.. doxygenfunction:: dinvwish(const mT&, const mT&, const pT, const bool)
   :project: statslib

Random Sampling
---------------

.. _rinvwish-func-ref1:
.. doxygenfunction:: rinvwish(const mT&, const pT, const bool)
   :project: statslib
