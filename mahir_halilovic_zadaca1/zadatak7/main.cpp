#include "upper_bound.cpp"
#include <vector>

int main() {
  std::vector<int> vec{2, 4, 6, 8, 10};

  auto it = upper_bound(vec.begin(), vec.end(), 7);
  vec.insert(it, 7);

  for(auto &e : vec)
    std::cout << e << ' ';

  return 0;
}
