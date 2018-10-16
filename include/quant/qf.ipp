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
 * quantile function of the F distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
qf_int_adj(const T I_inv_val, const T ab_ratio)
{
    return ( I_inv_val / (ab_ratio*(T(1) - I_inv_val)) ) ;
}

template<typename T>
statslib_constexpr
T
qf_int(const T p, const T a_par, const T b_par)
{
    return ( qf_int_adj(gcem::incomplete_beta_inv(a_par,b_par,p),a_par/b_par) );
}

template<typename T>
statslib_constexpr
T
qf_check(const T p, const T df1_par, const T df2_par)
{
    return ( STLIM<T>::epsilon() > p ? T(0) :
             //
             qf_int(p,df1_par/T(2),df2_par/T(2)) );
}

template<typename Ta, typename Tb>
statslib_constexpr
Ta
qf(const Ta p, const Tb df1_par, const Tb df2_par)
{
    return qf_check<Ta>(p,df1_par,df2_par);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qf_int(const Ta* __stats_pointer_settings__ vals_in, const Tb df1_par, const Tb df2_par, 
             Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = qf(vals_in[j],df1_par,df2_par);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qf(const ArmaMat<Ta>& X, const Tb df1_par, const Tb df2_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    qf_int<Ta,Tb,Tc>(X.memptr(),df1_par,df2_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qf(const ArmaGen<mT,tT>& X, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    return qf(X.eval(),df1_par,df2_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qf(const BlazeMat<Ta,To>& X, const Tb df1_par, const Tb df2_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    qf_int<Ta,Tb,Tc>(X.data(),df1_par,df2_par,mat_out.data(),X.rows()*X.spacing());

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

    qf_int<Ta,Tb,Tc>(X.data(),df1_par,df2_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
