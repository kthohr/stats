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
#ifdef STATS_TEST_MAT
    int n_samp = 10000;
    int K = 3;

    std::cout << "\n*** rwish: begin tests. ***\n" << std::endl;

    //

    double nu = 10 + K + 1;
    mat_obj Psi, X;

    stats::mat_ops::eye(Psi,K);

    Psi /= nu;

    stats::mat_ops::zeros(X,K,K);

    for (int i=0; i < n_samp; i++) {
        X += stats::rwish<mat_obj>(Psi,nu) / static_cast<double>(n_samp);
    }

    std::cout << "true mean:\n" << Psi * static_cast<double>(nu) << std::endl;
    std::cout << "sample mean:\n" << X << std::endl;

    double dwish_val = stats::dwish(X,Psi,nu,false);

    std::cout << "density value: " << dwish_val << std::endl;

    //

    std::cout << "\n*** rwish: end tests. ***\n" << std::endl;
#else
    std::cout << "\n*** rwish: no matrix library found. ***\n" << std::endl;
#endif

    return 0;
}
