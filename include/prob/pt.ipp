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
 * cdf of the univariate t distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
pt_compute_main_2(const T z, const T r_par)
{
    return( pbeta(T(1)/z, r_par/T(2), T(0.5)) / T(2) );
}

template<typename T>
statslib_constexpr
T
pt_compute_main_1(const T z, const T r_par)
{
    return( T(0.5) - pbeta(z/(r_par+z), T(0.5), r_par/T(2)) / T(2) );
}

template<typename T>
statslib_constexpr
T
pt_compute_main(const T x, const T r_par)
{
    return( r_par > x*x ? \
                (x > T(0) ? T(1) - pt_compute_main_1(x*x,r_par) : pt_compute_main_1(x*x,r_par)) : 
                (x > T(0) ? T(1) - pt_compute_main_2(T(1) + (x/r_par)*x,r_par) : 
                            pt_compute_main_2(T(1) + (x/r_par)*x,r_par)) );
}

template<typename T>
statslib_constexpr
T
pt_compute(const T x, const T r_par)
{
    return( r_par == T(1) ? \
                pcauchy_compute(x) :
            r_par == T(2) ? \
                T(0.5) + x / (T(2) * stmath::sqrt(x*x + T(2)) ) :
            //
            pt_compute_main(x,T(r_par)) );
}

template<typename T>
statslib_constexpr
T
pt_vals_check(const T x, const T dof_par, const bool log_form)
{
    return( !t_sanity_check(dof_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            log_if(pt_compute(x,dof_par), log_form) );
}

template<typename T1, typename T2, typename TC = common_return_t<T1,T2>>
statslib_constexpr
TC
pt_type_check(const T1 x, const T2 dof_par, const bool log_form)
noexcept
{
    return pt_vals_check(static_cast<TC>(x),static_cast<TC>(dof_par),log_form);
}

}

/**
 * @brief Distribution function of the t-distribution
 *
 * @param x a real-valued input.
 * @param dof_par the degrees of freedom parameter, a real-valued input.
 * @param log_form return the log-probability or the true form.
 *
 * @return the cumulative distribution function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::pt(0.37,11,false); \endcode
 */

template<typename T1, typename T2>
statslib_constexpr
common_return_t<T1,T2>
pt(const T1 x, const T2 dof_par, const bool log_form)
noexcept
{
    return internal::pt_type_check(x,dof_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
pt_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb dof_par, const bool log_form, 
             Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(pt,vals_in,vals_out,num_elem,dof_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
pt(const ArmaMat<Ta>& X, const Tb dof_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::pt_vec<Ta,Tb,Tc>(X.memptr(),dof_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
pt(const ArmaGen<mT,tT>& X, const Tb dof_par, const bool log_form)
{
    return pt(X.eval(),dof_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
pt(const BlazeMat<Ta,To>& X, const Tb dof_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::pt_vec<Ta,Tb,Tc>(X.data(),dof_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
pt(const EigMat<Ta,iTr,iTc>& X, const Tb dof_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::pt_vec<Ta,Tb,Tc>(X.data(),dof_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
