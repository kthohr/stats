/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/*
 * Sample from a multivariate normal distribution
 */

template<typename T>
T
rmvnorm(const T& mu_par, const T& Sigma_par, const bool pre_chol)
{
    T ret;

    const uint_t K = mat_ops::n_rows(Sigma_par);

    if (mat_ops::n_elem(mu_par) != K)
    {
        printf("rmvnorm: dimensions of mu and Sigma don't agree.\n");
        return ret;
    }

    //

    const T A = (pre_chol) ? Sigma_par : mat_ops::chol(Sigma_par); // should be lower-triangular

    ret = mu_par + A * rnorm<T>(K,1);

    //
    
    return ret;
}

//
// n-samples: results will be an n x K matrix

template<typename T>
T
rmvnorm(const uint_t n, const T& mu_par, const T& Sigma_par, const bool pre_chol)
{
    T ret;

    const uint_t K = mat_ops::n_rows(Sigma_par);

    if (mat_ops::n_elem(mu_par) != K)
    {
        printf("rmvnorm: dimensions of mu and Sigma don't agree.\n");
        return ret;
    }

    //

    const T A = (pre_chol) ? Sigma_par : mat_ops::chol(Sigma_par); // should be lower-triangular

    ret = mat_ops::repmat(mat_ops::trans(mu_par),n,1) + rnorm<T>(n,K) * mat_ops::trans(A);

    //
    
    return ret;
}
