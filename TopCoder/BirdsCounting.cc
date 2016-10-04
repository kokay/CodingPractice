#include <string.h>
#include <string>
#include <iostream>

using namespace std;

double dp[8][32];
int comb[32][32];
class BirdsCounting {
public:
  double computeProbability(int birdsNumber, int caughtPerDay, int daysNumber, int birdsMarked) {
    memset(dp, 0x00, sizeof(dp));
    init();

    dp[0][caughtPerDay] = 1.0;
    for (int d = 1; d < daysNumber; d++) {
      for (int i = 0; i < birdsNumber + 1; i++) {
        for (int k = 0; k < caughtPerDay + 1; k++) {
          if (k > i) continue;
          cout << "try to find dp[" << d << "][" << i + k << "]: d = " << d << " i = " << i << " k = " << k  <<endl;;
          cout << "  dp[" << d - 1 << "][" << i << "] = " << dp[d - 1][i] << endl;
          cout << "  " << birdsNumber << " - " << i << " choose " << k << " = " << prep(birdsNumber - i, k) << endl;
          cout << "  " << i << " choose " << caughtPerDay << " - " << k << " = " << prep(i, caughtPerDay - k) << endl;
          cout << "  " << birdsNumber << " choose " << caughtPerDay << " = " << prep(birdsNumber, caughtPerDay) << endl;
          dp[d][i + k] += dp[d - 1][i] * prep(birdsNumber - i, k)
            * prep(i, caughtPerDay - k) / prep(birdsNumber, caughtPerDay);
        }
      }
    }

    return dp[daysNumber - 1][birdsMarked];
  }

private:
  double prep(int n, int k) {
    if (k > n)
      return 0.0;
    return comb[n][k];
  }

  void init() {
    for (int i = 0; i<32; ++i) comb[i][0] = 1;
    for (int i = 1; i<32; ++i) 
      for (int j = 1; j<32; ++j)
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
  }
};
//
//int main() {
//  BirdsCounting b;
//  cout << b.computeProbability(3, 1, 2, 2) << endl;
//}