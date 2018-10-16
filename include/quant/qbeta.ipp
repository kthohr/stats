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
 * quantile function of the beta distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qbeta_int(const T p, const T a_par, const T b_par)
{
    return gcem::incomplete_beta_inv(a_par,b_par,p);
}

template<typename Ta, typename Tb>
statslib_constexpr
Ta
qbeta(const Ta p, const Tb a_par, const Tb b_par)
{
    return qbeta_int<Ta>(p,a_par,b_par);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qbeta_int(const Ta* __stats_pointer_settings__ vals_in, const Tb a_par, const Tb b_par, 
                Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = qbeta(vals_in[j],a_par,b_par);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qbeta(const ArmaMat<Ta>& X, const Tb a_par, const Tb b_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    qbeta_int<Ta,Tb,Tc>(X.memptr(),a_par,b_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qbeta(const ArmaGen<mT,tT>& X, const Tb a_par, const Tb b_par, const bool log_form)
{
    return qbeta(X.eval(),a_par,b_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qbeta(const BlazeMat<Ta,To>& X, const Tb a_par, const Tb b_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    qbeta_int<Ta,Tb,Tc>(X.data(),a_par,b_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qbeta(const EigMat<Ta,iTr,iTc>& X, const Tb a_par, const Tb b_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    qbeta_int<Ta,Tb,Tc>(X.data(),a_par,b_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
