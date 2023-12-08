
int sum(const int* array, int n) {
  if(n == 0) return 0;
  return array[n - 1] + sum(array, n - 1);
}

// Napisati rekurzivnu funkciju koja računa sumu svih elemenata u nizu. Funkcija
// treba da ima sljedeći prototip: int sum(const int* array, int n); gdje je array
// adresa prvog elementa u nizu, a n ukupan broj elemenata.
