#include "palindrome.cpp"
#include <iostream>

int main() {
  std::cout << "\"racecar\" is a palindrome - " << std::boolalpha << palindrome("racecar", 7);
  std::cout << "\n\"onion\" is a palidnrome - " << std::boolalpha << palindrome("onion", 5);
  
  return 0;
}
