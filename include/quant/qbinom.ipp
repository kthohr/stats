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
 * quantile function of the Binomial distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qbinom_recur(const T p, const llint_t n_trials_par, const T prob_par, const T value, const llint_t count)
noexcept
{
    return( value <= p ? \
                qbinom_recur(p,n_trials_par,prob_par, pbinom(count,n_trials_par,prob_par), count + 1) :
                count - llint_t(1) );
}

template<typename T>
statslib_constexpr
T
qbinom_vals_check(const T p, const llint_t n_trials_par, const T prob_par)
noexcept
{
    return( !binom_sanity_check(n_trials_par,prob_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p < T(0) || p > T(1) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                T(0) :
            p == T(1) ? \
                static_cast<T>(n_trials_par) :
            //
            qbinom_recur(p,n_trials_par,prob_par,T(0),llint_t(0)) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
qbinom_type_check(const T1 p, const llint_t n_trials_par, const T2 prob_par)
noexcept
{
    return qbinom_vals_check(static_cast<TC>(p),n_trials_par,static_cast<TC>(prob_par));
}

}

/**
 * @brief Quantile function of the Binomial distribution
 *
 * @param p a real-valued input.
 * @param n_trials_par the number of trials, a positive integral-valued input.
 * @param prob_par the probability parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qbinom(0.4,4,0.4); \endcode
 */

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
qbinom(const T1 p, const llint_t n_trials_par, const T2 prob_par)
noexcept
{
    return internal::qbinom_type_check(p,n_trials_par,prob_par);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qbinom_vec(const Ta* __stats_pointer_settings__ vals_in, const llint_t n_trials_par, const Tb prob_par, 
                 Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qbinom,vals_in,vals_out,num_elem,n_trials_par,prob_par);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qbinom(const ArmaMat<Ta>& X, const llint_t n_trials_par, const Tb prob_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::qbinom_vec<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qbinom(const ArmaGen<mT,tT>& X, const llint_t n_trials_par, const Tb prob_par)
{
    return qbinom(X.eval(),n_trials_par,prob_par);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qbinom(const BlazeMat<Ta,To>& X, const llint_t n_trials_par, const Tb prob_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::qbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qbinom(const EigMat<Ta,iTr,iTc>& X, const llint_t n_trials_par, const Tb prob_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::qbinom_vec<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
