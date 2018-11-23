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
 * quantile function of the Poisson distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qpois_compute_right_search(const T p, const T rate_par, const T value, const llint_t count)
noexcept
{
    return( value <= p ? \
                qpois_compute_right_search(p,rate_par, ppois(count,rate_par,false), count + llint_t(1)) : 
            // else
            count > llint_t(0) ? 
                static_cast<T>(count - llint_t(1)) : 
                T(0) );
}

template<typename T>
statslib_constexpr
T
qpois_compute_search_begin(const T p, const T rate_par, const llint_t count)
noexcept
{
    return qpois_compute_right_search(p,rate_par, ppois(count,rate_par,false), count);
}

template<typename T>
statslib_constexpr
llint_t
qpois_trunc_normal_approx(const T p, const T rate_par)
noexcept
{
    return static_cast<llint_t>( stmath::max( T(0), qnorm(p,rate_par,stmath::sqrt(rate_par)) - T(3) ) );
}

template<typename T>
statslib_constexpr
T
qpois_vals_check(const T p, const T rate_par)
noexcept
{
    return( !pois_sanity_check(rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p < T(0) || p > T(1) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                T(0) :
            STLIM<T>::epsilon() > rate_par ? \
                T(0) :
            p == T(1) ? \
                STLIM<T>::infinity() :
            // rate < 11
            rate_par < T(11) ? \
                qpois_compute_right_search(p,rate_par,T(0),llint_t(0)) :
            // else use a normal approximation
                qpois_compute_search_begin(p,rate_par,qpois_trunc_normal_approx(p,rate_par)) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
qpois_type_check(const T1 p, const T2 rate_par)
noexcept
{
    return qpois_vals_check(static_cast<TC>(p),static_cast<TC>(rate_par));
}

}

/**
 * @brief Quantile function of the Poisson distribution
 *
 * @param p a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qpois(0.6,10.0); \endcode
 */

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
qpois(const T1 p, const T2 rate_par)
noexcept
{
    return internal::qpois_type_check(p,rate_par);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qpois_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb rate_par,
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qpois,vals_in,vals_out,num_elem,rate_par);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qpois(const ArmaMat<Ta>& X, const Tb rate_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::qpois_vec<Ta,Tb,Tc>(X.memptr(),rate_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qpois(const ArmaGen<mT,tT>& X, const Tb rate_par)
{
    return qpois(X.eval(),rate_par);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qpois(const BlazeMat<Ta,To>& X, const Tb rate_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::qpois_vec<Ta,Tb,Tc>(X.data(),rate_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qpois(const EigMat<Ta,iTr,iTc>& X, const Tb rate_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::qpois_vec<Ta,Tb,Tc>(X.data(),rate_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
