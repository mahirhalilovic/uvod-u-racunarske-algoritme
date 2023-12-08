#pragma once
#include <iostream>

struct Tim {
  std::string naziv;
  int bodovi;
  int primljeniGolovi;
  int postignutiGolovi;
};

void print(Tim t) {
  std::cout << t.naziv << ' ' << t.bodovi << ' ' << t.primljeniGolovi << ' ' << t.postignutiGolovi << std::endl;
}
