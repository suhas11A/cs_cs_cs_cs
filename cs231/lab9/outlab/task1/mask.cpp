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
    // FILL SOLUTION HERE
    postAdd = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(postAdd - preAdd).count();
    cout << "Output AVX = " << layer2OutAVX << " duration = " << duration << endl;

}