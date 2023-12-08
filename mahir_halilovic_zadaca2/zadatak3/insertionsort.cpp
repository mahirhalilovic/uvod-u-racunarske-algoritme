#include <iostream>

template <typename It, typename C>
void insertionsort(It begin, It end, C comp) {
  // bidirekcioni iteratori
  // O(n^2)
  // in-place
  // stabilan
  auto cnt = begin;
  --begin;
  ++cnt;
  for(; cnt != end;) {
    auto key = *cnt;
    auto temp = cnt++;
    auto ph = temp;
    --temp;
    while(temp != begin && comp(key, *temp)) {
      *ph = *temp;
      --temp;
      --ph;
    }

    *ph = key;
  }
}
