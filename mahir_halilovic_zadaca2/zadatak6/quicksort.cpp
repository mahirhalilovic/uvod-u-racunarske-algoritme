#include <algorithm>
#include <iostream>
#include "../zadatak3/insertionsort.cpp"

template <typename It>
void quicksort(It begin, It end) {
  // bidirekcioni iteratori
  // wc: O(n^2), ac: O(n * logn), bc: O(n * logn)
  // in-place
  // nije stabilan
  int n = std::distance(begin, end);
  if (n > 1) {
    if (n > 1) {
      auto it = end;
      --it;
      auto last = *it;
      auto pivot = std::partition(begin, end, [&last](auto lhs) { return lhs < last; });
      std::swap(*it, *pivot);
      quicksort(begin, pivot++);
      quicksort(pivot, end);
    } else {
      insertionsort(begin, end, [](auto lhs, auto rhs) { return lhs > rhs; });
    }
  }
}
