#include <iostream>

template<typename It>
void merge(It begin, It mid, It end) {
  while(begin != mid && mid != end) {
    if(*begin <= *mid)
      ++begin;
    else {
      auto key = *mid;
      auto index1 = mid;
      auto index2 = mid;
      --index2;

      while(index1 != begin) {
        *index1 = *index2;
        --index1;
        --index2;
      }

      *begin = key;
      ++begin;
      ++mid;
    }
  }
}

template <typename It>
void mergesort(It begin, It end) {
  // bidirekcioni iteratori
  // O(n^2 * logn)
  // in-place
  // stabilan
  auto size = std::distance(begin, end);

  if(size > 1) {
    auto mid = begin;
    std::advance(mid, size / 2);
    mergesort(begin, mid);
    mergesort(mid, end);
    merge(begin, mid, end);
  }
}
