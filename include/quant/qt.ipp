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
 * quantile function of the t distribution
 *
 * using   Hill, G. W. (1970) "Algorithm 396: Student's t-Quantiles", ACM COMS 13(10), 619-20
 *         Hill, G. W. (1981) "Remark on "Algorithm 396: Student's t-Quantiles"", ACM TOMS 7, 250-1
 */

//
// single input

// coefficients

template<typename T>
statslib_constexpr
T
qt_int_coef_a(const T dof_par)
{
    return ( T(1) / (dof_par - T(0.5)) );
}

template<typename T>
statslib_constexpr
T
qt_int_coef_b(const T coef_a)
{
    return ( T(48) / (coef_a * coef_a) );
}

template<typename T>
statslib_constexpr
T
qt_int_coef_c(const T coef_a, const T coef_b)
{
    return ( T(96.36) + coef_a * ( - T(16) + coef_a * ( - T(98) + T(20700)*coef_a/coef_b ) ) );
}

template<typename T>
statslib_constexpr
T
qt_int_coef_c_update(const T x, const T dof_par, const T coef_c)
{
    return ( (dof_par < T(5)) ? coef_c + T(0.3)*(dof_par - T(4.5))*(x + T(0.6)) :
                                  coef_c );
}

template<typename T>
statslib_constexpr
T
qt_int_coef_d(const T dof_par, const T coef_a, const T coef_b, const T coef_c)
{
    return ( dof_par * stmath::sqrt(coef_a) * GCEM_SQRT_HALF_PI * \
                ( T(1) + (-T(3) + T(94.5)/(coef_b + coef_c))/coef_b ) );
}

// initial y

template<typename T>
statslib_constexpr
T
qt_int_y_init(const T p, const T dof_par, const T coef_d)
{
    return ( stmath::pow( coef_d*p , T(2)/dof_par ) );
}

// update y

template<typename T>
statslib_constexpr
T
qt_int_y_1_update(const int stage, const T y, const T x, const T coef_a, const T coef_b, const T coef_c)
{
    return ( stage == 1 ? x*x :
             stage == 2 ? x * ( T(1) + ( ( y * (T(36) + y * (T(6.3) + y*T(0.4))) + T(94.5) )/coef_c - y - T(3) ) / coef_b ) :
             stage == 3 ? coef_a * y * y :
             //
             y > T(0.1) ? stmath::exp(y) - T(1) : // see Remark on Algorithm 396
                          y + y * y * (T(12) + y * (T(4) + y))/T(24) );
}

//

template<typename T>
statslib_constexpr
T
qt_int_y_1(const int stage, const T y, const T x, const T dof_par, const T coef_a, const T coef_b, const T coef_c, const T coef_d)
{
    return ( stage == 0 ? qt_int_y_1(1,T(0), x, dof_par, coef_a, coef_b, qt_int_coef_c_update(x,dof_par,coef_c), coef_d) :
             //
             stage == 1 ? qt_int_y_1(2, qt_int_y_1_update(1,y,x,coef_a,coef_b,coef_c), x, dof_par, coef_a, coef_b,
                                     coef_b + coef_c + x * (- T(2) + x * (- T(7) + x * (-T(5) + T(0.05)*x*coef_d))), coef_d) :
             //
             stage == 2 ? qt_int_y_1(3,qt_int_y_1_update(2,y,x,coef_a,coef_b,coef_c),x,dof_par,coef_a,coef_b,coef_c,coef_d) :
             //
             stage == 3 ? qt_int_y_1(4,qt_int_y_1_update(3,y,x,coef_a,coef_b,coef_c),x,dof_par,coef_a,coef_b,coef_c,coef_d) :
             //
                          qt_int_y_1_update(4,y,x,coef_a,coef_b,coef_c) );
}

// small dof cases

template<typename T>
statslib_constexpr
T qt_int_y_2_iter_loop(const T p, const T dof_par, const T val_out, const T x, const int iter);

template<typename T>
statslib_constexpr
T
qt_int_y_2_iter_val_update(const T val_out, const T dof_par, const T x)
{
    return val_out + x * (T(1) + x*val_out * (T(1) + dof_par) / (T(2) * (dof_par + val_out*val_out)));
}

template<typename T>
statslib_constexpr
T
qt_int_y_2_iter_loop_update(const T p, const T dof_par, const T val_out, const T x, const int iter)
{
    return iter < 6 ? qt_int_y_2_iter_loop(p,dof_par,val_out,(T(1)-pt(val_out,dof_par,false)-p)/dt(val_out,dof_par,false),iter+1) :
                      val_out;
}

template<typename T>
statslib_constexpr
T
qt_int_y_2_iter_loop(const T p, const T dof_par, const T val_out, const T x, const int iter)
{
    return qt_int_y_2_iter_loop_update(p,dof_par,qt_int_y_2_iter_val_update(val_out,dof_par,x),T(0),iter);
}

template<typename T>
statslib_constexpr
T
qt_int_y_2_iter_begin(const T p, const T dof_par, const T y)
{
    return qt_int_y_2_iter_loop(p/T(2),dof_par,stmath::sqrt(dof_par*y),T(0),0);
}

