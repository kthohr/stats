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
 * pdf of the Weibull distribution
 */

//
// single input

namespace internal
{

template<typename T>
statslib_constexpr
T
dweibull_log_compute(const T x, const T shape_par, const T scale_par)
noexcept
{
    return( stmath::log(shape_par/scale_par) + (shape_par-1)*stmath::log(x) - stmath::pow(x,shape_par) );
}

template<typename T>
statslib_constexpr
T
dweibull_vals_check(const T x, const T shape_par, const T scale_par, const bool log_form)
noexcept
{
    return( !weibull_sanity_check(shape_par,scale_par) ? \
                STLIM<T>::quiet_NaN() :
            //
            x < T(0) ? \
                log_if(T(0),log_form) :
            //
            exp_if(dweibull_log_compute(x/scale_par,shape_par,scale_par), !log_form) );
}

template<typename T1, typename T2, typename T3, typename TC = common_return_t<T1,T2,T3>>
statslib_constexpr
TC
dweibull_type_check(const T1 x, const T2 shape_par, const T3 scale_par, const bool log_form)
noexcept
{
    return dweibull_vals_check(static_cast<TC>(x),static_cast<TC>(shape_par),
                               static_cast<TC>(scale_par),log_form);
}

}

/**
 * @brief Density function of the Weibull distribution
 *
 * @param x a real-valued input.
 * @param shape_par the shape parameter, a real-valued input.
 * @param scale_par the scale parameter, a real-valued input.
 * @param log_form return the log-density or the true form.
 *
 * @return the density function evaluated at \c x.
 * 
 * Example:
 * \code{.cpp} stats::dweibull(1.0,2.0,3.0,false); \endcode
 */

template<typename T1, typename T2, typename T3>
statslib_constexpr
common_return_t<T1,T2,T3>
dweibull(const T1 x, const T2 shape_par, const T3 scale_par, const bool log_form)
noexcept
{
    return internal::dweibull_type_check(x,shape_par,scale_par,log_form);
}

//
// matrix/vector input

namespace internal
{

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dweibull_vec(const Ta* __stats_pointer_settings__ vals_in, const Tb shape_par, const Tb scale_par, const bool log_form, 
                   Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
    EVAL_DIST_FN_VEC(dweibull,vals_in,vals_out,num_elem,shape_par,scale_par,log_form);
}

}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dweibull(const ArmaMat<Ta>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    internal::dweibull_vec<Ta,Tb,Tc>(X.memptr(),shape_par,scale_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dweibull(const ArmaGen<mT,tT>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    return dweibull(X.eval(),shape_par,scale_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dweibull(const BlazeMat<Ta,To>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    internal::dweibull_vec<Ta,Tb,Tc>(X.data(),shape_par,scale_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dweibull(const EigMat<Ta,iTr,iTc>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    internal::dweibull_vec<Ta,Tb,Tc>(X.data(),shape_par,scale_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
