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
statslib_inline
return_t<T>
rbeta_int(const T a_par, const T b_par, rand_engine_t& engine)
{
    const return_t<T> X = rgamma(a_par,T(1),engine);
    const return_t<T> Y = rgamma(b_par,T(1),engine);
    
    return X / (X + Y);
}

template<typename T>
statslib_inline
return_t<T>
rbeta(const T a_par, const T b_par, rand_engine_t& engine)
{
    return rbeta_int<return_t<T>>(a_par,b_par,engine);
}

template<typename T>
statslib_inline
return_t<T>
rbeta(const T a_par, const T b_par, ullint_t seed_val)
{
    rand_engine_t engine(seed_val);
    return rbeta_int<return_t<T>>(a_par,b_par,engine);
}

//

template<typename T>
statslib_inline
void
rbeta_int(const T a_par, const T b_par, T* vals_out, const ullint_t num_elem)
{
    RAND_DIST_FN_VEC(rbeta,vals_out,num_elem,a_par,b_par);
}

#ifdef STATS_WITH_MATRIX_LIB
template<typename mT, typename eT>
statslib_inline
mT
rbeta(const ullint_t n, const ullint_t k, const eT a_par, const eT b_par)
{
    mT mat_out(n,k);

    rbeta_int(a_par,b_par,mat_ops::get_mem_ptr(mat_out),n*mat_ops::spacing(mat_out));

    return mat_out;
}
#endif
