bool palindrome(const char* s, int n) {
  if(n < 2) return true; 

  return *s == *(s + n - 1) && palindrome(s + 1, n - 2);
}

// Napisati rekurzivnu funkciju koja provjerava da li je proslijeđeni c string palin-
// drom. Funkcija treba imati potpis bool palindrome(const char* s, int n).
