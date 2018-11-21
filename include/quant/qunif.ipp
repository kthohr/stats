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
 * quantile function of the uniform distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
qunif_compute(const T p, const T a_par, const T b_par)
noexcept
{
    return ( a_par + p*(b_par-a_par) );
}

template<typename T>
statslib_constexpr
T
qunif_vals_check(const T p, const T a_par, const T b_par)
noexcept
{
    return( !unif_sanity_check(a_par,b_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            p < T(0) || p > T(1) ? \
                STLIM<T>::quiet_NaN() :
            //
            p == T(0) ? \
                a_par :
            p == T(1) ? \
                b_par :
            //
            qunif_compute(p,a_par,b_par) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
qunif_type_check(const T1 p, const T2 a_par, const T3 b_par)
noexcept
{
    return qunif_vals_check(static_cast<TC>(p),static_cast<TC>(a_par),static_cast<TC>(b_par));
}

}

/**
 * @brief Quantile function of the Uniform distribution
 *
 * @param p a real-valued input.
 * @param a_par the lower bound parameter, a real-valued input.
 * @param b_par the upper bound parameter, a real-valued input.
 *
 * @return the quantile function evaluated at \c p.
 * 
 * Example:
 * \code{.cpp} stats::qunif(0.5,-1.0,2.0); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
qunif(const T1 p, const T2 a_par, const T3 b_par)
noexcept
{
    return internal::qunif_type_check(p,a_par,b_par);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qunif_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb a_par, const Tb b_par, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(qunif,vals_in,vals_out,num_elem,a_par,b_par);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qunif(const ArmaMat<Ta>& X, const Tb a_par, const Tb b_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::qunif_vec<Ta,Tb,Tc>(X.memptr(),a_par,b_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qunif(const ArmaGen<mT,tT>& X, const Tb a_par, const Tb b_par)
{
    return qunif(X.eval(),a_par,b_par);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qunif(const BlazeMat<Ta,To>& X, const Tb a_par, const Tb b_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::qunif_vec<Ta,Tb,Tc>(X.data(),a_par,b_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qunif(const EigMat<Ta,iTr,iTc>& X, const Tb a_par, const Tb b_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::qunif_vec<Ta,Tb,Tc>(X.data(),a_par,b_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
