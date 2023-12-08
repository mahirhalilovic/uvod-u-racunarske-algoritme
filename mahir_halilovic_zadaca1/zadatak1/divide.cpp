#include <iostream>

int divide(int a, int b) {
  if(a < b) return 0;
  return 1 + divide(a - b, b);
}

// Napisati funkciju divide koja uz pomoć rekurzije i oduzimanja određuje rezultat
// cjelobrojnog dijeljenja dva broja. Funkcija treba da se izvršava u O(n) vremenu.
