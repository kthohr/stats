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
#include <vector>

#include <iostream>
#include <iomanip>

//

#ifndef TEST_NAN
    #define TEST_NAN stats::STLIM<double>::quiet_NaN()
#endif

#ifndef TEST_POSINF
    #define TEST_POSINF stats::STLIM<double>::infinity()
#endif

#ifndef TEST_NEGINF
    #define TEST_NEGINF -stats::STLIM<double>::infinity()
#endif

//

#ifndef TEST_PRINT_LEVEL
    #define TEST_PRINT_LEVEL 0
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
        #define mat_obj Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>
    #endif
#endif

//
//

#define STATS_TEST_EXPECTED_VAL(fn_eval, val_inp, expected_val, test_number, err_tol,               \
                                print_verbose, extra_space, print_precision_1, print_precision_2,   \
                                args...)                                                            \
{                                                                                                   \
    ++test_number;                                                                                  \
                                                                                                    \
    auto f_val = stats::fn_eval(val_inp,args);                                                      \
    auto err_val = std::abs(f_val - expected_val) / (1 + std::abs(expected_val));                   \
                                                                                                    \
    bool test_success = false;                                                                      \
                                                                                                    \
    if (std::isnan(expected_val) && std::isnan(f_val)) {                                            \
        test_success = true;                                                                        \
    } else if(!std::isnan(f_val) && std::isinf(f_val) && f_val == expected_val) {                   \
        test_success = true;                                                                        \
    } else if(err_val < err_tol) {                                                                  \
        test_success = true;                                                                        \
    } else {                                                                                        \
        std::cerr << "\033[31m Test fail!\033[0m\n";                                                \
        std::cerr << "  - Test number: " << test_number << "\n";                                    \
        std::cerr << "  - Input value:    " << val_inp << "\n";                                     \
        std::cerr << "  - Expected value: " << expected_val << "\n";                                \
        std::cerr << "  - Actual value:   " << f_val << "\n";                                       \
        std::cerr << std::endl;                                                                     \
        throw std::runtime_error("test fail");                                                      \
    }                                                                                               \
                                                                                                    \
    if (print_verbose)                                                                              \
    {                                                                                               \
        std::cout << std::setiosflags(std::ios::fixed)                                              \
                  << std::setprecision(print_precision_1) << #fn_eval                               \
                  << "(" << val_inp << ")" << extra_space << " = "                                  \
                  << std::setprecision(print_precision_2) << f_val << "\n";                         \
                                                                                                    \
        std::cout << "  - error value = " << err_val << ".";                                        \
                                                                                                    \
        std::cout << "\033[32m OK.\033[0m\n";                                                       \
        std::cerr << std::endl;                                                                     \
    }                                                                                               \
}

#define STATS_TEST_2PAR_EXPECTED_VAL(fn_eval, val_inp, expected_val, test_number,                   \
                                     par_1,par_2,log_form)                                          \
{                                                                                                   \
    ++test_number;                                                                                  \
                                                                                                    \
    auto f_val = stats::fn_eval(val_inp,par_1,par_2,log_form);                                      \
    auto err_val = std::abs(f_val - expected_val) / (1 + std::abs(expected_val));                   \
                                                                                                    \
    bool test_success = false;                                                                      \
                                                                                                    \
    if (std::isnan(expected_val) && std::isnan(f_val)) {                                            \
        test_success = true;                                                                        \
    } else if(!std::isnan(f_val) && std::isinf(f_val) && f_val == expected_val) {                   \
        test_success = true;                                                                        \
    } else if(err_val < err_tol) {                                                                  \
        test_success = true;                                                                        \
    } else {                                                                                        \
        std::cerr << "\033[31m Test failed!\033[0m\n";                                              \
        std::cerr << "  - Test number: " << test_number << "\n";                                    \
        std::cerr << "  - Function Call:  " << #fn_eval                                             \
                  << "(" << val_inp << "," << par_1 << "," << par_2                                 \
                  << "," << ((log_form) ? "true" : "false") << ");\n";                              \
        std::cerr << "  - Expected value: " << expected_val << "\n";                                \
        std::cerr << "  - Actual value:   " << f_val << "\n";                                       \
        std::cerr << std::endl;                                                                     \
        throw std::runtime_error("test fail");                                                      \
    }                                                                                               \
                                                                                                    \
    if (print_level > 0)                                                                            \
    {                                                                                               \
        std::cout << "[\033[32mOK\033[0m] ";                                                        \
        std::cout << std::setiosflags(std::ios::fixed)                                              \
                  << std::setprecision(print_precision_1) << #fn_eval                               \
                  << "(" << val_inp << "," << par_1 << "," << par_2                                 \
                  << "," << ((log_form) ? "true" : "false") << ") = "                               \
                  << std::setprecision(print_precision_2) << f_val << "\n";                         \
                                                                                                    \
        if (print_level > 1)                                                                        \
            std::cout << "    - error value = " << err_val << ".\n";                                \
                                                                                                    \
        std::cout << std::endl;                                                                     \
    }                                                                                               \
}

// #define STATS_TEST_2PAR_EXPECTED_VAL_VEC(fn_eval, vals_inp, expected_vals, test_number,          \
//                                          par_1,par_2,log_form)                                   \
// {                                                                                                   \
//     ++test_number;                                                                                  \
//                                                                                                     \
//     size_t n_elem = vals_inp.size();                                                                \
//                                                                                                     \
//     double err_val = 0.0;

//     for (size_t i=0; i < n_elem; ++i)
//     {
//         auto f_val = stats::fn_eval(vals_inp[i],par_1,par_2,log_form);                                     \
//         err_val += std::abs(f_val - expected_val[i]) / (1 + std::abs(expected_val[i]));                   \
//     }
//                                                                                                     \
//     bool test_success = false;                                                                      \
//                                                                                                     \
//     if (err_val < err_tol) {                                                                  \
//         test_success = true;                                                                        \
//     } else {                                                                                        \
//         std::cerr << "\033[31m Test failed!\033[0m\n";                                              \
//         std::cerr << "  - Test number: " << test_number << "\n";                                    \
//         std::cerr << "  - Function Call:  " << #fn_eval                                             \
//                   << "(" << val_inp << "," << par_1 << "," << par_2                                 \
//                   << "," << ((log_form) ? "true" : "false") << ");\n";                              \
//         std::cerr << "  - Expected value: " << expected_val << "\n";                                \
//         std::cerr << "  - Actual value:   " << f_val << "\n";                                       \
//         std::cerr << std::endl;                                                                     \
//         throw std::runtime_error("test fail");                                                      \
//     }                                                                                               \
//                                                                                                     \
//     if (print_level > 0)                                                                            \
//     {                                                                                               \
//         std::cout << "[\033[32mOK\033[0m] ";                                                        \
//         std::cout << std::setiosflags(std::ios::fixed)                                              \
//                   << std::setprecision(print_precision_1) << #fn_eval                               \
//                   << "(" << val_inp << "," << par_1 << "," << par_2                                 \
//                   << "," << ((log_form) ? "true" : "false") << ") = "                               \
//                   << std::setprecision(print_precision_2) << f_val << "\n";                         \
//                                                                                                     \
//         if (print_level > 1)                                                                        \
//             std::cout << "    - error value = " << err_val << ".\n";                                \
//                                                                                                     \
//         std::cout << std::endl;                                                                     \
//     }                                                                                               \
// }

//

void finish_print_line(int k)
{
    for (int i=0; i < 80 - k; ++i) {
        printf(" ");
    }
    printf("#");
}

void print_begin(std::string fn_name, int test_number)
{
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


// }

