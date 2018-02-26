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
 * pdf of the Binomial distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dbinom_int(const int x, const uint_t n_trials_par, const T prob_par)
{
    return (x == 0 ? n_trials_par * stmath::log(1.0 - prob_par) :
            x == n_trials_par ? x * stmath::log(prob_par) :
            //
            stmath::log(gcem::binomial_coef(n_trials_par,x)) + x*stmath::log(prob_par) + (n_trials_par - x)*stmath::log(1.0 - prob_par) );
}

template<typename T>
statslib_constexpr
T
dbinom(const uint_t x, const uint_t n_trials_par, const T prob_par, const bool log_form)
{
    return (x > n_trials_par ? 0.0 : 
            n_trials_par == 1 ? dbern(x,prob_par,log_form) :
            //
            log_form == true ? dbinom_int(x,n_trials_par,prob_par) :
                               stmath::exp(dbinom_int(x,n_trials_par,prob_par)) );
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void
dbinom_int(const Ta* __stats_pointer_settings__ vals_in, const uint_t n_trials_par, const Tb prob_par, const bool log_form, 
                 Tc* __stats_pointer_settings__ vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = dbinom(static_cast<uint_t>(vals_in[j]),n_trials_par,prob_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
ArmaMat<Tc>
dbinom(const ArmaMat<Ta>& X, const uint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    dbinom_int<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
BlazeMat<Tc,To>
dbinom(const BlazeMat<Ta,To>& X, const uint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    dbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),X.rows()*X.columns());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
EigMat<Tc,iTr,iTc>
dbinom(const EigMat<Ta,iTr,iTc>& X, const uint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    dbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
