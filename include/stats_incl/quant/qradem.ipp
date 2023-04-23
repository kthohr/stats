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
 * quantile function of the Rademacher distribution
 */

//
// scalar input

namespace internal
{

template<typename T>
statslib_constexpr
T
qradem_compute(const T p, const T prob_par)
noexcept
{
    return( !radem_sanity_check(prob_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            !prob_val_check(p) ? \
                STLIM<T>::quiet_NaN() :
            //
            p > (T(1) - prob_par) ? \
                llint_t(1) : 
                llint_t(-1) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
qradem_type_check(const T1 p, const T2 prob_par)
noexcept
{
    return qradem_compute(static_cast<TC>(p),static_cast<TC>(prob_par));
}

}

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2> // not llint_t so we can return NaN
qradem(const T1 p, const T2 prob_par)
noexcept
{
    return internal::qradem_type_check(p,prob_par);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename rT>
statslib_inline
void
qradem_vec(const eT* __stats_pointer_settings__ vals_in, const T1 prob_par,
                 rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qradem,vals_in,vals_out,num_elem,prob_par);
}
#endif

}

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename rT>
statslib_inline
std::vector<rT>
qradem(const std::vector<eT>& x, const T1 prob_par)
{
    STDVEC_DIST_FN(qradem_vec,prob_par);
}
#endif

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename rT>
statslib_inline
ArmaMat<rT>
qradem(const ArmaMat<eT>& X, const T1 prob_par)
{
    ARMA_DIST_FN(qradem_vec,prob_par);
}

template<typename mT, typename tT, typename T1>
statslib_inline
mT
qradem(const ArmaGen<mT,tT>& X, const T1 prob_par)
{
    return qradem(X.eval(),prob_par);
}
#endif

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
qradem(const BlazeMat<eT,To>& X, const T1 prob_par)
{
    BLAZE_DIST_FN(qradem_vec,prob_par);
}
#endif

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
qradem(const EigenMat<eT,iTr,iTc>& X, const T1 prob_par)
{
    EIGEN_DIST_FN(qradem_vec,prob_par);
}
#endif
