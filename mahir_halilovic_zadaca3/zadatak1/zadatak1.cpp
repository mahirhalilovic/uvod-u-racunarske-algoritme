#include <iostream>
#include <vector>

long int sek_rek(int n) {
  if (n == 0) return 2;
  if (n == 1) return 4;
  if (n == 2) return 12;

  return 3 * sek_rek(n - 3) + 2 * sek_rek(n - 2) + sek_rek(n - 1);
}

long int sek_mem_r(int n, std::vector<long int>& lookup) {
  if (n == 0) return 2;
  if (n == 1) return 4;
  if (n == 2) return 12;
  if (lookup[n] == 0) {
    lookup[n] = 3 * sek_mem_r(n - 3, lookup) + 2 * sek_mem_r(n - 2, lookup) + sek_mem_r(n - 1, lookup);
  }

  return lookup[n];
}

long int sek_mem(int n) {
  std::vector<long int> lookup;
  lookup.resize(n + 1, 0);

  return sek_mem_r(n, lookup);
}

long int sek_din(int n) {
  long int lookup[n + 1];
  lookup[0] = 2;
  lookup[1] = 4;
  lookup[2] = 12;

  for(int i = 3; i <= n; ++i)
    lookup[i] = 3 * lookup[i - 3] + 2 * lookup[i - 2] + lookup[i - 1];

  return lookup[n];
}

int main() {
  std::cout << "sek_rek(35) = " << sek_rek(35) << std::endl;
  std::cout << "sek_mem(35) = " << sek_mem(35) << std::endl;
  std::cout << "sek_din(35) = " << sek_din(35);

  return 0;
}



// Neka je sekvenca cijelih brojeva definisana na sljedeći način:
// a(0) = 2
// a(1) = 4
// a(2) = 12
// a(n) = 3*a(n-3)+2*a(n-2)+a(n-3)
