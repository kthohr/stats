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
 * quantile function of the F-distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qf_compute_adj(const T I_inv_val, const T ab_ratio)
noexcept
{
    return( I_inv_val / (ab_ratio*(T(1) - I_inv_val)) );
}

template<typename T>
statslib_constexpr
T
qf_compute(const T p, const T a_par, const T b_par)
noexcept
{
    return qf_compute_adj(gcem::incomplete_beta_inv(a_par,b_par,p),a_par/b_par);
}

template<typename T>
statslib_constexpr
T
qf_vals_check(const T p, const T df1_par, const T df2_par)
noexcept
{
    return( !f_sanity_check(df1_par,df2_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p < T(0) || p > T(1) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                T(0) :
            p == T(1) ? \
                STLIM<T>::infinity() :
            //
            qf_compute(p,df1_par/T(2),df2_par/T(2)) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qf_type_check(const T1 x, const T2 df1_par, const T3 df2_par)
noexcept
{
    return qf_vals_check(static_cast<TC>(x),static_cast<TC>(df1_par),static_cast<TC>(df2_par));
}

}

/**
 * @brief Quantile function of the F-distribution
 *
 * @param p a real-valued input.
 * @param df1_par a degrees of freedom parameter, a real-valued input.
 * @param df2_par a degrees of freedom parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qf(0.5,10.0,12.0); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qf(const T1 p, const T2 df1_par, const T3 df2_par)
noexcept
{
    return internal::qf_type_check(p,df1_par,df2_par);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qf_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb df1_par, const Tb df2_par, 
             Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qexp,vals_in,vals_out,num_elem,df1_par,df2_par);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qf(const ArmaMat<Ta>& X, const Tb df1_par, const Tb df2_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::qf_vec<Ta,Tb,Tc>(X.memptr(),df1_par,df2_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qf(const ArmaGen<mT,tT>& X, const Tb df1_par, const Tb df2_par)
{
    return qf(X.eval(),df1_par,df2_par);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qf(const BlazeMat<Ta,To>& X, const Tb df1_par, const Tb df2_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::qf_vec<Ta,Tb,Tc>(X.data(),df1_par,df2_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qf(const EigMat<Ta,iTr,iTc>& X, const Tb df1_par, const Tb df2_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::qf_vec<Ta,Tb,Tc>(X.data(),df1_par,df2_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
