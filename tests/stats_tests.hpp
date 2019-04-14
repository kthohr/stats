/*################################################################################
  ##
  ##   Copyright (C) 2011-2019 Keith O'Hara
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

//

#ifndef STATS_TEST_INPUT_TYPE
    #define STATS_TEST_INPUT_TYPE 0 // switch between d/p (0) and q (1) cases (log_form input)
#endif

#ifndef TEST_NAN
    #define TEST_NAN stats::STLIM<double>::quiet_NaN()
#endif

#ifndef TEST_POSINF
    #define TEST_POSINF stats::STLIM<double>::infinity()
#endif

#ifndef TEST_NEGINF
    #define TEST_NEGINF -stats::STLIM<double>::infinity()
#endif

#ifndef TEST_STRIP_MACRO
    #define TEST_STRIP_MACRO(x) #x
#endif

#ifndef TEST_PRINT_LEVEL
    #define TEST_PRINT_LEVEL 0
#endif

#ifdef STATS_USE_STDVEC
    #define STATS_TEST_STDVEC_FEATURES
#endif

#if defined(STATS_USE_ARMA) || defined(STATS_USE_BLAZE) || defined(STATS_USE_EIGEN)
    #define STATS_TEST_MATRIX_FEATURES
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    #if defined(STATS_USE_ARMA)
        #define mat_obj arma::mat
    #elif defined(STATS_USE_BLAZE)
        #define mat_obj blaze::DynamicMatrix<double>
    #else
        #define mat_obj Eigen::MatrixXd
    #endif
#endif

//
// switch between d/p (0) and q (1) cases (log_form input)

#if STATS_TEST_INPUT_TYPE == 0
    #ifndef TEST_STRIP_FN_ARGS
        #define TEST_STRIP_FN_ARGS(fn,x,lf,args...) fn(x,args,lf)
    #endif
    #ifndef TEST_PRINT_LOG_INPUT
        #define TEST_PRINT_LOG_INPUT(lf) << "," << ((lf) ? "true" : "false")
    #endif
#else
    #ifndef TEST_STRIP_FN_ARGS
        #define TEST_STRIP_FN_ARGS(fn,x,lf,args...) fn(x,args)
    #endif
    #ifndef TEST_PRINT_LOG_INPUT
        #define TEST_PRINT_LOG_INPUT(lf) 
    #endif
#endif

//
// printing pass

template<typename T1, typename T2, typename T3>
inline
void
print_test_pass(std::string fn_name, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_val, const T1 err_val, 
                const T2 x, const T3 par_1, const bool log_form)
{
    STATS_UNUSED_PAR(log_form);

    std::cout << "[\033[32mOK\033[0m] ";
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setprecision(print_precision_1) << fn_name
              << "(" << x << "," << par_1
              TEST_PRINT_LOG_INPUT(log_form) << ") = "
              << std::setprecision(print_precision_2) << f_val << "\n";

    if (print_level > 1 && !std::isnan(err_val))
        std::cout << "    - error value = " << err_val << ".\n";

    std::cout << std::endl;
}

template<typename T1, typename T2, typename T3, typename T4>
inline
void
print_test_pass(std::string fn_name, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_val, const T1 err_val, 
                const T2 x, const T3 par_1, const T4 par_2, const bool log_form)
{
    STATS_UNUSED_PAR(log_form);

    std::cout << "[\033[32mOK\033[0m] ";
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setprecision(print_precision_1) << fn_name
              << "(" << x << "," << par_1 << "," << par_2
              TEST_PRINT_LOG_INPUT(log_form) << ") = "
              << std::setprecision(print_precision_2) << f_val << "\n";

    if (print_level > 1 && !std::isnan(err_val))
        std::cout << "    - error value = " << err_val << ".\n";

    std::cout << std::endl;
}

//
// printing fail

template<typename T1, typename T2, typename T3>
inline
void
print_test_fail(std::string fn_name, int test_number, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_val, const T1 expected_val, 
                const T2 x, const T3 par_1, const bool log_form)
{
    STATS_UNUSED_PAR(print_level);
    STATS_UNUSED_PAR(print_precision_1);
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cerr << "\033[31m Test failed!\033[0m\n";
    std::cerr << "  - Test number: " << test_number << "\n";
    std::cerr << "  - Function Call:  " << fn_name
              << "(" << x << "," << par_1
              TEST_PRINT_LOG_INPUT(log_form) << ");\n";
    std::cerr << "  - Expected value: " << expected_val << "\n";
    std::cerr << "  - Actual value:   " << f_val << "\n";
    std::cerr << std::endl;

    throw std::runtime_error("test fail");
}

template<typename T1, typename T2, typename T3, typename T4>
inline
void
print_test_fail(std::string fn_name, int test_number, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_val, const T1 expected_val, 
                const T2 x, const T3 par_1, const T4 par_2, const bool log_form)
{
    STATS_UNUSED_PAR(print_level);
    STATS_UNUSED_PAR(print_precision_1);
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cerr << "\033[31m Test failed!\033[0m\n";
    std::cerr << "  - Test number: " << test_number << "\n";
    std::cerr << "  - Function Call:  " << fn_name
              << "(" << x << "," << par_1 << "," << par_2
              TEST_PRINT_LOG_INPUT(log_form) << ");\n";
    std::cerr << "  - Expected value: " << expected_val << "\n";
    std::cerr << "  - Actual value:   " << f_val << "\n";
    std::cerr << std::endl;

    throw std::runtime_error("test fail");
}

template<typename T>
inline
stats::return_t<T>
log_if(const T x, const bool log_form)
{
    return( log_form ? std::log(x) : x );
}

//
// macros

#define STATS_TEST_EXPECTED_VAL(fn_eval, val_inp, expected_val,                                     \
                                log_form, args...)                                                  \
{                                                                                                   \
    ++test_number;                                                                                  \
    std::string fn_name = #fn_eval;                                                                 \
                                                                                                    \
    auto check_val = log_if(expected_val,log_form);                                                 \
                                                                                                    \
    auto f_val = TEST_STRIP_FN_ARGS(stats::fn_eval,val_inp,log_form,args);                          \
    auto err_val = std::abs(f_val - check_val) / (1 + std::abs(check_val));                         \
                                                                                                    \
    bool test_success = false;                                                                      \
                                                                                                    \
    if (std::isnan(expected_val) && std::isnan(f_val)) {                                            \
        test_success = true;                                                                        \
    } else if(!std::isnan(f_val) && std::isinf(f_val) && f_val == check_val) {                      \
        test_success = true;                                                                        \
    } else if(err_val < err_tol) {                                                                  \
        test_success = true;                                                                        \
    } else {                                                                                        \
        print_test_fail(fn_name,test_number,print_level,print_precision_1,print_precision_2,        \
                        f_val,check_val,val_inp,args,log_form);                                     \
    }                                                                                               \
                                                                                                    \
    if (test_success && print_level > 0)                                                            \
    {                                                                                               \
        print_test_pass(fn_name,print_level,print_precision_1,print_precision_2,                    \
                        f_val,err_val,val_inp,args,log_form);                                       \
    }                                                                                               \
}

#define STATS_TEST_EXPECTED_QUANT_VAL(fn_eval, val_inp, expected_val, args...)                      \
{                                                                                                   \
    STATS_TEST_EXPECTED_VAL(fn_eval, val_inp, expected_val, false, args)                            \
}

//
// matrix tests
//

#define MATOPS stats::mat_ops

//
// printing pass

template<typename T1, typename T2, typename T3>
inline
void
print_mat_test_pass(std::string fn_name, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_vals, const double err_val, 
                const T2 x, const T3 par_1, const bool log_form)
{
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cout << "[\033[32mOK\033[0m] ";
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setprecision(print_precision_1) << fn_name
              << "(X" << "," << par_1
              TEST_PRINT_LOG_INPUT(log_form) << ") = \n";
              MATOPS::cout_output(f_vals);

    if (print_level > 1) {
        std::cout << "     where X =\n";
        MATOPS::cout_output(x);
        std::cout << "    - error value = " << err_val << ".\n";
    }

    std::cout << std::endl;
}


template<typename T1, typename T2, typename T3, typename T4>
inline
void
print_mat_test_pass(std::string fn_name, const int print_level, 
                int print_precision_1, int print_precision_2,
                const T1 f_vals, const double err_val, 
                const T2 x, const T3 par_1, const T4 par_2, const bool log_form)
{
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cout << "[\033[32mOK\033[0m] ";
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setprecision(print_precision_1) << fn_name
              << "(X" << "," << par_1 << "," << par_2
              TEST_PRINT_LOG_INPUT(log_form) << ") = \n";
              MATOPS::cout_output(f_vals);

    if (print_level > 1) {
        std::cout << "     where X =\n";
        MATOPS::cout_output(x);
        std::cout << "    - error value = " << err_val << ".\n";
    }

    std::cout << std::endl;
}

//
// printing fail

template<typename T1, typename T2, typename T3>
inline
void
print_mat_test_fail(std::string fn_name, std::string mtype, int test_number, 
                    const int print_level, int print_precision_1, int print_precision_2,
                    const T1 f_vals, const T1 exp_vals, 
                    const T2 x, const T3 par_1, const bool log_form)
{
    STATS_UNUSED_PAR(print_level);
    STATS_UNUSED_PAR(print_precision_1);
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cerr << "\033[31m Vector/Matrix test failed!\033[0m\n";
    std::cerr << "  - Input class: " << mtype << "\n";
    std::cerr << "  - Test number: " << test_number << "\n";
    std::cerr << "  - Input values:\n";
    MATOPS::cerr_output(x);
    std::cerr << "  - Function Call:  " << fn_name
              << "(.," << par_1
              TEST_PRINT_LOG_INPUT(log_form) << ");\n";
    std::cerr << "  - Expected values:\n";
    MATOPS::cerr_output(exp_vals);
    std::cerr << "  - Actual values:\n";
    MATOPS::cerr_output(f_vals);
    std::cerr << std::endl;

    throw std::runtime_error("test fail");
}

template<typename T1, typename T2, typename T3, typename T4>
inline
void
print_mat_test_fail(std::string fn_name, std::string mtype, int test_number, 
                    const int print_level, int print_precision_1, int print_precision_2,
                    const T1 f_vals, const T1 exp_vals, 
                    const T2 x, const T3 par_1, const T4 par_2, const bool log_form)
{
    STATS_UNUSED_PAR(print_level);
    STATS_UNUSED_PAR(print_precision_1);
    STATS_UNUSED_PAR(print_precision_2);
    STATS_UNUSED_PAR(log_form);

    std::cerr << "\033[31m Vector/Matrix test failed!\033[0m\n";
    std::cerr << "  - Input class: " << mtype << "\n";
    std::cerr << "  - Test number: " << test_number << "\n";
    std::cerr << "  - Input values:\n";
    MATOPS::cerr_output(x);
    std::cerr << "  - Function Call:  " << fn_name
              << "(.," << par_1 << "," << par_2
              TEST_PRINT_LOG_INPUT(log_form) << ");\n";
    std::cerr << "  - Expected values:\n";
    MATOPS::cerr_output(exp_vals);
    std::cerr << "  - Actual values:\n";
    MATOPS::cerr_output(f_vals);
    std::cerr << std::endl;

    throw std::runtime_error("test fail");
}

//

#define STATS_TEST_EXPECTED_MAT(fn_eval, vals_inp, exp_vals,                                        \
                                mtype, log_form, args...)                                           \
{                                                                                                   \
    ++test_number;                                                                                  \
    std::string fn_name = #fn_eval;                                                                 \
                                                                                                    \
    mtype f_vals = TEST_STRIP_FN_ARGS(stats::fn_eval,vals_inp,log_form,args);                       \
                                                                                                    \
    double err_val = 0.0;                                                                           \
                                                                                                    \
    if (log_form) {                                                                                 \
        mtype log_exp_vals = MATOPS::log(exp_vals);                                                 \
        err_val = MATOPS::sum_absdiff(f_vals,log_exp_vals);                                         \
    } else {                                                                                        \
        err_val = MATOPS::sum_absdiff(f_vals,exp_vals);                                             \
    }                                                                                               \
                                                                                                    \
    err_val /= MATOPS::n_elem(vals_inp);                                                            \
                                                                                                    \
    bool test_success = false;                                                                      \
                                                                                                    \
    if(err_val < err_tol) {                                                                         \
        test_success = true;                                                                        \
    } else {                                                                                        \
        print_mat_test_fail(fn_name,TEST_STRIP_MACRO(mtype),test_number,                            \
                            print_level,print_precision_1,print_precision_2,                        \
                            f_vals,exp_vals,vals_inp,args,log_form);                                \
    }                                                                                               \
                                                                                                    \
    if (test_success && print_level > 0)                                                            \
    {                                                                                               \
        print_mat_test_pass(fn_name,print_level,print_precision_1,print_precision_2,                \
                            f_vals,err_val,vals_inp,args,log_form);                                 \
    }                                                                                               \
}

#define STATS_TEST_EXPECTED_QUANT_MAT(fn_eval, vals_inp, exp_vals, mtype, args...)                  \
{                                                                                                   \
    STATS_TEST_EXPECTED_MAT(fn_eval, vals_inp, exp_vals, mtype, false, args)                        \
}

//

void finish_print_line(int k)
{
    for (int i=0; i < 80 - k; ++i) {
        printf(" ");
    }
    printf("#");
}

void print_begin(std::string fn_name)
{
    STATS_UNUSED_PAR(fn_name);
}

void print_final(std::string fn_name, int test_number)
{
    std::cout << 
        "################################################################################\n" <<
        "#                                TESTS SUMMARY                                 #\n";
    
    //

    std::cout << 
        "#  - Test suite: " << fn_name;
        finish_print_line(14 + int(fn_name.length()) + 4);
    std::cout << std::endl;

    //

    std::cout << 
        "#  - Number of tests: " << test_number;
        finish_print_line(20 + (test_number > 9 ? 1 : 0) + 4);
    std::cout << std::endl;

    //

    std::cout << 
        "#                                   [\033[32mPASS\033[0m]                                     #\n" <<
        "################################################################################\n";
    //

    std::cout << std::endl;
}
