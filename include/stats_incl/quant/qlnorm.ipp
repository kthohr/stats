/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
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
 * quantile function of the univariate log-normal distribution
 */

//
// scalar input

namespace internal
{

template<typename T>
statslib_constexpr
T
qlnorm_compute(const T p, const T mu_par, const T sigma_par)
noexcept
{
    return stmath::exp(qnorm(p,mu_par,sigma_par));
}

template<typename T>
statslib_constexpr
T
qlnorm_vals_check(const T p, const T mu_par, const T sigma_par)
noexcept
{
    return( !lnorm_sanity_check(mu_par,sigma_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            !prob_val_check(p) ? \
                STLIM<T>::quiet_NaN() :
            //
            qlnorm_compute(p,mu_par,sigma_par) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qlnorm_type_check(const T1 p, const T2 mu_par, const T3 sigma_par)
noexcept
{
    return qlnorm_vals_check(static_cast<TC>(p),static_cast<TC>(mu_par),static_cast<TC>(sigma_par));
}

}

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qlnorm(const T1 p, const T2 mu_par, const T3 sigma_par)
noexcept
{
    return internal::qlnorm_type_check(p,mu_par,sigma_par);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
void
qlnorm_vec(const eT* __stats_pointer_settings__ vals_in, const T1 mu_par, const T2 sigma_par, 
                 rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qlnorm,vals_in,vals_out,num_elem,mu_par,sigma_par);
}
#endif

}

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
std::vector<rT>
qlnorm(const std::vector<eT>& x, const T1 mu_par, const T2 sigma_par)
{
    STDVEC_DIST_FN(qlnorm_vec,mu_par,sigma_par);
}
#endif

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
ArmaMat<rT>
qlnorm(const ArmaMat<eT>& X, const T1 mu_par, const T2 sigma_par)
{
    ARMA_DIST_FN(qlnorm_vec,mu_par,sigma_par);
}

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
qlnorm(const ArmaGen<mT,tT>& X, const T1 mu_par, const T2 sigma_par)
{
    return qlnorm(X.eval(),mu_par,sigma_par);
}
#endif

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
qlnorm(const BlazeMat<eT,To>& X, const T1 mu_par, const T2 sigma_par)
{
    BLAZE_DIST_FN(qlnorm_vec,mu_par,sigma_par);
}
#endif

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
qlnorm(const EigenMat<eT,iTr,iTc>& X, const T1 mu_par, const T2 sigma_par)
{
    EIGEN_DIST_FN(qlnorm_vec,mu_par,sigma_par);
}
#endif
