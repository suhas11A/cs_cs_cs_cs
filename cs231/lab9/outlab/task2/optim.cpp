/*

This file contains implementationss for:
1. Outer product of 2 matrices
2. Convolution of 2 matrices
3. Wierd multiplication of a matrix

*/

#include "../common/matrix.hpp"
#include <cmath>
#include <immintrin.h>

matrix* outer(matrix *a, matrix *b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    matrix *res = new matrix(r1 * r2, c1 * c2);
    // compute res
    return res;
}

matrix* convolve(matrix* a, matrix* b) {
    // output matrix dim must be same as a-> dim
    // and a->dim must be greater than b->dim
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (r1 < r2 || c1 < c2) {
        return nullptr; // Dimension mismatch   
    }
    if (r2 % 2 == 0 || c2 % 2 == 0) {
        return nullptr; // Kernel dimensions must be odd
    }
    matrix* res = new matrix(r1, c1);
    // compute res
    return res;
}

matrix* weirdMul(matrix* a, matrix* b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (c1 != r2) {
        return nullptr; // Dimension mismatch
    }
    matrix* res = new matrix(r1, c2);
    // compute res
    return res;
}