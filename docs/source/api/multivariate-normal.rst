.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Multivariate-Normal Distribution
================================

**Table of contents**

.. contents:: :local:

----

Density Function
----------------

The density function of the Multivariate-Normal distribution:

.. math::

   f(\mathbf{x}; \boldsymbol{\mu}, \boldsymbol{\Sigma}) = \dfrac{1}{\sqrt{(2\pi)^k |\boldsymbol{\Sigma}|}} \exp \left( - \frac{1}{2} (\mathbf{x} - \boldsymbol{\mu})^\top \boldsymbol{\Sigma}^{-1} (\mathbf{x} - \boldsymbol{\mu}) \right)

where :math:`k` is the dimension of the real-valued vector :math:`\mathbf{x}` and :math:`| \cdot |` denotes the matrix determinant.

.. _dmvnorm-func-ref1:
.. doxygenfunction:: dmvnorm(const mT&, const mT&, const mT&, const bool)
   :project: statslib

----

Random Sampling
---------------

.. _rmvnorm-func-ref1:
.. doxygenfunction:: rmvnorm(const mT&, const mT&, const bool)
   :project: statslib
