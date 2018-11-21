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
 * pdf of the Bernoulli distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
dbern_compute(const llint_t x, const T prob_par)
noexcept
{
    return( x == llint_t(1) ? \
                prob_par :
            x == llint_t(0) ? \
                T(1) - prob_par :
            //
                T(0) );
}

template<typename T>
statslib_constexpr
T
dbern_vals_check(const llint_t x, const T prob_par, const bool log_form)
noexcept
{
    return( !bern_sanity_check(prob_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            log_if(dbern_compute(x,prob_par), log_form) );
}

}

/**
 * @brief Density function of the Bernoulli distribution
 *
 * @param x a value equal to 0 or 1.
 * @param prob_par the probability parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dbern(1,0.6,false); \endcode
 */

template<typename T>
statslib_constexpr
T
dbern(const llint_t x, const T prob_par, const bool log_form)
noexcept
{
    return internal::dbern_vals_check(x,prob_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dbern_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb prob_par, const bool log_form,
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    // vals_out[j] = dbern(static_cast<int>(vals_in[j]),prob_par,log_form);
    EVAL_DIST_FN_VEC(dbern,vals_in,vals_out,num_elem,prob_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dbern(const ArmaMat<Ta>& X, const Tb prob_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::dbern_vec<Ta,Tb,Tc>(X.memptr(),prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dbern(const ArmaGen<mT,tT>& X, const Tb prob_par, const bool log_form)
{
    return dbern(X.eval(),prob_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dbern(const BlazeMat<Ta,To>& X, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::dbern_vec<Ta,Tb,Tc>(X.data(),prob_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dbern(const EigMat<Ta,iTr,iTc>& X, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::dbern_vec<Ta,Tb,Tc>(X.data(),prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
