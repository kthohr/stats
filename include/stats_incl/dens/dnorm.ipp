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
 * pdf of the univariate normal distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
dnorm_log_compute(const T z, const T sigma_par)
noexcept
{
    return( - T(0.5)*T(GCEM_LOG_2PI) - stmath::log(sigma_par) - z*z/T(2) );
}

template<typename T>
statslib_constexpr
T
dnorm_vals_check(const T x, const T mu_par, const T sigma_par, const bool log_form)
noexcept
{
    return( !norm_sanity_check(mu_par,sigma_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            exp_if(dnorm_log_compute((x-mu_par)/sigma_par,sigma_par), !log_form) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
dnorm_type_check(const T1 x, const T2 mu_par, const T3 sigma_par, const bool log_form)
noexcept
{
    return dnorm_vals_check(static_cast<TC>(x),static_cast<TC>(mu_par),
                            static_cast<TC>(sigma_par),log_form);
}

}

/**
 * @brief Density function of the Normal distribution
 *
 * @param x a real-valued input.
 * @param mu_par the mean parameter, a real-valued input.
 * @param sigma_par the standard deviation parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dnorm(0.5,1.0,2.0,false); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
dnorm(const T1 x, const T2 mu_par, const T3 sigma_par, const bool log_form)
noexcept
{
    return internal::dnorm_type_check(x,mu_par,sigma_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dnorm_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb mu_par, const Tb sigma_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(dnorm,vals_in,vals_out,num_elem,mu_par,sigma_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dnorm(const ArmaMat<Ta>& X, const Tb mu_par, const Tb sigma_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::dnorm_vec<Ta,Tb,Tc>(X.memptr(),mu_par,sigma_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dnorm(const ArmaGen<mT,tT>& X, const Tb mu_par, const Tb sigma_par, const bool log_form)
{
    return dnorm(X.eval(),mu_par,sigma_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dnorm(const BlazeMat<Ta,To>& X, const Tb mu_par, const Tb sigma_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::dnorm_vec<Ta,Tb,Tc>(X.data(),mu_par,sigma_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dnorm(const EigMat<Ta,iTr,iTc>& X, const Tb mu_par, const Tb sigma_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::dnorm_vec<Ta,Tb,Tc>(X.data(),mu_par,sigma_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
