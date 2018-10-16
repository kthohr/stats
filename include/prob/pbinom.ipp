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
 * cdf of the Binomial distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pbinom_int(const ullint_t x, const ullint_t n_trials_par, const T prob_par, const ullint_t count)
{
    return ( count == x ? dbinom(count,n_trials_par,prob_par,false) : 
                          dbinom(count,n_trials_par,prob_par,false) + pbinom_int(x,n_trials_par,prob_par,count+1) );
}

template<typename T>
statslib_constexpr
T
pbinom(const ullint_t x, const ullint_t n_trials_par, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(pbinom_int(x,n_trials_par,prob_par,0U)) :
                                pbinom_int(x,n_trials_par,prob_par,0U) );
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
pbinom_int(const Ta* __stats_pointer_settings__ vals_in, const ullint_t n_trials_par, const Tb prob_par, const bool log_form, 
                 Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = pbinom(static_cast<ullint_t>(vals_in[j]),n_trials_par,prob_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
pbinom(const ArmaMat<Ta>& X, const ullint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    pbinom_int<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
pbinom(const ArmaGen<mT,tT>& X, const ullint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    return pbinom(X.eval(),n_trials_par,prob_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
pbinom(const BlazeMat<Ta,To>& X, const ullint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    pbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
pbinom(const EigMat<Ta,iTr,iTc>& X, const ullint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    pbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
