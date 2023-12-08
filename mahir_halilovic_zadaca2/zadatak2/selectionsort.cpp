#include <iostream>

template <typename It, typename C>
void selectionsort(It begin, It end, C comp) {
  // forward iteratori
  // O(n^2)
  // in-place
  // nije stabilan
  auto pos = begin++;

  while(begin != end) {
    
    auto minEl = pos;
    auto b = pos;
    ++b;
    for(; b != end; ++b) {
      if(comp(*b, *minEl))
        minEl = b;
    }

    if(minEl != pos)
      std::swap(*pos, *minEl);

    ++pos;
    ++begin;
  }
}
