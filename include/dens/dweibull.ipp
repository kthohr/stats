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
 * pdf of the Weibull distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dweibull_int(const T x, const T shape_par, const T scale_par)
{
    return ( stmath::log(shape_par/scale_par) + (shape_par-1)*stmath::log(x) - stmath::pow(x,shape_par) );
}

template<typename T>
statslib_constexpr
T
dweibull(const T x, const T shape_par, const T scale_par, const bool log_form)
{
    return ( ( (shape_par < STLIM<T>::epsilon()) || (scale_par < STLIM<T>::epsilon()) ) ? STLIM<T>::quiet_NaN() :
             //
             x < STLIM<T>::epsilon() ? (log_form == false ? T(0.0) : - STLIM<T>::infinity()) :
             //
             log_form == true ? dweibull_int(x/scale_par,shape_par,scale_par) : 
                                stmath::exp(dweibull_int(x/scale_par,shape_par,scale_par)) );
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void
dweibull_int(const Ta* __stats_pointer_settings__ vals_in, const Tb shape_par, const Tb scale_par, const bool log_form, 
                   Tc* __stats_pointer_settings__ vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = dweibull(vals_in[j],shape_par,scale_par,log_form);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
ArmaMat<Tc>
dweibull(const ArmaMat<Ta>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    dweibull_int<Ta,Tb,Tc>(X.memptr(),shape_par,scale_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
BlazeMat<Tc,To>
dweibull(const BlazeMat<Ta,To>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    dweibull_int<Ta,Tb,Tc>(X.data(),shape_par,scale_par,log_form,mat_out.data(),X.rows()*X.columns());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
EigMat<Tc,iTr,iTc>
dweibull(const EigMat<Ta,iTr,iTc>& X, const Tb shape_par, const Tb scale_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    dweibull_int<Ta,Tb,Tc>(X.data(),shape_par,scale_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
