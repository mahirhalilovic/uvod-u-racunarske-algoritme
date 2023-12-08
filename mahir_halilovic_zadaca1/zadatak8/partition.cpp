#include <iostream>

template <typename Iter, typename P>
Iter partition(Iter begin, Iter end, const P& p) {
  auto it = begin;

  while(begin != end) {
    if(p(*begin)) {
      std::swap(*begin, *it);
      ++it;
    }

    ++begin;
  }

  return it;
}


// Ovaj algoritam prima opseg niza opisan pomoću dva iteratora, uzetih putem
// template parametra, a koji trebaju zadovoljavati karakteristike ForwardIteratora.
// Dodatni parametar p je predikat funkcija koja prima element niza, a vraća
// natrag bool vrijednost. Funkcija treba da izmjeni redoslijed elemenata u nizu na
// način da se svi elementi za koje je predikat funkcija p vratila true nalaze ispred
// elemenata za koje je funkcija vratila false. Međusobni poredak elemenata u ove
// dvije grupe nije bitan. Funkcija vraća iterator na prvi element iz druge grupe,
// za koje je predikat funkcija p vratila false. Dva primjera upotrebe partition
// algoritma:
// std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// std::partition(v.begin(), v.end(), [](int elem) { return elem & 2 == 0; });
// // sadržaj vektora v nakon poziva:
// // v = {0, 8, 2, 6, 4, *5*, 3, 7, 1, 9};
// // funkcija bi vratila iterator koji pokazuje na element 5 (boldiran).
// std::vector<int> v{2, 1, 3, 8, 4, 5, 6, 9, 7};
// auto s = std::partition(v.begin(), v.end(),
// [](const int& e) -> bool { return e < 4; });
// for (auto it = begin(v); it < s; ++it)
// std::cout << *it << ' ';
// std::cout << '*';
// for (; s < end(v); ++s)
// std::cout << ' ' << *s;
// std::cout << std::endl;
// // Ispis programa bi bio
// // 2 1 3 * 8 4 5 6 9 7
