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

/*
 * Sample from a Binomial distribution
 */

template<typename T>
uint_t
rbinom(const uint_t n_trials_par, const T prob_par)
{
    uint_t ret = 0U;

    for (uint_t i=0U; i < n_trials_par; i++) {
        ret += rbern(prob_par);
    }

    return ret;
}

template<typename T>
void
rbinom_int(const uint_t n_trials_par, const T prob_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rbinom(n_trials_par,prob_par);
    }
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
rbinom(const uint_t n, const uint_t k, const uint_t n_trials_par, const eT prob_par)
{
    mT mat_out(n,k);

    rbinom_int(n_trials_par,prob_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
