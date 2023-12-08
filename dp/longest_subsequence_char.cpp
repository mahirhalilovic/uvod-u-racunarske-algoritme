#include <iostream>
#include <string>

int longest_subsequence_char_rec(const char *a, const char *b, int na, int nb) {
  if (na == 0 || nb == 0) return 0;

  if (a[na - 1] == b[nb - 1])
    return 1 + longest_subsequence_char_rec(a, b, na - 1, nb - 1);
  else
    return std::max(longest_subsequence_char_rec(a, b, na - 1, nb),
                    longest_subsequence_char_rec(a, b, na, nb - 1));
}

int longest_subsequence_char_mem_r(const char *a, const char *b, int na, int nb,
                                   int lookup[100][100]) {
  if (na == 0 || nb == 0) return 0;

  if (lookup[na - 1][nb - 1] == 0) {
    if (a[na - 1] == b[nb - 1])
      lookup[na - 1][nb - 1] =  1 + longest_subsequence_char_mem_r(a, b, na - 1, nb - 1, lookup);
    else
      lookup[na - 1][nb - 1] = std::max(longest_subsequence_char_mem_r(a, b, na - 1, nb, lookup),
                      longest_subsequence_char_mem_r(a, b, na, nb - 1, lookup));
  }

  return lookup[na - 1][nb - 1];
}

int longest_subsequence_char_mem(const char *a, const char *b, int na, int nb) {
  int lookup[100][100];

  return longest_subsequence_char_mem_r(a, b, na, nb, lookup);
}

int longest_subsequence_char_din(const char *a, const char *b, int na, int nb) {
  int lookup[na + 1][nb + 1];

  for (int i = 0; i <= na; ++i)
    lookup[i][0] = 0;

  for (int i = 0; i <= nb; ++i)
    lookup[0][i] = 0;

  for (int i = 1; i < na + 1; ++i) {
    for (int j = 1; j < nb + 1; ++j) {
      if(a[i - 1] == b[j - 1])
        lookup[i][j] = 1 + lookup[i - 1][j - 1];
      else
        lookup[i][j] = std::max(lookup[i][j - 1], lookup[i - 1][j]);
    }
  }

  return lookup[na][nb];
}

int main() {
  std::string a{"AGGTAB"};
  std::string b{"GXTXAYB"};

  std::cout << "Recursion: "
            << longest_subsequence_char_rec(a.c_str(), b.c_str(), a.size(),
                                            b.size()) << std::endl;

  std::cout << "Memoization: "
            << longest_subsequence_char_mem(a.c_str(), b.c_str(), a.size(),
                                            b.size()) << std::endl;

  std::cout << "Dynamic: "
            << longest_subsequence_char_din(a.c_str(), b.c_str(), a.size(),
                                            b.size());

  return 0;
}
