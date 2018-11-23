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
 * cdf of the Binomial distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
pbinom_compute(const llint_t x, const llint_t n_trials_par, const T prob_par, const llint_t count)
noexcept
{
    return( count == x ? \
                dbinom(count,n_trials_par,prob_par,false) : 
                dbinom(count,n_trials_par,prob_par,false) + pbinom_compute(x,n_trials_par,prob_par,count+1) );
}

template<typename T>
statslib_constexpr
T
pbinom_vals_check(const llint_t x, const llint_t n_trials_par, const T prob_par, const bool log_form)
noexcept
{
    return( !binom_sanity_check(n_trials_par,prob_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < llint_t(0) ? \
                log_if(T(0),log_form) :
            x >= n_trials_par ? \
                log_if(T(1),log_form) : // includes pbinom(0,0,.) case
            //
            n_trials_par == llint_t(1) ? \
                pbern(x,prob_par,log_form) :
            //
            log_if(pbinom_compute(x,n_trials_par,prob_par,llint_t(0)), log_form) );
}

}

/**
 * @brief Distribution function of the Binomial distribution
 *
 * @param x a real-valued input.
 * @param n_trials_par the number of trials, a positive integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::pbinom(2,4,0.4,false); \endcode
 */

template<typename T>
statslib_constexpr
T
pbinom(const llint_t x, const llint_t n_trials_par, const T prob_par, const bool log_form)
noexcept
{
    return internal::pbinom_vals_check(x,n_trials_par,prob_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
pbinom_vec(const Ta* __stats_pointer_settings__ vals_in, const llint_t n_trials_par, const Tb prob_par, const bool log_form, 
                 Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(pbinom,vals_in,vals_out,num_elem,n_trials_par,prob_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
pbinom(const ArmaMat<Ta>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::pbinom_vec<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
pbinom(const ArmaGen<mT,tT>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    return pbinom(X.eval(),n_trials_par,prob_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
pbinom(const BlazeMat<Ta,To>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::pbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
pbinom(const EigMat<Ta,iTr,iTc>& X, const llint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::pbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
