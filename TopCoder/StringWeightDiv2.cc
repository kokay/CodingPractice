#include <string.h>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class StringWeightDiv2 {
public:
  const int MOD = 1000000009;
  int countMinimums(int L) {
    long long ans = 1;
    for (int i = 0; i < min(26, L); i++)
        ans = (ans * (26 - i)) % MOD;

    long long memo[1001][1001];
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < 27; ++j)
        memo[i][j] = 1;
    }

    for (int i = 2; i < L; ++i) {
      for (int j = 1; j < i; ++j) {
        memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]) % MOD;
      }
    }

    return (ans * memo[L - 1][25]) % MOD;
  }
};

//int main() {
//  StringWeightDiv2 s;
//  cout << s.countMinimums(1000) << endl;
//}