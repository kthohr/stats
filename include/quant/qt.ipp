/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
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
 * quantile function of the t distribution
 * 
 * using   Hill, G. W. (1970) "Algorithm 396: Student's t-Quantiles", ACM COMS 13(10), 619-20 
 *         Hill, G. W. (1981) "Remark on "Algorithm 396: Student's t-Quantiles"", ACM TOMS 7, 250-1
 */

//
// single input

// coefficients

statslib_constexpr
long double
qt_int_coef_a(const int dof_par)
{
    return ( 1.0L / (dof_par - 0.5L) );
}

statslib_constexpr
long double
qt_int_coef_b(const long double coef_a)
{
    return ( 48.0L / (coef_a * coef_a) );
}

statslib_constexpr
long double
qt_int_coef_c(const long double coef_a, const long double coef_b)
{
    return ( 96.36 + coef_a * ( - 16.0L + coef_a * ( - 98.0L + 20700.0L*coef_a/coef_b ) ) );
}

statslib_constexpr
long double
qt_int_coef_c_update(const long double x, const long int dof_par, const long double coef_c)
{
    return ( (dof_par < 5) ? coef_c + 0.3L*(dof_par - 4.5L)*(x + 0.6L) : coef_c );
}

statslib_constexpr
long double
qt_int_coef_d(const int dof_par, const long double coef_a, const long double coef_b, const long double coef_c)
{
    return ( static_cast<long double>(dof_par) * stats_math::sqrt(coef_a) * GCEM_SQRT_HALF_PI * ( 1.0L + (-3.0L + 94.5L/(coef_b + coef_c))/coef_b ) );
}

// initial y

statslib_constexpr
long double
qt_int_y_init(const long double p, const int dof_par, const long double coef_d)
{
    return ( gcem::pow_dbl( coef_d*p , 2.0L/static_cast<long double>(dof_par) ) );
}

// update y

statslib_constexpr
long double
qt_int_y_1_update(const int stage, const long double y, const long double x, const long double coef_a, const long double coef_b, const long double coef_c)
{
    return ( stage == 1 ? x*x : 
             stage == 2 ? x * ( 1.0L + ( ( y * ( 36.0L + y * (6.3L + 0.4L*y) ) + 94.5)/coef_c - y - 3.0L ) / coef_b ) :
             stage == 3 ? coef_a * y * y :
                          (y > 0.1L ? stats_math::exp(y) - 1.0L : y * (1.0L + y * (12.0L + y * (4.0L + y))/24.0L ) ) );
}

statslib_constexpr
long double
qt_int_y_1(const int stage, const long double y, const long double x, const int dof_par, const long double coef_a, const long double coef_b, const long double coef_c, const long double coef_d)
{
    return ( stage == 0 ? qt_int_y_1(1,0.0,x,dof_par,coef_a,coef_b, qt_int_coef_c_update(x,dof_par,coef_c) ,coef_d) : 
             stage == 1 ? qt_int_y_1(2,qt_int_y_1_update(1,y,x,coef_a,coef_b,coef_c),x,dof_par,coef_a,coef_b, coef_b + coef_c + x * (- 2.0L + x * (- 7.0L + x * (-5.0L + x*coef_d*0.05))),coef_d) : 
             stage == 2 ? qt_int_y_1(3,qt_int_y_1_update(2,y,x,coef_a,coef_b,coef_c),x,dof_par,coef_a,coef_b,coef_c,coef_d) :
             stage == 3 ? qt_int_y_1(4,qt_int_y_1_update(3,y,x,coef_a,coef_b,coef_c),x,dof_par,coef_a,coef_b,coef_c,coef_d) :
                          qt_int_y_1_update(4,y,x,coef_a,coef_b,coef_c) );
}

statslib_constexpr
long double
qt_int_y_2(const long double y, const int dof_par, const long double coef_b, const long double coef_c, const long double coef_d)
{
    return ( (1.0L/y) + (dof_par + 1.0L) * ( (1.0L / (((dof_par + 6.0L) / (dof_par * y) - 0.089L*coef_d - 0.822L) * (dof_par + 2.0L) * 3.0L) + 0.5L / (dof_par + 4.0L)) * y - 1.0L) / (dof_par + 2.0L) );
}

