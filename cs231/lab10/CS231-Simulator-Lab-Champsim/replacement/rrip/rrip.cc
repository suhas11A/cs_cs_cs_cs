#include <algorithm>
#include <iterator>
#include <map>

#include "cache.h"
#include "util.h"

std::map<CACHE*,std::vector<uint8_t>> rripVal;

void CACHE::initialize_replacement() {
    rripVal[this] = std::vector<uint8_t>(NUM_SET * NUM_WAY);
    for (int i=0; i < NUM_SET * NUM_WAY; i++) {
        rripVal[this][i] = 0;
    }
}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type) {
    std::vector<uint32_t> a;
    int tempo = 10;
    for(uint32_t i=0;i<NUM_WAY;i++){
        uint8_t v = rripVal[this][set*NUM_WAY+i];
        if(v==0){
            a.push_back(i);
        }
        if (v < tempo) tempo = v;
    }
    if(a.size()!=0){
        return a[(rand() % a.size())];
    }
    else{
        for(uint32_t i=0;i<NUM_WAY;i++){
            rripVal[this][set*NUM_WAY+i]-=tempo;
            if (rripVal[this][set*NUM_WAY+i]==0) a.push_back(i);
        }
        return a[(rand() % a.size())];
    }
    assert(false);
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit) {
    const uint32_t idx = set * NUM_WAY + way;
    if (hit && type == WRITEBACK)
        return;
    if (hit) {
        rripVal[this][idx] = 7;
    } else {
        rripVal[this][idx] = 1;
    }
}

void CACHE::replacement_final_stats() {}