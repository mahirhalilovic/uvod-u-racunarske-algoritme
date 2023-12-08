#include <iostream>
#include <vector>
#include "quicksort.cpp"

int main() {
  std::vector<int> vec{5, 7, 4, 2, 9, 1};

  quicksort(vec.begin(), vec.end());

  for(auto &e : vec)
    std::cout << e << ' ';

  return 0;
}
