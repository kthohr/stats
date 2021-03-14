.. Copyright (c) 2011-2021 Keith O'Hara

   Distributed under the terms of the Apache License, Version 2.0.

   The full license is in the file LICENSE, distributed with this software.

Examples and Tests
==================

.. contents:: :local:

Examples
--------

.. code:: cpp

    // evaluate the normal PDF at x = 1, mu = 0, sigma = 1
    double dval_1 = stats::dnorm(1.0,0.0,1.0);
    
    // evaluate the normal PDF at x = 1, mu = 0, sigma = 1, and return the log value
    double dval_2 = stats::dnorm(1.0,0.0,1.0,true);
    
    // evaluate the normal CDF at x = 1, mu = 0, sigma = 1
    double pval = stats::pnorm(1.0,0.0,1.0);
    
    // evaluate the Laplacian quantile at p = 0.1, mu = 0, sigma = 1
    double qval = stats::qlaplace(0.1,0.0,1.0);

    // draw from a t-distribution dof = 30
    double rval = stats::rt(30);

    // matrix output
    arma::mat beta_rvs = stats::rbeta<arma::mat>(100,100,3.0,2.0);
    // matrix input
    arma::mat beta_cdf_vals = stats::pbeta(beta_rvs,3.0,2.0);


----

Test suite
----------

You can build the tests suite as follows:

.. code:: bash

    # compile tests
    cd ./tests
    ./setup
    ./dens
    ./configure
    make
    ./dnorm.test
