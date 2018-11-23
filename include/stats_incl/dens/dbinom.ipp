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
 * pdf of the Binomial distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
dbinom_log_compute(const llint_t x, const llint_t n_trials_par, const T prob_par)
noexcept
{
    return( x == llint_t(0) ? \
                    n_trials_par * stmath::log(T(1.0) - prob_par) :
            //
            x == n_trials_par ? \
                x * stmath::log(prob_par) :
            //
            gcem::log_binomial_coef(n_trials_par,x) + x*stmath::log(prob_par) \
                + (n_trials_par - x)*stmath::log(T(1) - prob_par) );
}

template<typename T>
statslib_constexpr
T
dbinom_limit_vals(const llint_t x, const llint_t n_trials_par, const T prob_par)
noexcept
{
    return( x == llint_t(0) ? \
                T(1) :
                T(0) );
}

template<typename T>
statslib_constexpr
T
dbinom_vals_check(const llint_t x, const llint_t n_trials_par, const T prob_par, const bool log_form)
noexcept
{
    return( !binom_sanity_check(n_trials_par,prob_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < llint_t(0) || x > n_trials_par ? \
                log_if(T(0),log_form) :
            //
            n_trials_par == llint_t(0) ? \
                log_if(dbinom_limit_vals(x,n_trials_par,prob_par),log_form) :
            //
            n_trials_par == llint_t(1) ? \
                dbern(x,prob_par,log_form) :
            //
            exp_if(dbinom_log_compute(x,n_trials_par,prob_par), !log_form) );
}

}

/**
 * @brief Density function of the Binomial distribution
 *
 * @param x a real-valued input.
 * @param n_trials_par the number of trials, a positive integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dbinom(2,4,0.4,false); \endcode
 */

template<typename T>
statslib_constexpr
T
dbinom(const llint_t x, const llint_t n_trials_par, const T prob_par, const bool log_form)
noexcept
{
    return internal::dbinom_vals_check(x,n_trials_par,prob_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dbinom_vec(const Ta* __stats_pointer_settings__ vals_in, const llint_t n_trials_par, const Tb prob_par, const bool log_form, 
                 Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(dbinom,vals_in,vals_out,num_elem,n_trials_par,prob_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dbinom(const ArmaMat<Ta>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::dbinom_vec<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dbinom(const ArmaGen<mT,tT>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    return dbinom(X.eval(),n_trials_par,prob_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dbinom(const BlazeMat<Ta,To>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::dbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dbinom(const EigMat<Ta,iTr,iTc>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::dbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
