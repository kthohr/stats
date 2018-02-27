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
 * pdf of the Multivariate Normal distribution
 */

template<typename Ta, typename Te>
Te
dmvnorm(const Ta& X, const Ta& mu_par, const Ta& Sigma_par, bool log_form)
{
    const uint_t K = mat_opts::get_n_rows(X);

    //

    const Te cons_term = -Te(0.5)*K*GCEM_LOG_2PI;
    const Ta quadratic_term = mat_opts::trans(x - mu_par) * mat_opts::inverse(Sigma_par) * (x - mu_par);

    Te ret = cons_term - Te(0.5) * ( std::log(mat_opts::det(Sigma_par)) + quadratic_term(0,0) );

    if (!log_form) {
        ret = std::exp(ret);
    }

    //
    
    return ret;
}
