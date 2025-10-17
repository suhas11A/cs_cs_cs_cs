#include "vector.hpp"
#include <immintrin.h>  // for AVX

vector* vecAdd(vector* v1, vector* v2) {
    if (v1->dimension() != v2->dimension()) {
        return nullptr;
    }
    uint64_t dim = v1->dimension();
    vector* result = new vector(dim);
    uint64_t i = 0;
    for (; i < dim-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(v1->element(i));
        __m256d v2_hehe = _mm256_loadu_pd(v2->element(i));
        __m256d v3_hehe = _mm256_add_pd(v1_hehe, v2_hehe);
        _mm256_storeu_pd(result->element(i), v3_hehe);
    }
    for (;i<dim;i++) {
        *(result->element(i)) = *(v1->element(i)) + *(v2->element(i));
    }
    return result;
}

vector* vecSub(vector* v1, vector* v2) {
    if (v1->dimension() != v2->dimension()) {
        return nullptr;
    }
    uint64_t dim = v1->dimension();
    vector* result = new vector(v1->dimension());
    uint64_t i = 0;
    for (; i < dim-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(v1->element(i));
        __m256d v2_hehe = _mm256_loadu_pd(v2->element(i));
        __m256d v3_hehe = _mm256_sub_pd(v1_hehe, v2_hehe);
        _mm256_storeu_pd(result->element(i), v3_hehe);
    }
    for (;i<dim;i++) {
        *(result->element(i)) = *(v1->element(i)) - *(v2->element(i));
    }
    return result;
}

vector* vecElementMul(vector* v1, vector* v2) {
    if (v1->dimension() != v2->dimension()) {
        return nullptr;
    }
    uint64_t dim = v1->dimension();
    vector* result = new vector(v1->dimension());
    uint64_t i = 0;
    for (; i < dim-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(v1->element(i));
        __m256d v2_hehe = _mm256_loadu_pd(v2->element(i));
        __m256d v3_hehe = _mm256_mul_pd(v1_hehe, v2_hehe);
        _mm256_storeu_pd(result->element(i), v3_hehe);
    }
    for (;i<dim;i++) {
        *(result->element(i)) = (*(v1->element(i))) * (*(v2->element(i)));
    }
    return result;
}

vector* vecElementDiv(vector* v1, vector* v2) {
    if (v1->dimension() != v2->dimension()) {
        return nullptr;
    }
    uint64_t dim = v1->dimension();
    vector* result = new vector(v1->dimension());
    uint64_t i = 0;
    for (; i < dim-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(v1->element(i));
        __m256d v2_hehe = _mm256_loadu_pd(v2->element(i));
        __m256d v3_hehe = _mm256_div_pd(v1_hehe, v2_hehe);
        _mm256_storeu_pd(result->element(i), v3_hehe);
    }
    for (;i<dim;i++) {
        *(result->element(i)) = (*(v1->element(i))) / (*(v2->element(i)));
    }
    return result;
}

double dotProduct(vector* v1, vector* v2) {
    if (v1->dimension() != v2->dimension()) {
        return -1.0;
    }
    uint64_t dim = v1->dimension();
    double result = 0;
    uint64_t i = 0;
    __m256d result_hehe = _mm256_setzero_pd();
    for (; i < dim-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(v1->element(i));
        __m256d v2_hehe = _mm256_loadu_pd(v2->element(i));
        __m256d v3_hehe = _mm256_mul_pd(v1_hehe, v2_hehe);
        result_hehe = _mm256_add_pd(result_hehe, v3_hehe);
    }
    {
        vector* temp_result = new vector(4);
        _mm256_storeu_pd(temp_result->element(0), result_hehe);
        result += *(temp_result->element(0)) + *(temp_result->element(1)) + *(temp_result->element(2)) + *(temp_result->element(3));
    }
    for (;i<dim;i++) {
        result += (*(v1->element(i))) * (*(v2->element(i)));
    }
    return result;
}