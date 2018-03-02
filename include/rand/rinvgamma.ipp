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
 * Sample from an inverse-gamma distribution
 */

template<typename T>
T
rinvgamma(T shape_par, T rate_par)
{
    return T(1.0) / rgamma(shape_par,T(1.0)/rate_par);
}

template<typename T>
void
rinvgamma_int(const T shape_par, const T rate_par, T* vals_out, const uint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (uint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = rinvgamma(shape_par,rate_par);
    }
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
mT
rinvgamma(const uint_t n, const uint_t k, const eT shape_par, const eT rate_par)
{
    mT mat_out(n,k);

    rinvgamma_int(shape_par,rate_par,mat_ops::get_mem_ptr(mat_out),n*k);

    return mat_out;
}
#endif
