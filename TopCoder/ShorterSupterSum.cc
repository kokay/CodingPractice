#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class ShorterSuperSum {
public:
  int calculate(int k, int n) {
    memset(memo, -1, sizeof(memo));
    return superSum(k, n);
  }

  int calculate2(int k, int n) {
    int memo[15][15];
    for (int i = 1; i < 15; ++i)
      memo[0][i] = i;

    for (int i = 1; i <= k; ++i) {
      int sum = 0;
      for (int j = 1; j <= n; ++j) {
        sum += memo[i - 1][j];
        memo[i][j] = sum;
      }
    }
    return  memo[k][n];
  }

private:
  int memo[15][15];

  int superSum(int k, int n) {
    if (k == 0) return n;
    if (memo[k][n] != -1) return memo[k][n];

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      memo[k-1][i] = superSum(k - 1, i);
      sum += memo[k - 1][i];
    }
    return sum;
  }
};