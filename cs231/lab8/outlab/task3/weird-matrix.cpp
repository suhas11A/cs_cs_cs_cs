#include <iostream>
#include <cstdint>
#include <chrono>

volatile int accum = 0;

volatile int arr[1500];

volatile int m1[1500][1500];
volatile int m2[1500][1500];

int main() {

    srand(42); // seeds the randomness
    // first initialize the arr with random elements
    for (int i=0; i < 1500; i++) {
        arr[i] = rand() % 1500;
        for (int j=0; j < 1500; j++) {
            m1[i][j] = rand() % 100;
            m2[i][j] = rand() % 100;
        }
    }

    // naive time check
    auto preAdd = std::chrono::high_resolution_clock::now();
    accum = 0;
    for (int i=0; i < 1500; i++) {
        for (int j=0; j < 1500; j++) {
            if (arr[j] > 750) {
                // accum gets the dot product between ith column and jth column (say)
                int dotP = 0;
                for (int k=0; k < 1500; k++) {
                    dotP += m1[arr[k]][i] * m2[k][arr[j]];
                }
                accum += dotP;
            }
            else {
                // accum gets -dot product between jth column and ith column (say)
                int dotP = 0;
                for (int k=0; k < 1500; k++) {
                    dotP += m1[k][arr[j]] * m2[arr[k]][i];
                }
                accum -= dotP;
            }
        }
    }   
    auto postAdd = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(postAdd - preAdd).count();
    std::cout << "accum = " << accum << " time taken = " << duration << std::endl;

    preAdd = std::chrono::high_resolution_clock::now();
    accum = 0;
    // olala
    int n = 1500;
    int rs1[n] = {}; int rs2[n] = {};
    int sX[n] = {}; int sY[n] = {};
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            rs1[i] += m1[i][j];
            rs2[i] += m2[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        int a = rs1[arr[i]];
        int b = rs2[arr[i]];
        for (int j=0;j<n;j++) {
            sX[j] += m2[i][j]*a;
            sY[j] += m1[i][j]*b;
        }
    }
    for (int j=0;j<n;j++) {
        int tempo = arr[j];
        accum += (tempo>750 ? sX[tempo] : -sY[tempo]);
    }
    postAdd = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(postAdd - preAdd).count();
    std::cout << "accum = " << accum << " time taken = " << duration << std::endl;

}
