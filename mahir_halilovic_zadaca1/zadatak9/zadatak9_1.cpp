#include "../zadatak7/upper_bound.cpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>

int main() {
  std::vector<std::string> vec;
  std::string k;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  while(std::cin >> k)
    vec.push_back(k);

  std::sort(vec.begin(), vec.end());

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms";

  return 0;
}
