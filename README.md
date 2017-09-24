# StatsLib

[![Build Status](https://travis-ci.org/kthohr/stats.svg?branch=master)](https://travis-ci.org/kthohr/stats)
[![Coverage Status](https://codecov.io/github/kthohr/stats/coverage.svg?branch=master)](https://codecov.io/github/kthohr/stats?branch=master)

StatsLib is a templated C++ library for fast computation of statistical distribution functions.

## List of available distributons

cdf, pdf, quantile, and random variable generation:

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
* Uniform

pdf and random variable generation only:

* inverse-Wishart
* Multivariate Normal
* Wishart

Functions are written in a clean R-like syntax.

## Examples

```
// evaulate the normal PDF at x = 1, mu = 0, sigma = 1
double dval_1 = stats::dnorm(1.0,0.0,1.0)
 
// evaulate the normal PDF at x = 1, mu = 0, sigma = 1, and return the log value
double dval_2 = stats::dnorm(1.0,0.0,1.0,true)
 
// evaulate the normal CDF at x = 1, mu = 0, sigma = 1
double pval_1 = stats::pnorm(1.0,0.0,1.0)
 
// evaulate the Laplacian quantile at p = 0.1, mu = 0, sigma = 1
double qval_1 = stats::qlaplace(0.1,0.0,1.0)
```
