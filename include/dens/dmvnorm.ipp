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
 * pdf of the Multivariate Normal distribution
 */

template<typename Ta, typename Te>
Te
dmvnorm(const Ta& X, const Ta& mu_par, const Ta& Sigma_par, bool log_form)
{
    const uint_t K = mat_ops::n_rows(X);

    //

    const Te cons_term = -Te(0.5)*K*GCEM_LOG_2PI;
    const Ta X_cent = X - mu_par; // avoids issues like Mat vs eGlue in templates
    const Ta quadratic_term = mat_ops::trans(X_cent) * mat_ops::inv(Sigma_par) * (X_cent);

    Te ret = cons_term - Te(0.5) * ( std::log(mat_ops::det(Sigma_par)) + quadratic_term(0,0) );

    if (!log_form) {
        ret = std::exp(ret);
    }

    //
    
    return ret;
}
