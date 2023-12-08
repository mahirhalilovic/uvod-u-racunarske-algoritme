#include "push_unique.cpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec{1, 5, 3, 6, 2, 7, 4, 9, 8};
  std::cout << "Push 10: " << std::boolalpha << push_unique(vec, 10);
  std::cout << "\nPush 4: " << std::boolalpha << push_unique(vec, 4);

  return 0;
}
