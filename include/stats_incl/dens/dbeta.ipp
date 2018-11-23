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
 * pdf of the Beta distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
dbeta_log_compute(const T x, const T a_par, const T b_par)
noexcept
{
    return( - (stmath::lgamma(a_par) + stmath::lgamma(b_par) - stmath::lgamma(a_par+b_par)) \
            + (a_par - T(1))*stmath::log(x) + (b_par - T(1))*stmath::log(T(1) - x) );
}

template<typename T>
statslib_constexpr
T
dbeta_limit_vals(const T x, const T a_par, const T b_par)
noexcept
{
    return( a_par == T(0) && b_par == T(0) ? \
                x == T(0) || x == T(1) ? \
                    STLIM<T>::infinity() :
                    T(0) : 
            //
            a_par == T(0) || gcem::internal::is_posinf(b_par) ? \
                x == T(0) ? \
                    STLIM<T>::infinity() :
                    T(0) :
            //
            b_par == T(0) || gcem::internal::is_posinf(a_par) ? \
                x == T(1) ? \
                    STLIM<T>::infinity() :
                    T(0) :
            //
            x == T(0.5) ? \
                STLIM<T>::infinity() : 
                T(0) );
}

template<typename T>
statslib_constexpr
T
dbeta_vals_check(const T x, const T a_par, const T b_par, const bool log_form)
noexcept
{
    return( !beta_sanity_check(a_par,b_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < T(0) || x > T(1) ? \
                log_if(T(0),log_form) :
            //
            (a_par == T(0) || b_par == T(0) || gcem::internal::any_posinf(a_par,b_par)) ? \
                log_if(dbeta_limit_vals(x,a_par,b_par),log_form) :
            //
            x == T(0) ? \
                a_par < T(1) ? \
                    STLIM<T>::infinity() :
                a_par > T(1) ? \
                    log_if(T(0),log_form) :
                    log_if(b_par,log_form) :
            x == T(1) ? \
                b_par < T(1) ? \
                    STLIM<T>::infinity() :
                b_par > T(1) ? \
                    log_if(T(0),log_form) :
                    log_if(a_par,log_form) :
            //
            exp_if(dbeta_log_compute(x,a_par,b_par), !log_form) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
dbeta_type_check(const T1 x, const T2 a_par, const T3 b_par, const bool log_form)
noexcept
{
    return dbeta_vals_check(static_cast<TC>(x),static_cast<TC>(a_par),
                            static_cast<TC>(b_par),log_form);
}

}

/**
 * @brief Density function of the Beta distribution
 *
 * @param x a real-valued input.
 * @param a_par a shape parameter, a real-valued input.
 * @param b_par a shape parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dbeta(0.5,3.0,2.0,false); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
dbeta(const T1 x, const T2 a_par, const T3 b_par, const bool log_form)
noexcept
{
    return internal::dbeta_type_check(x,a_par,b_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dbeta_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb a_par, const Tb b_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(dbeta,vals_in,vals_out,num_elem,a_par,b_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dbeta(const ArmaMat<Ta>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::dbeta_vec<Ta,Tb,Tc>(X.memptr(),a_par,b_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dbeta(const ArmaGen<mT,tT>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    return dbeta(X.eval(),a_par,b_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dbeta(const BlazeMat<Ta,To>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::dbeta_vec<Ta,Tb,Tc>(X.data(),a_par,b_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dbeta(const EigMat<Ta,iTr,iTc>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::dbeta_vec<Ta,Tb,Tc>(X.data(),a_par,b_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
