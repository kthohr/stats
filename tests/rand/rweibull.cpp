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
    double shape = 3;
    double scale = 2;

    std::cout << "\n*** rweibull: begin tests. ***\n" << std::endl;

    //

    double weibull_rand = stats::rweibull(shape,scale);

    std::cout << "weibull rv draw: " << weibull_rand << std::endl;

#ifdef STATS_TEST_MAT
    double weibull_mean = scale*std::tgamma(1.0 + 1.0/shape);
    double weibull_var = scale*scale * std::tgamma(1.0 + 2.0/shape) - std::pow(weibull_mean,2);

    int n = 100000;
    mat_obj weibull_vec = stats::rweibull<mat_obj>(n,1,shape,scale);

    std::cout << "weibull rv mean: " << stats::mat_ops::mean(weibull_vec) << ". Should be close to: " << weibull_mean << std::endl;
    std::cout << "weibull rv variance: " << stats::mat_ops::var(weibull_vec) << ". Should be close to: " << weibull_var << std::endl;
#endif

    //

    std::cout << "\n*** rweibull: end tests. ***\n" << std::endl;

    return 0;
}
