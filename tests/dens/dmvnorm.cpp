/*################################################################################
  ##
  ##   Copyright (C) 2011-2021 Keith O'Hara
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

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main()
{
#ifdef STATS_TEST_MATRIX_FEATURES
    int K = 3;

    std::cout << "\n*** dmvnorm: begin tests. ***\n" << std::endl;

    mat_obj X, mu, Sigma;
    stats::mat_ops::zeros(X,K,1);
    stats::mat_ops::zeros(mu,K,1);
    stats::mat_ops::eye(Sigma,K);
    Sigma(0,0) = 1.3;
    Sigma(1,1) = 1.2;
    Sigma(2,2) = 1.1;

    double dmvnorm_val = stats::dmvnorm(X,mu,Sigma,false);

    std::cout << "density value: " << dmvnorm_val << "." << std::endl;

#ifdef STATS_ENABLE_EIGEN_WRAPPERS
    // test static versions
    Eigen::Matrix<double, 3, 1> X2(1, 1, 1);
    Eigen::Matrix<double, 3, 1> mean(0, 0, 0);
    Eigen::Matrix<double, 3, 3> Sigma2 = Eigen::Matrix3d::Identity();

    double p = stats::dmvnorm(X2, mean, Sigma2);
    std::cout << "p = " << p << "." << std::endl;
#endif

    std::cout << "\n*** dmvnorm: tests finished. ***\n" << std::endl;

#endif

    return 0;
}
