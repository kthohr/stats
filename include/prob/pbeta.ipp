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
 * cdf of the Beta distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pbeta_int(const T x, const T a_par, const T b_par)
{
    return gcem::incomplete_beta(a_par,b_par,x);
}

template<typename T>
statslib_constexpr
T
pbeta_check(const T x, const T a_par, const T b_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(pbeta_int(x,a_par,b_par)) :
                                pbeta_int(x,a_par,b_par) );
}

template<typename Ta, typename Tb>
statslib_constexpr
return_t<Ta>
pbeta(const Ta x, const Tb a_par, const Tb b_par, const bool log_form)
{
    return pbeta_check<return_t<Ta>>(x,a_par,b_par,log_form);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
pbeta_int(const Ta* __stats_pointer_settings__ vals_in, const Tb a_par, const Tb b_par, const bool log_form, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = pbeta(vals_in[j],a_par,b_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
pbeta(const ArmaMat<Ta>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    pbeta_int<Ta,Tb,Tc>(X.memptr(),a_par,b_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
pbeta(const ArmaGen<mT,tT>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    return pbeta(X.eval(),a_par,b_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
pbeta(const BlazeMat<Ta,To>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    pbeta_int<Ta,Tb,Tc>(X.data(),a_par,b_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
pbeta(const EigMat<Ta,iTr,iTc>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    pbeta_int<Ta,Tb,Tc>(X.data(),a_par,b_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
