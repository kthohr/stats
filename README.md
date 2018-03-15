# StatsLib &nbsp; [![Build Status](https://travis-ci.org/kthohr/stats.svg?branch=master)](https://travis-ci.org/kthohr/stats) [![Coverage Status](https://codecov.io/github/kthohr/stats/coverage.svg?branch=master)](https://codecov.io/github/kthohr/stats?branch=master)

StatsLib is a templated C++ library of statistical distribution functions.

Features:
* A header-only library of probability density functions, cumulative distribution functions, quantile functions, and random sampling methods.
* Functions are written in a concise C++11 `constexpr`-based format.
    * Built on the [GCE-Math library](https://github.com/kthohr/gcem), StatsLib can operate as a compile-time or run-time computation engine.
* A simple, **R**-like syntax.
* Optional vector-matrix functionality with wrappers to support several popular linear algebra libraries, including:
    * [Armadillo](http://arma.sourceforge.net/)
    * [Blaze](https://bitbucket.org/blaze-lib/blaze)
    * [Eigen](http://eigen.tuxfamily.org/index.php)
* Matrix-based operations are parallelizable with OpenMP.

## Available Distributions

cdf, pdf, quantile and random sampling functions are available for the following distributions:

* Bernoulli 
* Beta
* Binomial
* Cauchy
* Chi-squared
* Exponential
* F
* Gamma
* Inverse-Gamma
* Laplace
* Logistic
* Log-Normal
* Normal (Gaussian)
* Poisson
* Student's t
* Uniform
* Weibull

In addition, pdf and randomization functions are available for several multivariate distributions:

* inverse-Wishart
* Multivariate Normal
* Wishart

## Compiler Options

For inline-only functionality (i.e., no `constexpr` specifiers) use
```cpp
#define STATS_GO_INLINE
```

To use StatsLib with Armadillo:
```cpp
#define STATS_USE_ARMA
```
Similarly, for Blaze or Eigen:
```cpp
#define STATS_USE_BLAZE
#define STATS_USE_EIGEN
```

## Syntax and Examples

Functions are called using an **R**-like syntax.

* density functions: `stats::d*`. For example, the Normal (Gaussian) density is called using
``` cpp
stats::dnorm(<value>,<mean parameter>,<standard deviation>);
```
* cumulative distribution functions: `stats::p*`. For example, the Gamma CDF is called using
``` cpp
stats::pgamma(<value>,<shape parameter>,<scale parameter>);
```
* quantile functions: `stats::q*`. For example, the Beta quantile is called using
``` cpp
stats::qbeta(<value>,<a parameter>,<b parameter>);
```
* random sampling: `stats::r*`. For example, to generate a single draw from the Logistic distribution:
``` cpp
stats::rlogis(<location parameter>,<scale parameter>);
```

<br>

All of these functions have matrix-based equivalents using Armadillo, Blaze, and Eigen dense matrices.

* The pdf, cdf, and quantile functions can take matrix-valued arguments. For example,

```cpp
arma::mat norm_pdf_vals = stats::dnorm(arma::ones(10,20),1.0,2.0);
```

* The randomization functions (`r*`) can output random matrices of arbitrary dimensions. For example,</li>

```cpp
# Armadillo:
arma::mat gamma_rvs = stats::rgamma<arma::mat>(100,50,3.0,2.0);
# Blaze:
blaze::DynamicMatrix<double> gamma_rvs = stats::rgamma<blaze::DynamicMatrix<double>>(100,50,3.0,2.0);
# Eigen:
Eigen::MatrixXd gamma_rvs = stats::rgamma<Eigen::MatrixXd>(100,50,3.0,2.0);
```

<!-- <ul style="list-style-type:none">
    <li>will generate a 100-by-50 matrix of iid draws from a Gamma(3,2) distribution.</li>
</ul> -->
&nbsp; &nbsp; &nbsp; &nbsp; will generate a 100-by-50 matrix of iid draws from a Gamma(3,2) distribution.

* All matrix-based operations are parallelizable with OpenMP. For GCC and Clang compilers, simply include the `-fopenmp` option during compilation.

More examples with code:
```cpp
// evaluate the normal PDF at x = 1, mu = 0, sigma = 1
double dval_1 = stats::dnorm(1.0,0.0,1.0);
 
// evaluate the normal PDF at x = 1, mu = 0, sigma = 1, and return the log value
double dval_2 = stats::dnorm(1.0,0.0,1.0,true);
 
// evaluate the normal CDF at x = 1, mu = 0, sigma = 1
double pval = stats::pnorm(1.0,0.0,1.0);
 
// evaluate the Laplacian quantile at p = 0.1, mu = 0, sigma = 1
double qval = stats::qlaplace(0.1,0.0,1.0);

// generate a t-distributed random variable with dof = 30
double rval = stats::rt(30);

// matrix output
arma::mat beta_rvs = stats::rbeta<arma::mat>(100,100,3.0,2.0);
// matrix input
arma::mat beta_cdf_vals = stats::pbeta(beta_rvs,3.0,2.0);
```

## Installation

StatsLib is a header-only library. Just copy the contents of the include folder and add the header files to your project using `#include "stats.hpp"`.

## Compile-time computation

In addition to being a standard run-time library, StatsLib can also operate as a compile-time library. Compile-time features are enabled using the ```constexpr``` specifier:
```cpp
#include "stats.hpp"

int main()
{
    
    constexpr double dens_1 = stats::dlaplace(1.0,1.0,2.0);  // answer = 0.25
    constexpr double prob_1 = stats::plaplace(1.0,1.0,2.0);  // answer = 0.5
    constexpr double quant_1 = stats::qlaplace(0.1,1.0,2.0); // answer = -2.218875...

    return 0;
}
```
Assembly code generated by Clang:
```assembly
LCPI0_0:
	.quad	-4611193153885729483    ## double -2.2188758248682015
LCPI0_1:
	.quad	4602678819172646912     ## double 0.5
LCPI0_2:
	.quad	4598175219545276417     ## double 0.25000000000000006
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	xor	eax, eax
	movsd	xmm0, qword ptr [rip + LCPI0_0] ## xmm0 = mem[0],zero
	movsd	xmm1, qword ptr [rip + LCPI0_1] ## xmm1 = mem[0],zero
	movsd	xmm2, qword ptr [rip + LCPI0_2] ## xmm2 = mem[0],zero
	mov	dword ptr [rbp - 4], 0
	movsd	qword ptr [rbp - 16], xmm2
	movsd	qword ptr [rbp - 24], xmm1
	movsd	qword ptr [rbp - 32], xmm0
	pop	rbp
	ret
	.cfi_endproc
```

## Author

Keith O'Hara

## License

Apache Version 2
