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
 * cdf of the Poisson distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
ppois_compute_recur(const llint_t x, const T rate_par, const llint_t r_count)
{   // note: integer overflow can happen when calculating factorial values
    return( x == llint_t(0) ? \
                T(1) :
            x == llint_t(1) ? \
                T(1) + rate_par :
            //
            r_count == llint_t(0) ? \
                T(1) + ppois_compute_recur(x,rate_par,r_count+1) :
            //
            r_count < x ? \
                    stmath::pow(rate_par,r_count) / gcem::factorial(r_count) + ppois_compute_recur(x,rate_par,r_count+1) :  
                    stmath::pow(rate_par,r_count) / gcem::factorial(r_count) );
}

template<typename T>
statslib_constexpr
T
ppois_compute(const llint_t x, const T rate_par)
{
    return( rate_par > T(10) ? \
            // switch to incomplete gamma function
                T(1) - gcem::incomplete_gamma(T(x+1),rate_par) :
            // else
                stmath::exp(-rate_par) * ppois_compute_recur(x,rate_par,0U) );
}

template<typename T>
statslib_constexpr
T
ppois_vals_check(const llint_t x, const T rate_par, const bool log_form)
{
    return( !pois_sanity_check(rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < llint_t(0) ? \
                log_if(0,log_form) :
            //
            log_if(ppois_compute(x,rate_par), log_form) );
}

}

/**
 * @brief Distribution function of the Poisson distribution
 *
 * @param x a non-negative integral-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::ppois(8.0,10.0,false); \endcode
 */

template<typename T>
statslib_constexpr
return_t<T>
ppois(const ullint_t x, const T rate_par, const bool log_form)
noexcept
{
    return internal::ppois_vals_check(x,static_cast<return_t<T>>(rate_par),log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
ppois_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb rate_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(ppois,vals_in,vals_out,num_elem,rate_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
ppois(const ArmaMat<Ta>& X, const Tb rate_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::ppois_vec<Ta,Tb,Tc>(X.memptr(),rate_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
ppois(const ArmaGen<mT,tT>& X, const Tb rate_par, const bool log_form)
{
    return ppois(X.eval(),rate_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
ppois(const BlazeMat<Ta,To>& X, const Tb rate_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::ppois_vec<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
ppois(const EigMat<Ta,iTr,iTc>& X, const Tb rate_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::ppois_vec<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
