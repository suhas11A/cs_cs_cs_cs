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
    for (uint64_t i = 0; i < r1; i++) {
        for (uint64_t j = 0; j < c1; j++) {
            double my_temp = *(a->element(i, j));
            __m256d one_hehe = _mm256_set1_pd(my_temp);
            for (uint64_t p = 0; p < r2; p++) {
                double* bptr   = b->element(p, 0);
                double* resptr = res->element(i * r2 + p, j * c2);
                uint64_t q = 0;
                for (; q <= c2-4; q+=4) {
                    __m256d v1_hehe = _mm256_loadu_pd(bptr + q);
                    __m256d v2_hehe = _mm256_mul_pd(v1_hehe, one_hehe);
                    _mm256_storeu_pd(resptr + q, v2_hehe);
                }
                for (; q < c2; q++) {
                    resptr[q] = my_temp * bptr[q];
                }
            }
        }
    }
    // code ends
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
    // for tile (i,j) its k = -(r2 - 1)/2 to (r2 - 1)/2 and l = -(c2 - 1)/2 to (c2 - 1)/2
    // res(i,j) = sum(a(i+k, j+l) * b(k,l))
    for (int i = (r2 - 1)/2; i < r1 - (r2 - 1)/2; i++) {
        for (int j = (c2 - 1)/2; j < c1 - (c2 - 1)/2; j++) {
            double sum = 0.0;
            __m256d result_hehe = _mm256_setzero_pd();
            for (int k = -((int64_t)r2 - 1)/2; k <= ((int64_t)r2 - 1)/2; k++) {
                int l = -((int64_t)c2 - 1)/2;
                for (; l <= ((int64_t)c2 - 1)/2 - 3; l+=4) {
                    __m256d v1_hehe = _mm256_loadu_pd(a->element(i + k, j + l));
                    __m256d v2_hehe = _mm256_loadu_pd(b->element(k + (r2 - 1)/2, l + (c2 - 1)/2));
                    __m256d v3_hehe = _mm256_mul_pd(v1_hehe, v2_hehe);
                    result_hehe = _mm256_add_pd(result_hehe, v3_hehe);
                }
                for (; l <= ((int64_t)c2 - 1)/2; l++) {
                    sum += (*(a->element(i + k, j + l))) * (*(b->element(k + (r2 - 1)/2, l + (c2 - 1)/2)));
                }
            }
            {    double* temp_result = new double[4];
                _mm256_storeu_pd(temp_result, result_hehe);
                sum += temp_result[0] + temp_result[1] + temp_result[2] + temp_result[3];
            }
            *(res->element(i, j)) = sum;
        }
    }
    // Borders zero padded by default
    return res;
}

matrix* transpose(matrix *a) {
    auto [r, c] = a->size();
    matrix *res = new matrix(c, r);
    for (uint64_t i = 0; i < r; i++) {
        for (uint64_t j = 0; j < c; j++) {
            *(res->element(j, i)) = *(a->element(i, j));
        }
    }
    return res;
}

matrix* weirdMul(matrix* a, matrix* b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (c1 != r2) {
        return nullptr; // Dimension mismatch
    }
    matrix* fake_a = new matrix(r1,c1);
    matrix* fake_b = transpose(b);
    for (uint64_t i = 0; i < r1; ++i) {
        for (uint64_t k = 0; k < c1; ++k) {
            double val = *(a->element(i, k));
            *(fake_a->element(i, k)) = *(a->element(i, k)) - ((val <= 0.5) ? 1 : 0);
        }
    }
    matrix* res = new matrix(r1, c2);
    // compute res
    for (uint64_t i = 0; i < r1; i++) {
        for (uint64_t j = 0; j < c2; j++) {
            double result = 0;
            uint64_t k = 0;
            __m256d result_hehe = _mm256_setzero_pd();
            for (; k < c1-4; k+=4) {
                __m256d a_hehe = _mm256_loadu_pd(fake_a->element(i,k));
                __m256d b_hehe = _mm256_loadu_pd(fake_b->element(j,k));
                __m256d c_hehe = _mm256_mul_pd(a_hehe, b_hehe);
                result_hehe = _mm256_add_pd(result_hehe, c_hehe);
            }
            {
                double* temp_result = new double[4];
                _mm256_storeu_pd(temp_result, result_hehe);
                result += temp_result[0] + temp_result[1] + temp_result[2] + temp_result[3];
            }
            for (;k<c1;k++) {
                result += (*(fake_a->element(i,k))) * (*(fake_b->element(j,k)));
            }
            *(res->element(i,j)) = result;
        }
    }
    // code ends
    return res;
}