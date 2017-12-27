# StatsLib

[![Build Status](https://travis-ci.org/kthohr/stats.svg?branch=master)](https://travis-ci.org/kthohr/stats)
[![Coverage Status](https://codecov.io/github/kthohr/stats/coverage.svg?branch=master)](https://codecov.io/github/kthohr/stats?branch=master)

StatsLib is a templated C++ library for fast computation of statistical distribution functions.

Vector-matrix functionality is built on the [Armadillo C++ linear algebra library](http://arma.sourceforge.net/).

## List of available distributons

cdf, pdf, quantile, and random variable generation are available for the following distributions:

* Bernoulli
* Beta
* Binomial
* Cauchy
* Chi-squared
* Exponential
* Gamma
* Inverse-Gamma
* Laplace
* Logistic
* Log-Normal
* Normal (Gaussian)
* Student's t
* Uniform

pdf and random variable generation only:

* inverse-Wishart
* Multivariate Normal
* Wishart

## Examples

Functions are called using a clean R-like syntax.

```cpp
// evaluate the normal PDF at x = 1, mu = 0, sigma = 1
double dval_1 = stats::dnorm(1.0,0.0,1.0)
 
// evaluate the normal PDF at x = 1, mu = 0, sigma = 1, and return the log value
double dval_2 = stats::dnorm(1.0,0.0,1.0,true)
 
// evaluate the normal CDF at x = 1, mu = 0, sigma = 1
double pval_1 = stats::pnorm(1.0,0.0,1.0)
 
// evaluate the Laplacian quantile at p = 0.1, mu = 0, sigma = 1
double qval_1 = stats::qlaplace(0.1,0.0,1.0)

// matrix input of beta-distributed random variables
arma::mat beta_rvs = stats::rbeta(100,100,3.0,2.0);
arma::mat beta_cdf_vals = stats::pbeta(beta_rvs,3.0,2.0);
```
