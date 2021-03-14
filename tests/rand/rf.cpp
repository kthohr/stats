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

#include "../stats_tests.hpp"

int main()
{
    print_begin("rf");

    //
    
    double a_par = 16;
    double b_par = 10;

    double F_mean = b_par / (b_par - 2.0);
    double F_var = 2.0 * b_par*b_par*(a_par + b_par - 2.0) / ( a_par*std::pow(b_par - 2.0,2)*(b_par - 4.0) );

    int n_sample = 10000;

    //

    double F_rand = stats::rf(a_par,b_par);
    std::cout << "F rv draw: " << F_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> F_stdvec = stats::rf<std::vector<double>>(n_sample,1,a_par,b_par);

    std::cout << "stdvec: F rv mean: " << stats::mat_ops::mean(F_stdvec) << ". Should be close to: " << F_mean << std::endl;
    std::cout << "stdvec: F rv variance: " << stats::mat_ops::var(F_stdvec) << ". Should be close to: " << F_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj F_vec = stats::rf<mat_obj>(n_sample,1,a_par,b_par);

    std::cout << "Matrix: F rv mean: " << stats::mat_ops::mean(F_vec) << ". Should be close to: " << F_mean << std::endl;
    std::cout << "Matrix: F rv variance: " << stats::mat_ops::var(F_vec) << ". Should be close to: " << F_var << std::endl;
#endif
    
    //

    std::cout << "\n*** rf: end tests. ***\n" << std::endl;
    
    return 0;
}
