#include <iostream>

long int fib_rek(int n) {
  if(n < 2) return n;

  return fib_rek(n - 1) + fib_rek(n - 2);
}

long int fib_mem_r(int n, long int *lookup) {
  if(lookup[n] == 0) {
    if(n < 2)
      lookup[n] = n;
    else
      lookup[n] = fib_mem_r(n - 1, lookup) + fib_mem_r(n - 2, lookup);
  }

  return lookup[n];
}

long int fib_mem(int n) {
  long int lookup[100] = {0};

  return fib_mem_r(n, lookup);
}

long int fib_din(int n) {
  long int lookup[100];
  lookup[0] = 0;
  lookup[1] = 1;

  for(int i = 2; i < n + 1; ++i)
    lookup[i] = lookup[i - 1] + lookup[i - 2];

  return lookup[n];
}

int main() {
  int k = 40;
  std::cout << "F_d(k) = " << fib_din(k) << std::endl;
  std::cout << "F_m(k) = " << fib_mem(k) << std::endl;
  std::cout << "F_r(k) = " << fib_rek(k) << std::endl;
  return 0;
}
