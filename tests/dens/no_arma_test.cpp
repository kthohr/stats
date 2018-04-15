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

#include <math.h>
#include <iomanip>
#include "stats.hpp"

int main()
{
    double err_tol = 1E-05;

    double mu = 1;
    double sigma = 2;

    // x = 2
    double x_1 = 2;
    double val_1 = 0.17603266;
    double dens_1 = stats::dnorm(x_1,mu,sigma);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);

    // x = 1, return log
    double x_2 = 1;
    double val_2 = -1.612085;
    double dens_2 = stats::dnorm(x_2,mu,sigma,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);

    if (success_1 && success_2) {
        printf("\nno_arma: \033[32mall tests PASSED.\033[0m\n");
    }

    return 0;
}
