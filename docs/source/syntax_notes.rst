.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Syntax
======

Functions are called using an **R**-like syntax. Some general rules:

- density functions: ``stats::d*``. For example, the Normal (Gaussian) density is called using

.. code:: cpp

    stats::dnorm(<value>,<mean parameter>,<standard deviation>);

- cumulative distribution functions: ``stats::p*``. For example, the Gamma CDF is called using

.. code:: cpp

    stats::pgamma(<value>,<shape parameter>,<scale parameter>);

- quantile functions: ``stats::q*``. For example, the Beta quantile is called using

.. code:: cpp

    stats::qbeta(<value>,<a parameter>,<b parameter>);

- random sampling: ``stats::r*``. For example, to generate a single draw from the Logistic distribution:

.. code:: cpp

    stats::rlogis(<location parameter>,<scale parameter>,<seed value or random number engine>);

All of these functions have matrix-based equivalents using Armadillo, Blaze, and Eigen dense matrices.

- The pdf, cdf, and quantile functions can take matrix-valued arguments. For example,

.. code:: cpp

    // Using Armadillo:
    arma::mat norm_pdf_vals = stats::dnorm(arma::ones(10,20),1.0,2.0);

- The randomization functions (``r*``) can output random matrices of arbitrary size. For example, the following code will generate a 100-by-50 matrix of iid draws from a Gamma(3,2) distribution:

.. code:: cpp

    // Armadillo:
    arma::mat gamma_rvs = stats::rgamma<arma::mat>(100,50,3.0,2.0);
    // Blaze:
    blaze::DynamicMatrix<double> gamma_rvs = stats::rgamma<blaze::DynamicMatrix<double>>(100,50,3.0,2.0);
    // Eigen:
    Eigen::MatrixXd gamma_rvs = stats::rgamma<Eigen::MatrixXd>(100,50,3.0,2.0);


- All matrix-based operations are parallelizable with OpenMP. For GCC and Clang compilers, simply include the ``-fopenmp`` option during compilation.
