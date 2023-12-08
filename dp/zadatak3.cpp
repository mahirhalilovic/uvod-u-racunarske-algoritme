#include <iostream>
#include <string>

int lsr(const char *a, const char *b, int na, int nb) {
  if(na == 0 || nb == 0) return 0;
  if(a[na - 1] == b[nb - 1]) return 1 + lsr(a, b, na - 1, nb - 1);
  else return std::max(lsr(a, b, na - 1, nb), lsr(a, b, na, nb - 1));
}

int lsmr(const char *a, const char *b, int na, int nb, int lookup[100][100]) {
  if(na == 0 || nb == 0) return 0;
  if(lookup[na][nb] == 0) {
    if(a[na - 1] == b[nb - 1]) return 1 + lsmr(a, b, na - 1, nb - 1, lookup);
    else return std::max(lsmr(a, b, na - 1, nb, lookup), lsmr(a, b, na, nb - 1, lookup));
  }

  return lookup[na][nb];
}

int lsm(const char *a, const char *b, int na, int nb) {
  int lookup[100][100];
  for(int i = 0; i < 100; ++i) {
    for(int j = 0; j < 100; ++j)
      lookup[i][j] = 0;
  }

  return lsmr(a, b, na, nb, lookup);
}

int lsd(const char *a, const char *b, int na, int nb) {
  int lookup[100][100];
  for(int i = 0; i < 100; ++i) {
    lookup[0][i] = 0;
    lookup[i][0] = 0;
  }

  for(int i = 1; i < na + 1; ++i)
    for(int j = 1; j < nb + 1; ++j) {
      if(a[i - 1] == b[j - 1]) lookup[i][j] = 1 + lookup[i - 1][j - 1];
      else lookup[i][j] = std::max(lookup[i - 1][j], lookup[i][j - 1]);
    }

  return lookup[na][nb];
}

int main() {
  std::string a{"AGGTAB"}, b{"GXTXAYB"};
  int na = 6, nb = 7;

  std::cout << "lsr = " << lsr(a.c_str(), b.c_str(), na, nb) << std::endl;
  std::cout << "lsm = " << lsm(a.c_str(), b.c_str(), na, nb) << std::endl;
  std::cout << "lsd = " << lsd(a.c_str(), b.c_str(), na, nb);

  return 0;
}
