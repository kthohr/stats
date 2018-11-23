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

template<typename T, typename not_arma_mat<T>::type*>
statslib_inline
T
rmvnorm(const T& mu_par, const T& Sigma_par, const bool pre_chol)
{
    T ret;

    const ullint_t K = mat_ops::n_rows(Sigma_par);

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

#ifdef STATS_USE_ARMA
template<typename mT, typename eT>
statslib_inline
mT
rmvnorm(const mT& mu_par, const ArmaMat<eT>& Sigma_par, const bool pre_chol)
{   // mu is templated as it could be of type Col<eT> or Mat<eT>
    mT ret;

    const ullint_t K = Sigma_par.n_rows;

    if (mu_par.n_elem != K)
    {
        printf("rmvnorm: dimensions of mu and Sigma don't agree.\n");
        return ret;
    }

    //

    const ArmaMat<eT> A = (pre_chol) ? Sigma_par : arma::chol(Sigma_par,"lower"); // should be lower-triangular

    // ret = mu_par + A * rnorm<mT>(K,1);
    ret = mu_par + A * arma::randn<mT>(K,1);

    //
    
    return ret;
}
#endif

//
// n-samples: results will be an n x K matrix

template<typename T, typename not_arma_mat<T>::type*>
statslib_inline
T
rmvnorm(const ullint_t n, const T& mu_par, const T& Sigma_par, const bool pre_chol)
{
    T ret;

    const ullint_t K = mat_ops::n_rows(Sigma_par);

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

#ifdef STATS_USE_ARMA
template<typename mT, typename eT>
statslib_inline
ArmaMat<eT>
rmvnorm(const ullint_t n, const mT& mu_par, const ArmaMat<eT>& Sigma_par, const bool pre_chol)
{   // mu is templated as it could be of type Col<eT> or Mat<eT>
    ArmaMat<eT> ret;

    const ullint_t K = Sigma_par.n_rows;

    if (mu_par.n_elem != K)
    {
        printf("rmvnorm: dimensions of mu and Sigma don't agree.\n");
        return ret;
    }

    //

    const ArmaMat<eT> A = (pre_chol) ? Sigma_par : arma::chol(Sigma_par,"lower"); // should be lower-triangular

    // ret = arma::repmat(mu_par.t(),n,1) + rnorm<ArmaMat<eT>>(n,K) * A.t();
    ret = arma::repmat(mu_par.t(),n,1) + arma::randn<ArmaMat<eT>>(n,K) * A.t();

    //
    
    return ret;
}
#endif
