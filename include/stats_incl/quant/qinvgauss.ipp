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
 * quantile function of the univariate inverse Gaussian distribution
 */

//
// scalar input

namespace internal
{

template<typename T>
statslib_constexpr
T
qinvgauss_compute_iter_2(const T dval, const T qn, const T p, const T mu_par, const T lambda_par, const int count) noexcept;

template<typename T>
statslib_constexpr
T
invgauss_mode(const T mu_par, const T mu_div_lambda)
noexcept
{
    return mu_par * ( stmath::sqrt( T(1) + T(9) * mu_div_lambda * mu_div_lambda / T(4) ) - T(3) * mu_div_lambda / T(2) );
}

template<typename T>
statslib_constexpr
T
qinvgauss_compute_iter_1(const T qn, const T p, const T mu_par, const T lambda_par, const int count)
noexcept
{
    return qinvgauss_compute_iter_2(p - pinvgauss(qn, mu_par, lambda_par), qn, p, mu_par, lambda_par, count);
}

template<typename T>
statslib_constexpr
T
qinvgauss_compute_iter_2(const T dval, const T qn, const T p, const T mu_par, const T lambda_par, const int count)
noexcept
{
    return( abs(dval) < STLIM<T>::min() ? \
                qn :
            //
            count < STATS_QINVGAUSS_MAX_ITER ? \
                qinvgauss_compute_iter_1(qn + dval / dinvgauss(qn, mu_par, lambda_par), p, mu_par, lambda_par, count + 1) :
                qn );
}


template<typename T>
statslib_constexpr
T
qinvgauss_compute(const T p, const T mu_par, const T lambda_par)
noexcept
{
    return qinvgauss_compute_iter_1( invgauss_mode(mu_par, mu_par / lambda_par), p, mu_par, lambda_par, 0 );
}

template<typename T>
statslib_constexpr
T
qinvgauss_vals_check(const T p, const T mu_par, const T lambda_par)
noexcept
{
    return( !invgauss_sanity_check(mu_par,lambda_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            !prob_val_check(p) ? \
                STLIM<T>::quiet_NaN() :
            //
            GCINT::is_posinf(lambda_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            mu_par == T(0) ? \
                STLIM<T>::quiet_NaN() :
            //
            lambda_par == T(0) ? \
                p == T(1) ? \
                    STLIM<T>::infinity() :
                    T(0) :
            //
            p == T(1) ? \
                STLIM<T>::infinity() :
            //
            p == T(0) ? \
                T(0) :
            //
            qinvgauss_compute(p,mu_par,lambda_par) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qinvgauss_type_check(const T1 p, const T2 mu_par, const T3 lambda_par)
noexcept
{
    return qinvgauss_vals_check(static_cast<TC>(p),static_cast<TC>(mu_par),static_cast<TC>(lambda_par));
}

}

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qinvgauss(const T1 p, const T2 mu_par, const T3 lambda_par)
noexcept
{
    return internal::qinvgauss_type_check(p,mu_par,lambda_par);
}

//
// vector/matrix input

namespace internal
{

#ifdef STATS_ENABLE_INTERNAL_VEC_FEATURES
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
void
qinvgauss_vec(const eT* __stats_pointer_settings__ vals_in, const T1 mu_par, const T2 lambda_par, 
                    rT* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qinvgauss,vals_in,vals_out,num_elem,mu_par,lambda_par);
}
#endif

}

#ifdef STATS_ENABLE_STDVEC_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
std::vector<rT>
qinvgauss(const std::vector<eT>& x, const T1 mu_par, const T2 lambda_par)
{
    STDVEC_DIST_FN(qinvgauss_vec,mu_par,lambda_par);
}
#endif

#ifdef STATS_ENABLE_ARMA_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT>
statslib_inline
ArmaMat<rT>
qinvgauss(const ArmaMat<eT>& X, const T1 mu_par, const T2 lambda_par)
{
    ARMA_DIST_FN(qinvgauss_vec,mu_par,lambda_par);
}

template<typename mT, typename tT, typename T1, typename T2>
statslib_inline
mT
qinvgauss(const ArmaGen<mT,tT>& X, const T1 mu_par, const T2 lambda_par)
{
    return qinvgauss(X.eval(),mu_par,lambda_par);
}
#endif

#ifdef STATS_ENABLE_BLAZE_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, bool To>
statslib_inline
BlazeMat<rT,To>
qinvgauss(const BlazeMat<eT,To>& X, const T1 mu_par, const T2 lambda_par)
{
    BLAZE_DIST_FN(qinvgauss_vec,mu_par,lambda_par);
}
#endif

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
template<typename eT, typename T1, typename T2, typename rT, int iTr, int iTc>
statslib_inline
EigenMat<rT,iTr,iTc>
qinvgauss(const EigenMat<eT,iTr,iTc>& X, const T1 mu_par, const T2 lambda_par)
{
    EIGEN_DIST_FN(qinvgauss_vec,mu_par,lambda_par);
}
#endif
