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

#include "stats.hpp"
#include "../stats_tests.hpp"

int main()
{
    arma::vec prob_vec(5);
    prob_vec(0) = 0.1;
    prob_vec(1) = 0.15;
    prob_vec(2) = 0.2;
    prob_vec(3) = 0.25;
    prob_vec(4) = 0.3;

    std::cout << "\n*** rmultinom: begin tests. ***\n" << std::endl;

    //

    arma::cout << "rmultinom draw:\n" << stats::rmultinom(prob_vec) << arma::endl;

    arma::mat X = arma::zeros(5,1);

    int n = 10000;

    for (int i=0; i < n; i++) {
        X += stats::rmultinom(prob_vec) / n;
    }

    arma::cout << "sample mean:\n" << X << arma::endl;

    //

    std::cout << "\n*** rmultinom: end tests. ***\n" << std::endl;

    return 0;
}
