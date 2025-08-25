#include "alloc.h"

void alloc_measure( unsigned VSIZE_RANGE, unsigned REPEAT, std::map<unsigned,float>& m ) {
  for (unsigned i=0;i<REPEAT;i++) {
    std::vector<unsigned> vec;
    for (unsigned j=0;j<VSIZE_RANGE;j++) {
      ClockCounter time;
      time.start();
      vec.push_back(0);
      m[j] += time.stop();
    }
  }
  for( auto pr : m ) {
    pr.second /= REPEAT;
  }
}