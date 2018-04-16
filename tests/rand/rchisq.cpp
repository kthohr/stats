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
    double dof = 3;
    
    std::cout << "\n*** rchisq: begin tests. ***\n" << std::endl;

    //

    double chisq_rand = stats::rchisq(dof);

    std::cout << "chisq rv draw: " << chisq_rand << std::endl;

#ifdef STATS_TEST_MAT
    double chisq_mean = dof;
    double chisq_var = 2*dof;

    int n = 100000;
    mat_obj chisq_vec = stats::rchisq<mat_obj>(n,1,dof);

    std::cout << "chisq rv mean: " << stats::mat_ops::mean(chisq_vec) << ". Should be close to: " << chisq_mean << std::endl;
    std::cout << "chisq rv variance: " << stats::mat_ops::var(chisq_vec) << ". Should be close to: " << chisq_var << std::endl;
#endif

    //

    std::cout << "\n*** rchisq: end tests. ***\n" << std::endl;

    return 0;
}
