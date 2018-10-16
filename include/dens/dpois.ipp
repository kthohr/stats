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
 * pdf of the Poisson distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dpois_int(const ullint_t x, const T rate_par)
{
    return ( x * stmath::log(rate_par) - rate_par - stmath::log( T(gcem::factorial(x)) ) );
}

template<typename T>
statslib_constexpr
T
dpois_check(const ullint_t x, const T rate_par, const bool log_form)
{
    return ( log_form == true ? dpois_int(x,rate_par) : stmath::exp(dpois_int(x,rate_par)) );
}

template<typename T>
statslib_constexpr
return_t<T>
dpois(const ullint_t x, const T rate_par, const bool log_form)
{
    return dpois_check<return_t<T>>(x,rate_par,log_form);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
dpois_int(const Ta* __stats_pointer_settings__ vals_in, const Tb rate_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = dpois(ullint_t(vals_in[j]),rate_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
dpois(const ArmaMat<Ta>& X, const Tb rate_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    dpois_int<Ta,Tb,Tc>(X.memptr(),rate_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
dpois(const ArmaGen<mT,tT>& X, const Tb rate_par, const bool log_form)
{
    return dpois(X.eval(),rate_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
dpois(const BlazeMat<Ta,To>& X, const Tb rate_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    dpois_int<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
dpois(const EigMat<Ta,iTr,iTc>& X, const Tb rate_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    dpois_int<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
