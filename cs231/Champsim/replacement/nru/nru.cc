#include <algorithm>
#include <iterator>
#include <map>

#include "cache.h"
#include "util.h"

std::map<CACHE*,std::vector<uint32_t>> nru;

void CACHE::initialize_replacement() {
    nru[this] = std::vector<uint32_t>(NUM_SET * NUM_WAY);
    for (int i=0; i < NUM_SET * NUM_WAY; i++) {
      nru[this][i] = 0;
    }
}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
    std::vector<uint32_t> tempo;

    for(uint32_t i=0;i<NUM_WAY;i++){
        if(nru[this][set*NUM_WAY+i]==0){
            tempo.push_back(i);
        }
    }

    if(tempo.size()!=0){
        return tempo[(rand() % tempo.size())];
    }
    else{
        for(uint32_t i=0;i<NUM_WAY;i++){
            nru[this][set*NUM_WAY+i]=0;
        }
        return rand()%NUM_WAY;
    }
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit)
{
    if (hit && type == WRITEBACK)  {
      return;
    }
    nru[this][set*NUM_WAY+way]=1;
    return;
}

void CACHE::replacement_final_stats() {}