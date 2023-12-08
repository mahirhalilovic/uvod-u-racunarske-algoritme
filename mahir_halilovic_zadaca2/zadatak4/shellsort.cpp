#include <iostream>

template <typename It, typename C>
void shellsort(It begin, It end, C comp) {
  // random access iteratori
  // O(n^2)
  // in-place
  // nije stabilan
  int n = end - begin;
  for(int shell = n / 2; shell > 0; shell /= 2) {
    for(int i = shell; i < n; ++i) {
      auto temp = *(begin + i);
      int j;

      for(j = i; j >= shell && comp(temp, *(begin + j - shell)); j -= shell)
        *(begin + j) = *(begin + j - shell);

      *(begin + j) = temp;
    }
  }
}
