#include <iostream>
using namespace std;

const int dis[10][7] =
{
  { 1, 1, 1, 0, 1, 1, 1 },
  { 0, 0, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 0, 1, 1, 1, 0, 1, 0 },
  { 1, 1, 0, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 1, 1, 1 },
  { 1, 0, 1, 0, 0, 1, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 },
};

class NumbersAndMatches
{
public:

  long long dp[127][127];

  long long differentNumbers(long long N, int K)
  {
    const int m = 126;

    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
        dp[i][j] = !i && !j;

    int inc[10][10], dec[10][10];

    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
      {
        inc[i][j] = dec[i][j] = 0;
        for (int k = 0; k < 7; k++)
        {
          if (dis[i][k] < dis[j][k])
            inc[i][j] ++;
          if (dis[i][k] > dis[j][k])
            dec[i][j] ++;
        }
      }

    while (N > 0)
    {
      int n = N % 10;
      N /= 10;

      for (int i = m; i >= 0; i--)
        for (int j = m; j >= 0; j--)
          if (dp[i][j])
          {
            long long me = dp[i][j];

            dp[i][j] -= me;
            for (int k = 0; k < 10; k++)
            {
              dp[i + inc[n][k]][j + dec[n][k]] += me;
            }
          }
    }

    long long re = 0;
    for (int i = 0; i <= K; i++)
      re += dp[i][i];
    return re;
  }
};

//int main() {
//  NumbersAndMatches numbersAndMatches;
//  cout << numbersAndMatches.differentNumbers(10, 1) << endl;
//}