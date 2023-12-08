#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>

int main() {
  std::vector<std::string> vec;
  std::string k;
  std::ifstream file{"../shakespeare.txt"};
  
  while(file >> k) {
    for(char &c : k)
      c = tolower(c);

    vec.push_back(k);
  }

  // std::set<std::string> s;
  // for(auto e : vec) s.insert(e);
  // vec.assign( s.begin(), s.end() );

  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

  std::cout << "Unesite neku rijec: ";
  while(std::cin >> k) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto it = std::find(vec.begin(), vec.end(), k);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    if(it != vec.end())
      std::cout << "Rijec je pronadjena!\n";
    else
      std::cout << "Rijec nije pronadjena!\n";

    std::cout << "Vrijeme pretrage: " << t << "ms\n";
    std::cout << "Unesite neku rijec: ";
  }

  return 0;
}
