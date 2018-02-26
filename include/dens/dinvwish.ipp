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
 * pdf of the inverse-Wishart distribution
 */

template<typename T>
double
dinvwish_int(const T& X, const T& Psi_par, const uint_t nu_par, bool log_form)
{
    const uint_t K = mat_opts::get_n_rows(X);

    const double nu_par_d2 = static_cast<double> (nu_par) / 2.0;

    //

    const double lmg_term = gcem::log_multi_gamma(nu_par_d2, K);
    const double norm_term = nu_par_d2*std::log(mat_opts::det(Psi_par)) - nu_par_d2*K*GCEM_LOG_2 - lmg_term;

    double ret = norm_term - 0.5*( (nu_par+K+1) * std::log(mat_opts::det(X)) + mat_opts::trace(mat_opts::solve(X,Psi_par)) );

    if (!log_form) {
        ret = std::exp(ret);
    }

    //
    
    return ret;
}
