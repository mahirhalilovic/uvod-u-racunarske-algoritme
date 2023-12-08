#include "Tim.cpp"
#include "sorts.cpp"

int main() {
  Tim timovi[5] = {{"Prvi tim", 31, 12, 41},
             {"Drugi tim", 31, 14, 42},
             {"Treci tim", 29, 16, 52},
             {"Cetvrti tim", 29, 16, 52},
             {"Tim pet", 7, 42, 11}};

  std::sort(std::begin(timovi), std::end(timovi), [](auto lhs, auto rhs) { return lhs.naziv < rhs.naziv; });
  std::stable_sort(std::begin(timovi), std::end(timovi), [](auto lhs, auto rhs) { return lhs.postignutiGolovi < rhs.postignutiGolovi; });
  std::stable_sort(std::begin(timovi), std::end(timovi), [](auto lhs, auto rhs) { return lhs.postignutiGolovi - lhs.primljeniGolovi < rhs.postignutiGolovi - rhs.primljeniGolovi; });
  std::stable_sort(std::begin(timovi), std::end(timovi), [](auto lhs, auto rhs) { return lhs.bodovi < rhs.bodovi; });

  for(auto k : timovi)
    print(k);

  return 0;
}
