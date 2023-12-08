#include <iostream>
#include <vector>
#include "selectionsort.cpp"
#include <list>

int main() {
  std::list<int> vec{5, 7, 4, 2, 9, 1};

  selectionsort(vec.begin(), vec.end(), [](const int& lhs, const int& rhs) { return lhs > rhs; });

  for(auto &e : vec)
    std::cout << e << ' ';

  return 0;
}
