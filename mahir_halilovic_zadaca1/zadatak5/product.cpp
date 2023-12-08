
int product(int n) {
  if(n <= 0) return 1;
  if(n % 2) return product(n - 1);
  
  return n * product(n - 2);
}

// Napisati rekurzivnu funkciju koja računa proizvod parnih prirodnih brojeva
// manjih i jednakih broju n. Od korisnika se traži unos broja n u main funkciji.
