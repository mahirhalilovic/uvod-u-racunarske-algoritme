#include "partition.cpp"
#include "stable_partition.cpp"
#include <iostream>
#include <list>

int main() {
  std::list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> l2(l);
  auto it = partition(l.begin(), l.end(), [](int elem) { return elem % 2 == 0; });
  auto it2 = stable_partition(l2.begin(), l2.end(), [](int elem) { return elem % 2 == 0; });

  std::cout << "Partition: ";
  for(auto &e : l)
    std::cout << e << ' ';

  std::cout << "\nIterator: " << *it;

  std::cout << "\nStable partition: ";
  for(auto &e : l2)
    std::cout << e << ' ';
  
  std::cout << "\nStable iterator: " << *it2;

  return 0;
}
