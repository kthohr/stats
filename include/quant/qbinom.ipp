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
 * quantile function of the Binomial distribution
 */

//
// single input

template<typename Ta, typename Tb>
statslib_constexpr
Tb
qbinom_int(const Ta p, const ullint_t n_trials_par, const Ta prob_par, const Ta value, const ullint_t count)
{
    return ( value <= p ? qbinom_int<Ta,Tb>(p,n_trials_par,prob_par, pbinom(count,n_trials_par,prob_par), count + 1) :
                          count - 1 );
}

template<typename Ta, typename Tb>
statslib_constexpr
Tb
qbinom(const Ta p, const ullint_t n_trials_par, const Ta prob_par)
{
    return ( STLIM<Ta>::epsilon() > p ? Tb(0) :
             //
             qbinom_int<Ta,Tb>(p,n_trials_par,prob_par,Ta(0),0U) );
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qbinom_int(const Ta* __stats_pointer_settings__ vals_in, const ullint_t n_trials_par, const Tb prob_par, 
                 Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = qbinom(vals_in[j],n_trials_par,prob_par);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qbinom(const ArmaMat<Ta>& X, const ullint_t n_trials_par, const Tb prob_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    qbinom_int<Ta,Tb,Tc>(X.memptr(),n_trials_par,prob_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qbinom(const ArmaGen<mT,tT>& X, const ullint_t n_trials_par, const Tb prob_par, const bool log_form)
{
    return qbinom(X.eval(),n_trials_par,prob_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qbinom(const BlazeMat<Ta,To>& X, const ullint_t n_trials_par, const Tb prob_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    qbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qbinom(const EigMat<Ta,iTr,iTc>& X, const ullint_t n_trials_par, const Tb prob_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    qbinom_int<Ta,Tb,Tc>(X.data(),n_trials_par,prob_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
