.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Wishart Distribution
====================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Wishart distribution:

.. math::

   f(\mathbf{X}; \boldsymbol{\Psi}, \nu) = \dfrac{1}{2^{\frac{\nu p}{2}} |\boldsymbol{\Psi}|^{\frac{\nu}{2}} \Gamma_p\left( \frac{\nu}{2} \right)} | \mathbf{X} |^{\frac{\nu - p - 1}{2}} \exp \left( - \frac{1}{2} \text{tr} (\boldsymbol{\Psi}^{-1} \mathbf{X}) \right)

where :math:`\Gamma_p` is the Multivariate Gamma function, :math:`| \cdot |` denotes the matrix determinant, and :math:`\text{tr}(\cdot)` denotes the matrix trace.

.. _dwish-func-ref1:
.. doxygenfunction:: dwish(const mT&, const mT&, const pT, const bool)
   :project: statslib

----

Random Sampling
---------------

.. _rwish-func-ref1:
.. doxygenfunction:: rwish(const mT&, const pT, const bool)
   :project: statslib
