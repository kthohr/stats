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
    mat_obj prob_vec(5,1);
    prob_vec(0,0) = 0.1;
    prob_vec(1,0) = 0.15;
    prob_vec(2,0) = 0.2;
    prob_vec(3,0) = 0.25;
    prob_vec(4,0) = 0.3;

    std::cout << "\n*** rmultinom: begin tests. ***\n" << std::endl;

    //

    std::cout << "rmultinom draw:\n" << stats::rmultinom(prob_vec) << std::endl;

    mat_obj X;
    stats::mat_ops::zeros(X,5,1);

    int n = 10000;

    for (int i=0; i < n; i++) {
        X += stats::rmultinom<mat_obj>(prob_vec) / n;
    }

    std::cout << "sample mean:\n" << X / 5.0 << std::endl;

    //

    std::cout << "\n*** rmultinom: end tests. ***\n" << std::endl;
#else
    std::cout << "\n*** rmultinom: no matrix library found. ***\n" << std::endl;
#endif

    return 0;
}
