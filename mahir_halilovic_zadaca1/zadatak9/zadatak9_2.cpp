#include "../zadatak7/upper_bound.cpp"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

int main() {
  std::vector<std::string> vec;
  std::string k;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  while(std::cin >> k) {
    auto it = upper_bound(vec.begin(), vec.end(), k);
    vec.insert(it, k);
  }

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms";

  return 0;
}
