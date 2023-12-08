#include <iostream>
#include <vector>

int collatz_rec(unsigned long n) {
  if(n < 2) return 0;

  if(n % 2) return 1 + collatz_rec(3 * n + 1);
  
  return 1 + collatz_rec(n / 2);
}

int collatz_r(unsigned long n, long *lookup) {
  if(n < 2) return 0;

  if(n < 1000) {
    if(lookup[n] == 0) {
      if(n % 2 == 0) lookup[n] = 1 + collatz_r(n / 2, lookup);
      else lookup[n] = 1 + collatz_r(3 * n + 1, lookup);
    }
  } else {
      if(n & 1) return 1 + collatz_r(3 * n + 1, lookup);
      else return 1 + collatz_r(n / 2, lookup);
    }

  return lookup[n];
}

int collatz(unsigned long n) {
  long lookup[1000] = {0};

  return collatz_r(n, lookup);
}

int main() {
  // std::cout << "Collatz(837799) = " << collatz(837799);
  std::cout << "collatz(871) = " << collatz_rec(871) << std::endl;
  std::cout << "collatz(871) = " << collatz(871);

  return 0;
}
// Pokušati optimizirati rješenje koristeći memoizaciju.
// Obratite pažnju da neke jednostavne početne vrijednosti Collatz
// sekvence mogu dovesti do jako visokih brojeva kroz samu sekvencu,
// pa bi bilo dobro napraviti neki vid kombinovanog rješenja. Primjera
// radi, prvih 1000 vrijednosti bi mogli spremiti u lookup tabelu, a
// vrijednosti preko toga računati regularnim pristupom rekurzije bez
// tabele.
