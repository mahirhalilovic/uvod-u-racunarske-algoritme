#include <iostream>
#include <vector>

int coin_change_rek(int *coins, int n, int sum) {
  if(n == 0) return 0;
  if(sum == 0) return 1;
  if(sum < 0) return 0;

  return coin_change_rek(coins, n - 1, sum) + coin_change_rek(coins, n, sum - coins[n - 1]);
}

int coin_change_mem_r(int *coins, int n, int sum, int lookup[2000][20]) {
  if(n == 0) return 0;
  if(sum == 0) return 1;
  if(sum < 0) return 0;

  if(lookup[sum][n] == 0) {  
    lookup[sum][n] = coin_change_mem_r(coins, n - 1, sum, lookup) + coin_change_mem_r(coins, n, sum - coins[n - 1], lookup);
  }

  return lookup[sum][n];
}

int coin_change_mem(int *coins, int n, int sum) {
  int lookup[2000][20];

  for(int i = 0; i < sum + 1; ++i)
    lookup[i][0] = 1;

  for(int i = 0; i < n + 1; ++i)
    lookup[0][i] = 1;

  return coin_change_mem_r(coins, n, sum, lookup);
}

int coin_change_din(int *coins, int n, int sum) {
  std::vector<int> lookup;
  lookup.resize(sum + 1, 0);
  lookup[0] = 1;

  for(int i = 0; i < n; ++i) {
    for(int j = 1; j < sum + 1; ++j) {
      if(j >= coins[i])
        lookup[j] += lookup[j - coins[i]];
    }
  }

  return lookup[sum];
}

int main() {
  int coins[] = {1, 2, 3};

  std::cout << coin_change_rek(coins, 3, 4) << std::endl;
  std::cout << coin_change_mem(coins, 3, 4) << std::endl;
  std::cout << coin_change_din(coins, 3, 4);

  return 0;
}
