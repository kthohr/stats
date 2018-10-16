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
 * pdf of the F distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
df_int_adj(const T x, const T ratio_abx)
{
    return ( ratio_abx * (T(1) - x*ratio_abx) );
}

template<typename T>
statslib_constexpr
T
df_int(const T x, const T a_par, const T b_par, const T abx, const bool log_form)
{
    return ( log_form == true ? \
             // if
                dbeta(abx/(T(1)+abx),a_par,b_par,true)  + stmath::log(df_int_adj(x,(a_par/b_par)/(T(1) + abx))) :
             // else
                dbeta(abx/(T(1)+abx),a_par,b_par,false) * df_int_adj(x,(a_par/b_par)/(T(1) + abx)) );
}

template<typename T>
statslib_constexpr
T
df_check(const T x, const T df1_par, const T df2_par, const bool log_form)
{
    return df_int(x,df1_par/T(2),df2_par/T(2),df1_par*x/df2_par,log_form);
}

template<typename Ta, typename Tb>
statslib_constexpr
return_t<Ta>
df(const Ta x, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    return df_check<return_t<Ta>>(x,df1_par,df2_par,log_form);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
df_int(const Ta* __stats_pointer_settings__ vals_in, const Tb df1_par, const Tb df2_par, const bool log_form,
             Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = df(vals_in[j],df1_par,df2_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
df(const ArmaMat<Ta>& X, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    df_int<Ta,Tb,Tc>(X.memptr(),df1_par,df2_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
df(const ArmaGen<mT,tT>& X, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    return df(X.eval(),df1_par,df2_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
df(const BlazeMat<Ta,To>& X, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    df_int<Ta,Tb,Tc>(X.data(),df1_par,df2_par,log_form,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
df(const EigMat<Ta,iTr,iTc>& X, const Tb df1_par, const Tb df2_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    df_int<Ta,Tb,Tc>(X.data(),df1_par,df2_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
