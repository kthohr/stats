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
 * pdf of the Wishart distribution
 */

template<typename Ta, typename Te>
Te
dwish(const Ta& X, const Ta& Psi_par, const uint_t nu_par, bool log_form)
{
    const uint_t K = mat_opts::get_n_rows(X);

    const Te nu_par_d2 = static_cast<Te>(nu_par) / Te(2.0);

    //

    const Te lmg_term = gcem::log_multi_gamma(nu_par_d2, K);
    const Te norm_term = - nu_par_d2*std::log(mat_opts::det(Psi_par)) - nu_par_d2*K*GCEM_LOG_2 - lmg_term;

    Te ret = norm_term + 0.5*( (nu_par-K-1) * std::log(mat_opts::det(X)) - mat_opts::trace(mat_opts::solve(X,Psi_par)) );

    if (!log_form) {
        ret = std::exp(ret);
    }

    //
    
    return ret;
}