template<typename T>
statslib_constexpr
T
qt_int_y_2_mterm(const T y, const T dof_par, const T coef_d)
{
    return ( T(0.5) / (dof_par + T(4)) + T(1) / ( ((dof_par + T(6)) / (dof_par * y) - T(0.089)*coef_d - T(0.822)) * (dof_par + T(2)) * T(3) ) );
}

template<typename T>
statslib_constexpr
T
qt_int_y_2(const T p, const T y, const T dof_par, const T coef_d)
{
    return qt_int_y_2_iter_begin(p, dof_par, (T(1)/y) + (dof_par + T(1)) * ( qt_int_y_2_mterm(y,dof_par,coef_d) * y - T(1)) / (dof_par + T(2)));
}

//

template<typename T>
statslib_constexpr
T
qt_int_choose(const T p, const T y, const T dof_par, const T coef_a, const T coef_b, const T coef_c, const T coef_d)
{
    return ( y > T(0.05) + coef_a ? stmath::sqrt( dof_par * qt_int_y_1(0,y,qnorm(T(0.5)*p),dof_par,coef_a,coef_b,coef_c,coef_d)) :
                                    qt_int_y_2(p,y,dof_par,coef_d) );
}

template<typename T>
statslib_constexpr
T
qt_int_finish(const T p, const T dof_par, const T coef_a, const T coef_b, const T coef_c, const T coef_d)
{
    return qt_int_choose(p, qt_int_y_init(p,dof_par,coef_d), dof_par,coef_a,coef_b,coef_c,coef_d);
}

template<typename T>
statslib_constexpr
T
qt_int_main_iter(const ullint_t stage, const T p, const T dof_par, const T coef_a, const T coef_b, const T coef_c, const T coef_d)
{
    return ( stage == 0U ? qt_int_main_iter(1U,p,dof_par,qt_int_coef_a(dof_par),T(0),T(0),T(0)) :
             stage == 1U ? qt_int_main_iter(2U,p,dof_par,coef_a,qt_int_coef_b(coef_a),T(0),T(0)) :
             stage == 2U ? qt_int_main_iter(3U,p,dof_par,coef_a,coef_b,qt_int_coef_c(coef_a,coef_b),T(0)) :
             stage == 3U ? qt_int_main_iter(4U,p,dof_par,coef_a,coef_b,coef_c,qt_int_coef_d(dof_par,coef_a,coef_b,coef_c)) :
                           qt_int_finish(p,dof_par,coef_a,coef_b,coef_c,coef_d) );
}

template<typename T>
statslib_constexpr
T
qt_int_main(const T p, const T dof_par)
{
    return ( p < T(0.5) ? - qt_int_main_iter(0U,2*p,dof_par,T(0),T(0),T(0),T(0)) : qt_int_main_iter(0U,2*p,dof_par,T(0),T(0),T(0),T(0)) );
}

template<typename T>
statslib_constexpr
T
qt_int(const T p, const T dof_par)
{
    return ( STLIM<T>::epsilon() > stmath::abs(T(1) - dof_par) ? stmath::tan(GCEM_PI*(p - T(0.5))) : // Cauchy case
             STLIM<T>::epsilon() > stmath::abs(T(2) - dof_par) ? (2*p - T(1)) / stmath::sqrt(2*p*(T(1) - p)) :
                                                                 qt_int_main(p,dof_par) );
}

//

template<typename Ta, typename Tb>
statslib_constexpr
Ta
qt(const Ta p, const Tb dof_par)
{
    return qt_int<return_t<Ta>>(p,dof_par);
}

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc>
statslib_inline
void
qt_int(const Ta* __stats_pointer_settings__ vals_in, const Tb dof_par,
             Tc* __stats_pointer_settings__ vals_out, const ullint_t num_elem)
{
#ifdef STATS_USE_OPENMP
    #pragma omp parallel for
#endif
    for (ullint_t j=0U; j < num_elem; j++)
    {
        vals_out[j] = qt(vals_in[j],dof_par);
    }
}

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc>
statslib_inline
ArmaMat<Tc>
qt(const ArmaMat<Ta>& X, const Tb dof_par)
{
    ArmaMat<Tc> mat_out(X.n_rows,X.n_cols);

    qt_int<Ta,Tb,Tc>(X.memptr(),dof_par,mat_out.memptr(),mat_out.n_elem);

    return mat_out;
}

template<typename mT, typename tT, typename Tb>
statslib_inline
mT
qt(const ArmaGen<mT,tT>& X, const Tb dof_par, const bool log_form)
{
    return qt(X.eval(),dof_par,log_form);
}
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc, bool To>
statslib_inline
BlazeMat<Tc,To>
qt(const BlazeMat<Ta,To>& X, const Tb dof_par)
{
    BlazeMat<Tc,To> mat_out(X.rows(),X.columns());

    qt_int<Ta,Tb,Tc>(X.data(),dof_par,mat_out.data(),X.rows()*X.spacing());

    return mat_out;
}
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc, int iTr, int iTc>
statslib_inline
EigMat<Tc,iTr,iTc>
qt(const EigMat<Ta,iTr,iTc>& X, const Tb dof_par)
{
    EigMat<Tc,iTr,iTc> mat_out(X.rows(),X.cols());

    qt_int<Ta,Tb,Tc>(X.data(),dof_par,mat_out.data(),mat_out.size());

    return mat_out;
}
#endif
