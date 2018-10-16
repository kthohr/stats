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
 * cdf of the Poisson distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
ppois_int_recur(const ullint_t x, const T rate_par, const size_t r_count)
{   // note: integer overflow can happen when calculating factorial values
    return ( x == 0U ? T(1) :
             x == 1U ? T(1) + rate_par :
             //
             r_count == 0 ? T(1) + ppois_int_recur(x,rate_par,r_count+1) :
             r_count < x ? stmath::pow(rate_par,r_count) / gcem::factorial(r_count) + ppois_int_recur(x,rate_par,r_count+1) :  
                           stmath::pow(rate_par,r_count) / gcem::factorial(r_count) );
}

template<typename T>
statslib_constexpr
T
ppois_int(const int x, const T rate_par)
{
    return( rate_par > T(10) ? \
            // switch to incomplete gamma function
                T(1) - gcem::incomplete_gamma(T(x+1),rate_par) :
            // else
                stmath::exp(-rate_par) * ppois_int_recur(x,rate_par,0U) );
}

template<typename T>
statslib_constexpr
T
ppois_check(const int x, const T rate_par, const bool log_form)
{
    return ( log_form == false ? ppois_int(x,rate_par) : 
                                 stmath::log(ppois_int(x,rate_par)) );
}

template<typename T>
statslib_constexpr
return_t<T>
ppois(const ullint_t x, const T rate_par, const bool log_form)
{
    return ppois_check<return_t<T>>(x,rate_par,log_form);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
ppois_int(const Ta* __stats_pointer_settings__ vals_in, const Tb rate_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = ppois(vals_in[j],rate_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
ppois(const ArmaMat<Ta>& X, const Tb rate_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    ppois_int<Ta,Tb,Tc>(X.memptr(),rate_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
ppois(const ArmaGen<mT,tT>& X, const Tb rate_par, const bool log_form)
{
    return ppois(X.eval(),rate_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
ppois(const BlazeMat<Ta,To>& X, const Tb rate_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    ppois_int<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
ppois(const EigMat<Ta,iTr,iTc>& X, const Tb rate_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    ppois_int<Ta,Tb,Tc>(X.data(),rate_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
