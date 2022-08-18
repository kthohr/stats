/*################################################################################
  ##
  ##   Copyright (C) 2011-2022 Keith O'Hara
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
 * pdf of the univariate inverse Gaussian distribution
 */

//
// scalar input

namespace internal
{

template<typename T>
statslib_constexpr
T
dinvgauss_log_compute_term_1(const T x, const T lambda_par)
noexcept
{
    return( - T(0.5) * ( T(GCEM_LOG_2PI) + T(3) * stmath::log(x) - stmath::log(lambda_par) ) );
}

template<typename T>
statslib_constexpr
T
dinvgauss_log_compute_term_2(const T x, const T xc, const T mu_par, const T lambda_par)
noexcept
{
    return( - lambda_par * (xc * xc) / (T(2) * mu_par * mu_par * x ) );
}

template<typename T>
statslib_constexpr
T
dinvgauss_log_compute(const T x, const T mu_par, const T lambda_par)
noexcept
{
    return dinvgauss_log_compute_term_1(x, lambda_par) + dinvgauss_log_compute_term_2(x, x - mu_par, mu_par, lambda_par);
}

template<typename T>
statslib_constexpr
T
dinvgauss_limit_vals(const T x, const T mu_par, const T lambda_par)
noexcept
{
    return( x == T(0) && (mu_par == T(0) || lambda_par == T(0)) ? \
                STLIM<T>::infinity() :
            // x == 0
            x == T(0) ? \
                T(0) :
            // lambda == 0
            lambda_par == T(0) ? \
                T(0) :
            // x == Inf (includes case where x == mu == lambda == Inf)
            GCINT::is_posinf(x) ? \
                T(0) :
            // lambda == Inf and x-mu == 0
            GCINT::is_posinf(lambda_par) && x == mu_par ? \
                STLIM<T>::infinity() :
            //
                T(0) );
}

template<typename T>
statslib_constexpr
T
dinvgauss_vals_check(const T x, const T mu_par, const T lambda_par, const bool log_form)
noexcept
{
    return( // notes: (i) statmod allows for lambda < 0  cases, with singularities at x == mu == 0, but we return NaN
            //        (ii) statmod allows for mu < 0 when x < 0 (density equals to zero), but we return NaN
            !invgauss_sanity_check(x,mu_par,lambda_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < T(0) ? \
                log_zero_if<T>(log_form) :
            //
            GCINT::any_inf(x,mu_par,lambda_par) || x == T(0) || lambda_par == T(0) ? \
                log_if(dinvgauss_limit_vals(x,mu_par,lambda_par),log_form) :
            //
            exp_if(dinvgauss_log_compute(x, mu_par, lambda_par), !log_form) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
dinvgauss_type_check(const T1 x, const T2 mu_par, const T3 lambda_par, const bool log_form)
noexcept
{
    return dinvgauss_vals_check(static_cast<TC>(x), static_cast<TC>(mu_par),
                                static_cast<TC>(lambda_par), log_form);
}

}

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
dinvgauss(const T1 x, const T2 mu_par, const T3 lambda_par, const bool log_form)
noexcept
{
    return internal::dinvgauss_type_check(x,mu_par,lambda_par,log_form);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
void
dinvgauss_vec(const eT* __stats_pointer_settings__ vals_in, const T1 mu_par, const T2 lambda_par, const bool log_form, 
                    rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(dinvgauss,vals_in,vals_out,num_elem,mu_par,lambda_par,log_form);
}
#endif

}

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
std::vector<rT>
dinvgauss(const std::vector<eT>& x, const T1 mu_par, const T2 lambda_par, const bool log_form)
{
    STDVEC_DIST_FN(dinvgauss_vec,mu_par,lambda_par,log_form);
}
#endif

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
ArmaMat<rT>
dinvgauss(const ArmaMat<eT>& X, const T1 mu_par, const T2 lambda_par, const bool log_form)
{
    ARMA_DIST_FN(dinvgauss_vec,mu_par,lambda_par,log_form);
}

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
dinvgauss(const ArmaGen<mT,tT>& X, const T1 mu_par, const T2 lambda_par, const bool log_form)
{
    return dinvgauss(X.eval(),mu_par,lambda_par,log_form);
}
#endif

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
dinvgauss(const BlazeMat<eT,To>& X, const T1 mu_par, const T2 lambda_par, const bool log_form)
{
    BLAZE_DIST_FN(dinvgauss,mu_par,lambda_par,log_form);
}
#endif

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
dinvgauss(const EigenMat<eT,iTr,iTc>& X, const T1 mu_par, const T2 lambda_par, const bool log_form)
{
    EIGEN_DIST_FN(dinvgauss_vec,mu_par,lambda_par,log_form);
}
#endif
