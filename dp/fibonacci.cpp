#include <iostream>
#include <vector>

long int fibonacci_rec(int n) {
  if(n <= 1) return n;

  return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

long int fibonacci_din(int n) {
  std::vector<long int> lookup;
  lookup.resize(n + 1, 0);
  lookup[0] = 0;
  lookup[1] = 1;

  for(int i = 2; i <= n; ++i)
    lookup[i] = lookup[i - 1] + lookup[i - 2];

  return lookup[n];
}

long int fibonacci_mem_rec(int n, std::vector<long int>& lookup) {

  if (lookup[n] == 0) {
    if(n <= 1) {
      lookup[n] = n;
    } else {
      lookup[n] = fibonacci_mem_rec(n - 1, lookup) + fibonacci_mem_rec(n - 2, lookup);
    }
  }

  return lookup[n];
}

long int fibonacci_mem(int n) {
  std::vector<long int> lookup;
  lookup.resize(n + 1, 0);

  return fibonacci_mem_rec(n, lookup);
}

int main() {
  std::cout << "F(35) = " << fibonacci_mem(35) << std::endl;
  std::cout << "F(40) = " << fibonacci_mem(40) << std::endl;
  std::cout << "F(45) = " << fibonacci_mem(45) << std::endl;

  return 0;
}
