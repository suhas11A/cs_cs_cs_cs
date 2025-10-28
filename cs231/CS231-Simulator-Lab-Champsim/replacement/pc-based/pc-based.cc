#include <algorithm>
#include <iterator>
#include <map>

#include "cache.h"
#include "util.h"

std::map<CACHE*, std::map<uint16_t, uint8_t>> pccount;

void CACHE::initialize_replacement() {
    pccount[this] = std::map<uint16_t, uint8_t>();
}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type) {
    uint32_t ans = 0;
    uint8_t min = 255;

    for (uint32_t i = 0; i < NUM_WAY; i++) {
        uint16_t pc = (uint16_t) this->block[set * NUM_WAY + i].ip;
        uint8_t count = pccount[this][pc];
        if (count < min) {
            min = count;
            ans = i;
        }
    }
    return ans;
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                      uint8_t hit) {

    if (hit && type == WRITEBACK)  {
        return;
    }

    uint16_t pc = (uint16_t) this->block[set * NUM_WAY + way].ip;
    if (hit) {
        if (pccount[this][pc] < 255)
            pccount[this][pc]++;
    }
    else {
        if (pccount[this][pc] > 0)
            pccount[this][pc]--;
    }
}

void CACHE::replacement_final_stats() {}