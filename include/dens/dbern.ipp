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
 * pdf of the Bernoulli distribution
 */

//
// single input

template<typename T>
statslib_constexpr
T
dbern_int(const int x, const T prob_par)
{
    return ( x == 1 ? prob_par : T(1.0) - prob_par );
}

template<typename T>
statslib_constexpr
T
dbern(const int x, const T prob_par, const bool log_form)
{
    return ( log_form == true ? stmath::log(dbern_int(x,prob_par)) : dbern_int(x,prob_par) );
}

template<typename T>
statslib_constexpr
T
dbern(const int x)
{
    return dbern<T>(x,T(0.5),false);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void
dbern_int(const Ta* vals_in, const Tb prob_par, const bool log_form, Tc* vals_out, uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = dbern(static_cast<int>(vals_in[j]),prob_par,log_form);
    }
}

#ifdef STATS_USE_ARMA

template<typename Ta, typename Tb, typename Tc>
ArmaMat<Tc>
dbern(const ArmaMat<T>& X, const Tb prob_par, const bool log_form)
{
    arma::Mat<Tc> mat_out(X.n_rows,X.n_cols);

    dbern_int<Ta,Tb,Tc>(X.memptr(),prob_par,log_form,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

#endif

#ifdef STATS_USE_BLAZE

template<typename Ta, typename Tb, typename Tc, bool To>
BlazeMat<Tc,To>
dbern(const BlazeMat<Ta,To>& X, const Tb prob_par, const bool log_form)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    dbern_int<Ta,Tb,Tc>(X.data(),prob_par,log_form,mat_out.data(),X.rows()*X.columns());

    return mat_out;
}

#endif

#ifdef STATS_USE_EIGEN

template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
EigMat<Tc,iTr,iTc>
dbern(const EigMat<Ta,iTr,iTc>& X, const Tb prob_par, const bool log_form)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    dbern_int<Ta,Tb,Tc>(X.data(),prob_par,log_form,mat_out.data(),mat_out.size());

    return mat_out;
}

#endif
