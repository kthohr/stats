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
 * pdf of the Wishart distribution
 */

template<typename Ta, typename Te>
statslib_inline
Te
dwish(const Ta& X, const Ta& Psi_par, const Te nu_par, bool log_form)
{
    const uint_t K = mat_ops::n_rows(X);

    const Te nu_par_d2 =  nu_par / Te(2.0);

    //

    const Te lmg_term = gcem::log_multi_gamma(nu_par_d2, K);
    const Te norm_term = - nu_par_d2*std::log(mat_ops::det(Psi_par)) - nu_par_d2*K*GCEM_LOG_2 - lmg_term;

    Te ret = norm_term + 0.5*( (nu_par-K-1) * std::log(mat_ops::det(X)) - mat_ops::trace(mat_ops::solve(X,Psi_par)) );

    if (!log_form) {
        ret = std::exp(ret);
    }

    //

    return ret;
}
