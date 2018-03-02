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
    int K = 2;

    std::cout << "\n*** dwish: begin tests. ***\n" << std::endl;

    mat_obj X,Psi;
    stats::mat_ops::eye(X,K);
    stats::mat_ops::eye(Psi,K);

    double dwish_val = stats::dwish(X,Psi,K+1,false);

    std::cout << "density value = " << dwish_val << "." << std::endl;

    std::cout << "\n*** dwish: tests finished. ***\n" << std::endl;
#endif

    return 0;
}
