#ifndef SAMPLER_H
#define SAMPLER_H

#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <cstdint>
#include <numeric>

class DeadBlockPredictor {
    private:
        static const int TABLES = 3;
        static const int ENTRIES = 4096;
        static const int THRESHOLD = 8;
        std::vector<std::vector<int>> counters;

        inline uint32_t hash1(uint32_t x)const {
            x ^= (x >> 16);
            x *= 0x7feb352d;
            x ^= (x >> 15);
            return x & 0xFFF;  // 12-bit index (0–4095)
        }

        inline uint32_t hash2(uint32_t x) const{
            x ^= (x >> 13);
            x *= 0x846ca68b;
            x ^= (x >> 16);
            return x & 0xFFF;  
        }

        inline uint32_t hash3(uint32_t x) const{
            x ^= (x << 7);
            x *= 0x165667b1;
            x ^= (x >> 11);
            return x & 0xFFF;
        }

        std::map<uint32_t,uint32_t> num_dead;
        std::map<uint32_t,uint32_t> num_live;

        inline void inc_counter(int& c) {
            if (c < 3) c++;
        }

        inline void dec_counter(int& c) {
            if (c > 0) c--;
        }
    public:
        DeadBlockPredictor() : counters(TABLES, std::vector<int>(ENTRIES, 0)) {}

        bool predict_to_be_dead(uint32_t signature) {
            // Compute indices in each table
            uint32_t i1 = hash1(signature);
            uint32_t i2 = hash2(signature);
            uint32_t i3 = hash3(signature);

            int c1 = counters[0][i1];
            int c2 = counters[1][i2];
            int c3 = counters[2][i3];

            int confidence_sum = c1 + c2 + c3;

            // Predict dead if sum of 3 counters >= THRESHOLD (8)
            return (confidence_sum >= THRESHOLD);
        }

        void update(uint32_t signature, bool dead) {
            // Track stats (optional, but harmless)
            if (dead)
                num_dead[signature]++;
            else
                num_live[signature]++;

            uint32_t i1 = hash1(signature);
            uint32_t i2 = hash2(signature);
            uint32_t i3 = hash3(signature);

            int& c1 = counters[0][i1];
            int& c2 = counters[1][i2];
            int& c3 = counters[2][i3];

            if (dead) {
                // block turned out to be dead: increase confidence
                inc_counter(c1);
                inc_counter(c2);
                inc_counter(c3);
            } else {
                // block was live (got a hit before eviction): decrease confidence
                dec_counter(c1);
                dec_counter(c2);
                dec_counter(c3);
            }
        }
};
#endif 