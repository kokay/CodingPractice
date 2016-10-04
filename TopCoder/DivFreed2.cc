#include <iostream>
#include <vector>
#include <string.h>
#define mod 1000000007

using namespace std;

class DivFreed2 {
public:
  int count(int n, int k) {
    int dp[11][100001];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
      dp[1][i] = 1;

    for (int pos = 2; pos <= n; pos++) {
      int sum = 0;
      for (int i = 1; i <= k; i++)
        sum = (sum + dp[pos - 1][i]) % mod;

      for (int i = 1; i <= k; i++) {
        dp[pos][i] += sum;
        for (int j = 2 * i; j <= k; j += i)
          dp[pos][i] = (dp[pos][i] - dp[pos - 1][j] + mod) % mod;
      }
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
      ans = (ans + dp[n][i]) % mod;
    return ans;
  }
};
