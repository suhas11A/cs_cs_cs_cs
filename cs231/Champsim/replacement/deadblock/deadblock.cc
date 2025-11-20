#include <algorithm>
#include <iterator>
#include "sampler.h"
#include "cache.h"
#include "util.h"

extern DeadBlockPredictor dp_predictor;
void CACHE::initialize_replacement() {}

// find replacement victim
uint32_t CACHE::find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK* current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
  // -------- Task 2: prefer blocks predicted to be dead --------------------
  for (uint32_t way = 0; way < NUM_WAY; ++way) {
    const BLOCK& blk = current_set[way];

    // (Normally, find_victim is only called when all ways are valid,
    //  but we keep this check for safety.)
    if (!blk.valid)
      continue;

    uint32_t signature = static_cast<uint32_t>(blk.ip);
    if (dp_predictor.predict_to_be_dead(signature)) {
      // Choose the first predicted-dead block as victim
      return way;
    }
  }
  // -----------------------------------------------------------------------

  // Fallback to pure LRU when no block is confidently dead
  return std::distance(current_set,
                       std::max_element(current_set,
                                        std::next(current_set, NUM_WAY),
                                        lru_comparator<BLOCK, BLOCK>()));
}

// called on every cache hit and cache fill
void CACHE::update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type,
                                     uint8_t hit)
{
  if (hit && type == WRITEBACK)
    return;

  auto begin = std::next(block.begin(), set * NUM_WAY);
  auto end = std::next(begin, NUM_WAY);
  uint32_t hit_lru = std::next(begin, way)->lru;
  std::for_each(begin, end, [hit_lru](BLOCK& x) {
    if (x.lru <= hit_lru)
      x.lru++;
  });
  std::next(begin, way)->lru = 0; // promote to the MRU position
}

void CACHE::replacement_final_stats() {}
