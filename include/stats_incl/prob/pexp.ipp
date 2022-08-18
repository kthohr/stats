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
 * cdf of the Exponential distribution
 */

//
// scalar input

namespace internal
{

template<typename T>
statslib_constexpr
T
pexp_compute(const T x, const T rate_par)
{
    return( x <= T(0) ? \
                T(0) :
            // x > 0
            GCINT::is_posinf(rate_par) ? \
                T(1) :
            //
            - stmath::expm1(-rate_par*x) );
}

template<typename T>
statslib_constexpr
T
pexp_vals_check(const T x, const T rate_par, const bool log_form)
noexcept
{
    return( !exp_sanity_check(x,rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            log_if(pexp_compute(x,rate_par), log_form) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
pexp_type_check(const T1 x, const T2 rate_par, const bool log_form)
noexcept
{
    return pexp_vals_check(static_cast<TC>(x),static_cast<TC>(rate_par),log_form);
}

}

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
pexp(const T1 x, const T2 rate_par, const bool log_form)
noexcept
{
    return internal::pexp_type_check(x,rate_par,log_form);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename rT>
statslib_inline
void
pexp_vec(const eT* __stats_pointer_settings__ vals_in, const T1 rate_par, const bool log_form, 
               rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(pexp,vals_in,vals_out,num_elem,rate_par,log_form);
}
#endif

}

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename rT>
statslib_inline
std::vector<rT>
pexp(const std::vector<eT>& x, const T1 rate_par, const bool log_form)
{
    STDVEC_DIST_FN(pexp_vec,rate_par,log_form);
}
#endif

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename rT>
statslib_inline
ArmaMat<rT>
pexp(const ArmaMat<eT>& X, const T1 rate_par, const bool log_form)
{
    ARMA_DIST_FN(pexp_vec,rate_par,log_form);
}

template<typename mT, typename tT, typename T1>
statslib_inline
mT
pexp(const ArmaGen<mT,tT>& X, const T1 rate_par, const bool log_form)
{
    return pexp(X.eval(),rate_par,log_form);
}
#endif

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
pexp(const BlazeMat<eT,To>& X, const T1 rate_par, const bool log_form)
{
    BLAZE_DIST_FN(pexp_vec,rate_par,log_form);
}
#endif

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
pexp(const EigenMat<eT,iTr,iTc>& X, const T1 rate_par, const bool log_form)
{
    EIGEN_DIST_FN(pexp_vec,rate_par,log_form);
}
#endif
