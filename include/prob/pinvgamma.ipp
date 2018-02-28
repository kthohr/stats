/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

/*
 * cdf of the inverse-gamma distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
pinvgamma_int(const T x, const T shape_par, const T rate_par)
{
    return ( T(1.0) - gcem::incomplete_gamma(shape_par,rate_par/x) );
}

template<typename T>
statslib_constexpr
T
pinvgamma(const T x, const T shape_par, const T rate_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(pinvgamma_int(x,shape_par,rate_par)) :
                                pinvgamma_int(x,shape_par,rate_par) );
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void
pinvgamma_int(const Ta* __stats_pointer_settings__ vals_in, const Tb shape_par, const Tb rate_par, const bool log_form, 
                    Tc* __stats_pointer_settings__ vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = pinvgamma(vals_in[j],shape_par,rate_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
ArmaMat<Tc>
pinvgamma(const ArmaMat<Ta>& X, const Tb shape_par, const Tb rate_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    pinvgamma_int<Ta,Tb,Tc>(X.memptr(),shape_par,rate_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
BlazeMat<Tc,To>
pinvgamma(const BlazeMat<Ta,To>& X, const Tb shape_par, const Tb rate_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    pinvgamma_int<Ta,Tb,Tc>(X.data(),shape_par,rate_par,log_form,mat_out.data(),X.rows()*X.columns());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
EigMat<Tc,iTr,iTc>
pinvgamma(const EigMat<Ta,iTr,iTc>& X, const Tb shape_par, const Tb rate_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    pinvgamma_int<Ta,Tb,Tc>(X.data(),shape_par,rate_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
