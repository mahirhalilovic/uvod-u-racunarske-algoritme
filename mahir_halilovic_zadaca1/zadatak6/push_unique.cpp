#include <vector>

bool push_unique(std::vector<int> &vec, int element) {
  auto it = vec.begin();
  while(it != vec.end()) {
    if(*it == element) return false;
    ++it;
  }

  vec.push_back(element);
  return true;
}

// Napisati funkciju push_unique sa potpisom:
//
// bool push_unique(std::vector<int>&, int)
// Gdje je prvi parametar niz brojeva, a drugi parametar je element kojeg treba
// ubaciti na kraj niza samo u slučaju da element već nije u nizu. Funkcija treba
// da se izvršava u O(n) vremenu, nije potrebno da vector bude sortiran. Funkcija
// vraća true ukoliko je element ubačen u niz.
