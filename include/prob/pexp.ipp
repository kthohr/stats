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
 * cdf of the Exponential distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
pexp_compute(const T x, const T rate_par)
{
    return( x < T(0) ? \
            //
                T(0) :
            //
                - stmath::expm1(-rate_par*x) );
}

template<typename T>
statslib_constexpr
T
pexp_vals_check(const T x, const T rate_par, const bool log_form)
noexcept
{
    return( !exp_sanity_check(rate_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            log_if(pexp_compute(x,rate_par), log_form) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
pexp_type_check(const T1 x, const T2 rate_par, const bool log_form)
noexcept
{
    return pexp_vals_check(static_cast<TC>(x),static_cast<TC>(rate_par),log_form);
}

}

/**
 * @brief Distribution function of the Exponential distribution
 *
 * @param x a real-valued input.
 * @param rate_par the rate parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::pexp(1.0,2.0,false); \endcode
 */

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
pexp(const T1 x, const T2 rate_par, const bool log_form)
noexcept
{
    return internal::pexp_type_check(x,rate_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
pexp_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb rate_par, const bool log_form, 
               Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(pexp,vals_in,vals_out,num_elem,rate_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
pexp(const ArmaMat<Ta>& X, const Tb rate_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::pexp_vec<Ta,Tb,Tc>(X.memptr(),rate_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
pexp(const ArmaGen<mT,tT>& X, const Tb rate_par, const bool log_form)
{
    return pexp(X.eval(),rate_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
pexp(const BlazeMat<Ta,To>& X, const Tb rate_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::pexp_vec<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
pexp(const EigMat<Ta,iTr,iTc>& X, const Tb rate_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::pexp_vec<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
