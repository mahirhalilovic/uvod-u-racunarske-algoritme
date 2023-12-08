#pragma once
#include <iostream>

template<typename It, typename T>
It upper_bound(It begin, It end, const T& element) {
  int mid = (end - begin) / 2;
  if(mid == 0) return end;
  
  if(element < *(begin + mid)) return upper_bound(begin, begin + mid, element);

  return upper_bound(begin + mid, end, element);
}

// Implementirati funkciju upper_bound sa potpisom:
// It upper_bound(It begin, It end, const T& element);
// begin i end predstavljaju dva random_access iteratora, na primjer iz kontenjera
// std::vector. Niz na koji iteraotri pokazuju je sortiran. Treći argument je
// element kojeg korisnik želi ubaciti u niz.
// Funkcija treba da u O(log n) vremenu pronađe mjesto u nizu gdje treba ubaciti
// element tako da bi nakon ubacivanja elementa niz ostao sortiran. Funkcija vraća
// natrag iterator na poziciju gdje treba ubaciti element. Pretpostaviti da korisnik
// ubaciju elemente sa vector::insert metodom (ona ubacuje prije).
// Pomoć: U standardnoj biblioteci postoji algoritam upper_bound. Ideja je da
// algoritam pomoću polovljenja intervala pronalazi prvi element koji je veći od
// traženog elementa, ili iterator na kraj ako je element veći od svih elemenata u
// nizu. Kod u prilogu bi radio pravilno ubacivanje u niz:
// std::vector v{2,4,6,8,10};
// auoto it = std::upper_bound(v.begin(), v.end(), 7); // vraća iterator na 8
// v.insert(it, 7); // v = {2,4,5,7,8,10};
// it = std::upper_bound(v.begin(), v.end(), 20); // vraća iterator na end
// v.insert(it, 20); // v = {2,4,5,7,8,10,20};
// it = std::upper_bound(v.begin(), v.end(), 7); // vraća iterator na 8
// v.insert(it, 7); // v = {2,4,5,7,7,8,10,20};
