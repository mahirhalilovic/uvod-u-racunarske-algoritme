#include <iostream>
#include <vector>
#include "shellsort.cpp"

int main() {
  std::vector<int> vec{5, 7, 4, 2, 9, 1};

  shellsort(vec.begin(), vec.end(), [](const int& lhs, const int& rhs) { return lhs > rhs; });

  for(auto &e : vec)
    std::cout << e << ' ';

  return 0;
}
