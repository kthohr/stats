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

/*
 * Sample from a multinomial distribution
 */

template<typename T>
T
rmultinom(const T& prob)
{
    typedef typename T::elem_type eT;
    const uint_t n_prob = prob.n_elem;

    uint_t n_j = n_prob;

    //

    eT p_j = 1.0;

    T ret(n_prob);
    const T prob_csum = arma::cumsum(prob);

    p_j = prob(0);
    ret(0) = rbinom(n_j,p_j);

    //

    uint_t ret_sum = arma::as_scalar(ret(0));
    
    for (uint_t j = 1U; j < n_prob; j++)
    {
        p_j = prob(j) / (eT(1.0) - prob_csum(j-1));
        n_j = n_prob - ret_sum;
        
        ret(j) = rbinom(n_j,p_j);
        
        ret_sum += ret(j);
    }

    //

    return ret;
}
