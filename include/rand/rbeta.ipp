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
 * Sample from a Beta distribution
 */

template<typename T>
T
rbeta(const T a_par, const T b_par)
{
    const T X = rgamma(a_par,T(1.0));
    const T Y = rgamma(b_par,T(1.0));

    //
    
    return X / (X + Y);
}

template<typename T>
void
rbeta_int(const T a_par, const T b_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rbeta(a_par,b_par);
    }
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
rbeta(const uint_t n, const uint_t k, const eT a_par, const eT b_par)
{
    mT mat_out(n,k);

    rbeta_int(a_par,b_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
