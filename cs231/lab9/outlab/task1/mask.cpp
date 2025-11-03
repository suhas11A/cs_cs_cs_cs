#include <iostream>
#include <immintrin.h>
#include <chrono>
#include "vector.hpp"
using namespace std;

/*
Layer 1:
n cells, each have to perform y[i] = sum_j[max(0, w[i,j] * x[j])] where x[j] is jth dimensional element of input, 
                                                                        w[i,j] is jth dimensional weight of ith cell,

Layer 2:
1 cell, has to perform out = summation_[i=1; i < NUM_CELL; i++](max(y[i], (y[i-1] + 1)* y[i]))

You may assume INPUT_DIM and NUM_CELL are multiples of 4.
*/

#define NUM_CELL 1000
#define INPUT_DIM 100000

vector** layer1CellWeights;  
vector layer1Outs(NUM_CELL);
vector layer1OutsAVX(NUM_CELL + 4); // why?
vector input(INPUT_DIM);

int main () {
    
    srand(42);
    for (int i=0; i < INPUT_DIM; i++) {
        *(input.element(i)) = rand() % 10 - rand() % 10;
    }
    layer1CellWeights = new vector*[NUM_CELL];
    for (int i=0; i < NUM_CELL; i++) {
        layer1CellWeights[i] = new vector(INPUT_DIM);
        for (int j=0; j < INPUT_DIM; j++) {
            *(layer1CellWeights[i]->element(j)) = rand() % 10 - rand() % 10;
        }
    }

    // Naive Implementation
    auto preAdd = std::chrono::high_resolution_clock::now();
    for (int i=0; i < NUM_CELL; i++) {
        
        *(layer1Outs.element(i)) = 0;
        for (int j=0; j < INPUT_DIM; j++) {
            *(layer1Outs.element(i)) += max(0.0,(*(layer1CellWeights[i]->element(j))) * (*(input.element(j))));
        }

    }
    double layer2Out = 0;
    for (int i=1; i < NUM_CELL; i++) {
        double val1 = *(layer1Outs.element(i));
        double val2 = (*(layer1Outs.element(i-1)) + 1) * (*(layer1Outs.element(i)));
        layer2Out += max(val1, val2);
    }
    auto postAdd = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(postAdd - preAdd).count();
    cout << "Output = " << layer2Out << " duration = " << duration << endl;

    // AVX2 Implementation
    preAdd = std::chrono::high_resolution_clock::now();
    double layer2OutAVX = 0;
    __m256d zero_hehe = _mm256_setzero_pd();
    for (int i=0; i < NUM_CELL; i++) {
        *(layer1OutsAVX.element(i)) = 0;
        int j=0;
        __m256d result_hehe = _mm256_setzero_pd();
        for (; j < INPUT_DIM-4; j+=4) {
            __m256d v1_hehe = _mm256_loadu_pd(layer1CellWeights[i]->element(j));
            __m256d v2_hehe = _mm256_loadu_pd(input.element(j));
            __m256d v4_hehe = _mm256_mul_pd(v1_hehe, v2_hehe);
            __m256d v3_hehe = _mm256_max_pd(zero_hehe, v4_hehe);
            result_hehe = _mm256_add_pd(result_hehe, v3_hehe);
        }
        {    vector* temp_result = new vector(4);
            _mm256_storeu_pd(temp_result->element(0), result_hehe);
            *(layer1OutsAVX.element(i)) += *(temp_result->element(0)) + *(temp_result->element(1)) + *(temp_result->element(2)) + *(temp_result->element(3));
        }
        for (;j< INPUT_DIM; j++) {
            *(layer1OutsAVX.element(i)) += max(0.0,(*(layer1CellWeights[i]->element(j))) * (*(input.element(j))));
        }
    }
    int i=1;
    __m256d result_hehe = _mm256_setzero_pd();
    for (; i < NUM_CELL-4; i+=4) {
        __m256d v1_hehe = _mm256_loadu_pd(layer1OutsAVX.element(i));
        __m256d v2_hehe = _mm256_loadu_pd(layer1OutsAVX.element(i-1));
        __m256d v4_hehe = _mm256_loadu_pd(layer1OutsAVX.element(i));
        __m256d v5_hehe = _mm256_fmadd_pd(v2_hehe, v4_hehe, v4_hehe);
        __m256d v6_hehe = _mm256_max_pd(v1_hehe, v5_hehe);
        result_hehe = _mm256_add_pd(result_hehe, v6_hehe);
    }
    {    vector* temp_result = new vector(4);
        _mm256_storeu_pd(temp_result->element(0), result_hehe);
        layer2OutAVX += *(temp_result->element(0)) + *(temp_result->element(1)) + *(temp_result->element(2)) + *(temp_result->element(3));
    }
    for (; i < NUM_CELL; i++) {
        double val1 = *(layer1OutsAVX.element(i));
        double val2 = (*(layer1OutsAVX.element(i-1)) + 1) * (*(layer1OutsAVX.element(i)));
        layer2OutAVX += max(val1, val2);
    }
    // FILL SOLUTION HERE
    postAdd = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(postAdd - preAdd).count();
    cout << "Output AVX = " << layer2OutAVX << " duration = " << duration << endl;

}