statslib_constexpr
long double
qt_int_choose(const long double p, const long double y, const int dof_par, const long double coef_a, const long double coef_b, const long double coef_c, const long double coef_d)
{
    return ( y > 0.05 + coef_a ? qt_int_y_1(0,y,qnorm(0.5L*p),dof_par,coef_a,coef_b,coef_c,coef_d) : qt_int_y_2(y,dof_par,coef_b,coef_c,coef_d) );
}

statslib_constexpr
long double
qt_int_finish(const long double p, const int dof_par, const long double coef_a, const long double coef_b, const long double coef_c, const long double coef_d)
{
    return ( stats_math::sqrt( dof_par * qt_int_choose(p, qt_int_y_init(p,dof_par,coef_d), dof_par,coef_a,coef_b,coef_c,coef_d) ) );
}

statslib_constexpr
long double
qt_int_main_iter(const int stage, const long double p, const int dof_par, const long double coef_a, const long double coef_b, const long double coef_c, const long double coef_d)
{
    return ( stage == 0 ? qt_int_main_iter(1,p,dof_par,qt_int_coef_a(dof_par),0,0,0) :
             stage == 1 ? qt_int_main_iter(2,p,dof_par,coef_a,qt_int_coef_b(coef_a),0,0) : 
             stage == 2 ? qt_int_main_iter(3,p,dof_par,coef_a,coef_b,qt_int_coef_c(coef_a,coef_b),0) :
             stage == 3 ? qt_int_main_iter(4,p,dof_par,coef_a,coef_b,coef_c,qt_int_coef_d(dof_par,coef_a,coef_b,coef_c)) :
                          qt_int_finish(p,dof_par,coef_a,coef_b,coef_c,coef_d) );
}

statslib_constexpr
long double
qt_int_main(const long double p, const int dof_par)
{
    return ( p < 0.5 ? - qt_int_main_iter(0,2*p,dof_par,0,0,0,0) : qt_int_main_iter(0,2*p,dof_par,0,0,0,0) );
}

statslib_constexpr
long double
qt_int(const long double p, const int dof_par)
{
    return ( dof_par == 1 ? stats_math::tan(GCEM_PI*(p - 0.5L)) : // Cauchy
             dof_par == 2 ? (2*p - 1.0L) / stats_math::sqrt(2*p*(1.0L - p)) :
                            qt_int_main(p,dof_par) );
}

//

template<typename T>
statslib_constexpr
T
qt(const T p, const int dof_par, const bool log_form)
{
    return ( log_form == true ? stats_math::log(qt_int(p,dof_par)) : qt_int(p,dof_par) );
}

statslib_constexpr
double
qt(const double p)
{
    return qt(p,30,false);
}

statslib_constexpr
double
qt(const double p, const bool log_form)
{
    return qt(p,1.0,log_form);
}

statslib_constexpr
double
qt(const double p, const int dof_par)
{
    return qt(p,dof_par,false);
}

//
// matrix/vector input

#ifndef STATS_NO_ARMA

inline
arma::mat
qt_int(const arma::mat& p, const int* dof_par_inp, bool log_form)
{
    const int dof_par = (dof_par_inp) ? *dof_par_inp : 30;
    
    const int n = p.n_rows;
    const int k = p.n_cols;

    //

    arma::mat ret(n,k);

    const double* inp_mem = p.memptr();
    double* ret_mem = ret.memptr();

#ifndef STATS_NO_OMP
    #pragma omp parallel for
#endif
    for (int j=0; j < n*k; j++)
    {
        ret_mem[j] = qt(inp_mem[j],dof_par,log_form);
    }

    //

    return ret;
}

inline
arma::mat
qt(const arma::mat& p)
{
    return qt_int(p,nullptr,false);
}

inline
arma::mat
qt(const arma::mat& p, const bool log_form)
{
    return qt_int(p,nullptr,log_form);
}

inline
arma::mat
qt(const arma::mat& p, const int dof_par)
{
    return qt_int(p,&dof_par,false);
}

inline
arma::mat
qt(const arma::mat& p, const int dof_par, const bool log_form)
{
    return qt_int(p,&dof_par,log_form);
}

#endif
