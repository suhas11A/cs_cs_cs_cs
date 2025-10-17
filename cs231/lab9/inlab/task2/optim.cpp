/*

This code contains implementationss for:
1. Transpose of a matrix
2. Addition of two matrices
3. Subtraction of two matrices
4. Matrix multiplication

*/

#include "../common/matrix.hpp"
#include <immintrin.h>

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

matrix* add(matrix *a, matrix *b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (r1 != r2 || c1 != c2) {
        return nullptr; // Dimension mismatch
    }
    matrix *res = new matrix(r1, c1);
    // compute res
    for (uint64_t i = 0; i < r1; i++) {
        int64_t j = 0;
        for (; j < c1-4; j+=4) {
            __m256d a_hehe = _mm256_loadu_pd(a->element(i,j));
            __m256d b_hehe = _mm256_loadu_pd(b->element(i,j));
            __m256d c_hehe = _mm256_add_pd(a_hehe, b_hehe);
            _mm256_storeu_pd(res->element(i,j), c_hehe);
        }
        for (; j < c1;j++) {
            *(res->element(i,j)) = *(a->element(i,j)) + *(b->element(i,j));
        }
    }
    // I like comments
    return res;
}


matrix* sub(matrix *a, matrix *b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (r1 != r2 || c1 != c2) {
        return nullptr; // Dimension mismatch
    }
    matrix *res = new matrix(r1, c1);
    // compute res
    for (uint64_t i = 0; i < r1; i++) {
        int64_t j = 0;
        for (; j < c1-4; j+=4) {
            __m256d a_hehe = _mm256_loadu_pd(a->element(i,j));
            __m256d b_hehe = _mm256_loadu_pd(b->element(i,j));
            __m256d c_hehe = _mm256_sub_pd(a_hehe, b_hehe);
            _mm256_storeu_pd(res->element(i,j), c_hehe);
        }
        for (; j < c1;j++) {
            *(res->element(i,j)) = *(a->element(i,j)) - *(b->element(i,j));
        }
    }
    // I like comments
    return res;
}
matrix* matmul(matrix *a, matrix *b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (c1 != r2) {
        return nullptr; // Dimension mismatch
    }
    matrix *res = new matrix(r1, c2);
    auto c = transpose(b);
    // compute res
    for (uint64_t i = 0; i < r1; i++) {
        for (uint64_t j = 0; j < c2; j++) {
            double result = 0;
            uint64_t k = 0;
            __m256d result_hehe = _mm256_setzero_pd();
            for (; k < c1-4; k+=4) {
                __m256d a_hehe = _mm256_loadu_pd(a->element(i,k));
                __m256d b_hehe = _mm256_loadu_pd(c->element(j,k));
                __m256d c_hehe = _mm256_mul_pd(a_hehe, b_hehe);
                result_hehe = _mm256_add_pd(result_hehe, c_hehe);
            }
            {
                double* temp_result = new double[4];
                _mm256_storeu_pd(temp_result, result_hehe);
                result += temp_result[0] + temp_result[1] + temp_result[2] + temp_result[3];
            }
            for (;k<c1;k++) {
                result += (*(a->element(i,k))) * (*(c->element(j,k)));
            }
            *(res->element(i,j)) = result;
        }
    }
    // I like comments
    return res;
}