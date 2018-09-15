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

template<typename mT, typename eT>
statslib_inline
eT
dmvnorm(const mT& X, const mT& mu_par, const mT& Sigma_par, bool log_form)
{
    const uint_t K = mat_ops::n_rows(X);

    //

    const eT cons_term = -eT(0.5)*K*GCEM_LOG_2PI;
    const mT X_cent = X - mu_par; // avoids issues like Mat vs eGlue in templates
    const mT quadratic_term = mat_ops::trans(X_cent) * mat_ops::inv(Sigma_par) * (X_cent);

    /*Direct determinant computation is not safe for high dimensional matrices: underflow or overflow*/
    // eT ret = cons_term - eT(0.5) * ( std::log(mat_ops::det(Sigma_par)) + quadratic_term(0,0) );
    
    /*Safely Compute Logdeterminant using cholesky decomposition*/
    Eigen::LLT<Eigen::MatrixXd> cholesky_sigma(Sigma_par);
    Eigen::MatrixXd L = cholesky_sigma.matrixL();
    double logDetSigma = (L.diagonal().array().log()*2.0).sum(); 
    
    eT ret = cons_term - eT(0.5) * ( logDetSigma + quadratic_term(0,0) );

    if (!log_form) {
        ret = std::exp(ret);
        /*Handle overflow*/
        if(std::isinf(ret))
            ret = std::numeric_limits<eT>::max();
    }

    //
    
    return ret;
}
