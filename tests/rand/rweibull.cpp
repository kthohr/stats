/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

#include "stats.hpp"

int main()
{
    double shape = 3;
    double scale = 2;
    double weibull_mean = scale*std::tgamma(1.0 + 1.0/shape);
    double weibull_var = scale*scale * std::tgamma(1.0 + 2.0/shape) - std::pow(weibull_mean,2);

    std::cout << "\n*** rweibull: begin tests. ***\n" << std::endl;

    //

    double weibull_rand = stats::rweibull(shape,scale);

    std::cout << "weibull rv draw: " << weibull_rand << std::endl;

    int n = 10000;
    arma::vec weibull_vec = stats::rweibull(n,shape,scale);

    std::cout << "weibull rv mean: " << arma::mean(weibull_vec) << ". Should be close to: " << weibull_mean << std::endl;
    std::cout << "weibull rv variance: " << arma::var(weibull_vec) << ". Should be close to: " << weibull_var << std::endl;

    //
    // coverage tests

    stats::rweibull(0.7,scale);
    stats::rweibull(100,100,shape,scale);

    std::cout << "\n*** rweibull: end tests. ***\n" << std::endl;

    return 0;
}
