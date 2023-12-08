#include <iostream>

template<typename Iter, typename P>
Iter stable_partition(Iter begin, Iter end, const P& p) {
  auto it = begin;

  while(begin != end) {
    if(p(*begin)) {
      auto it2 = begin;
      while(it2 != it) {
        std::swap(*it2--, *it2);
      }
      // auto temp = *begin;
      // std::move(it++, begin, it);
      // *(--it)++ = temp;
      ++it;
    }

    ++begin;
  }

  return it;
}
