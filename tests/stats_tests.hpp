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

#include <cmath>
#include <iostream>
#include <iomanip>

#if defined(STATS_USE_ARMA) || defined(STATS_USE_BLAZE) || defined(STATS_USE_EIGEN)
    #define STATS_TEST_MAT
#endif

#ifdef STATS_TEST_MAT
    #if defined(STATS_USE_ARMA)
        #define mat_obj arma::mat
    #elif defined(STATS_USE_BLAZE)
        #define mat_obj blaze::DynamicMatrix<double>
    #else
        #define mat_obj Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>
    #endif
#endif
