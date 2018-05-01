# StatsLib | Tests

This directory contains test files for the StatsLib C++ library.

## Instructions

From the current directory, run
```bash
./setup
```
Then change directory to the desired test suite and invoke the usual `./configure && make` combination. 

For example,
```bash
cd dens
./configure -p
make
./dnorm.test
```
There are several configure options available (`./configure -h`):
* `-c` a coverage build (used with Codecov)
* `-g` a debugging build (optimization flags set to: `-O0 -g`)
* `-h` print help
* `-i` install path; default: build directory.
* `-l` enable wrappers for a linear algebra library; for example, `-l arma`, `-l blaze`, or `-l eigen`
* `-m` specify the BLAS and Lapack libraries to link against; for example, `-m "-lopenblas"` or `-m "-framework Accelerate"`
* `-o` compiler optimization options; defaults to `-O3 -march=native -ffp-contract=fast`
* `-p` enable OpenMP parallelization features
