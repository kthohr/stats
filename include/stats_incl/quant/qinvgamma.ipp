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
 * quantile function of the inverse-gamma distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qinvgamma_compute(const T p, const T shape_par, const T rate_par)
noexcept
{
    return( rate_par / gcem::incomplete_gamma_inv(shape_par,T(1)-p) );
}

template<typename T>
statslib_constexpr
T
qinvgamma_vals_check(const T p, const T shape_par, const T rate_par)
noexcept
{
    return( !invgamma_sanity_check(shape_par,rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p < T(0) || p > T(1) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                T(0) :
            p == T(1) ? \
                STLIM<T>::infinity() :
            //
            qinvgamma_compute(p,shape_par,rate_par) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qinvgamma_type_check(const T1 x, const T2 shape_par, const T3 rate_par)
noexcept
{
    return qinvgamma_vals_check(static_cast<TC>(x),static_cast<TC>(shape_par),static_cast<TC>(rate_par));
}

}

/**
 * @brief Quantile function of the Inverse-Gamma distribution
 *
 * @param p a real-valued input.
 * @param shape_par the shape parameter, a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 *
 * Example:
 * \code{.cpp} stats::qinvgamma(0.5,2,1); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qinvgamma(const T1 p, const T2 shape_par, const T3 rate_par)
noexcept
{
    return internal::qinvgamma_type_check(p,shape_par,rate_par);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qinvgamma_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb shape_par, const Tb rate_par, 
                    Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qinvgamma,vals_in,vals_out,num_elem,shape_par,rate_par);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qinvgamma(const ArmaMat<Ta>& X, const Tb shape_par, const Tb rate_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::qinvgamma_vec<Ta,Tb,Tc>(X.memptr(),shape_par,rate_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qinvgamma(const ArmaGen<mT,tT>& X, const Tb shape_par, const Tb rate_par)
{
    return qinvgamma(X.eval(),shape_par,rate_par);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qinvgamma(const BlazeMat<Ta,To>& X, const Tb shape_par, const Tb rate_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::qinvgamma_vec<Ta,Tb,Tc>(X.data(),shape_par,rate_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qinvgamma(const EigMat<Ta,iTr,iTc>& X, const Tb shape_par, const Tb rate_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::qinvgamma_vec<Ta,Tb,Tc>(X.data(),shape_par,rate_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
