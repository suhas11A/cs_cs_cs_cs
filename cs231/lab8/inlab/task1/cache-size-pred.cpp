#include <bits/stdc++.h>
#include <x86intrin.h>

//Demo function to show use of rdtsc
double measure_time_rdtsc(int trials, int kilobytes) {
    int32_t size_of_array = (kilobytes*250);
    int32_t * dummy=new int32_t[size_of_array];
    // Measure using rdtsc with serialization
    uint64_t total_cycles = 0;
    int32_t counter = 0;
    for (int32_t t = 0; t < trials; t++) {
        uint32_t cycles_high, cycles_low;
        asm volatile (
            "cpuid\n"      
            "rdtsc\n"
            : "=a"(cycles_low), "=d"(cycles_high)
            :: "rbx","rcx"
        );
        uint64_t start = ((uint64_t)cycles_high << 32) | cycles_low;

        /*
        Put whatever code you want to measure execution time of here
        Dummy memory access given for reference
        */
        for (int32_t j=0;j<size_of_array;j+=16) {
            int32_t a = dummy[j];
        }

        asm volatile (
            "rdtscp\n"      
            "mov %%edx, %0\n"
            "mov %%eax, %1\n"
            "cpuid\n"
            : "=r"(cycles_high), "=r"(cycles_low)
            :: "rax","rbx","rcx","rdx"
        );
        uint64_t end = ((uint64_t)cycles_high << 32) | cycles_low;
        total_cycles += (end - start);
    }

    return (double(total_cycles) / (trials * (( double (size_of_array))/16))) ; // cycles per access
}


int main(){
    std::cout << "Estimating cache sizes (cycles per access)...\nSize (KB) Cycles/access\n---------------------------\n";
    for (float size = 1;size < 15000;size+=100) {
        if (size<10) continue;
        std::cout << size << " " << measure_time_rdtsc(3000, size) <<  std::endl;
    }
}