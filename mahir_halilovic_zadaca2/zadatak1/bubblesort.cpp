#include <iostream>

template <typename It, typename C>
void bubblesort(It begin, It end, C comp) {
  // forward iterators
  // O(n^2)
  // in-place
  // stabilan
  
  auto cbegin = begin++;
  auto mEnd = end;

  while(begin != end) {
    auto cond = cbegin, b = cbegin;
    ++cond;

    while(cond != mEnd) {
      auto temp = b++;
      if(comp(*b, *temp))
        std::swap(*temp, *b);

      ++cond;
    }

    mEnd = b;
    ++begin;
  }

  // bidirectional iterators
  // O(n^2)
  // in-place
  // stabilan

  // auto cend = --end;
  // auto cbegin = begin;
  //
  // while(cbegin != cend) {
  //   for(auto b = begin; b != end;) {
  //     auto temp = b++;
  //     if(comp(*temp, *b))
  //       std::swap(*temp, *b);
  //   }
  //
  //   ++cbegin;
  // }
}
