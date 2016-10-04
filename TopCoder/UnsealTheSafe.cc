#include <iostream>

using namespace std;

class UnsealTheSafe {
public:
  long long countPasswords(int N) {
    long long m[10][31];
    for (int num = 0; num <= 9; ++num)
      m[num][1] = 1;

    for (int len = 2; len <= N; ++len) {
      int pre = len - 1;
      m[0][len] = m[7][pre]; 
      m[1][len] = m[2][pre] + m[4][pre]; 
      m[2][len] = m[1][pre] + m[3][pre] + m[5][pre]; 
      m[3][len] = m[2][pre] + m[6][pre]; 
      m[4][len] = m[1][pre] + m[5][pre] + m[7][pre];
      m[5][len] = m[2][pre] + m[4][pre] + m[6][pre] + m[8][pre];
      m[6][len] = m[3][pre] + m[5][pre] + m[9][pre];
      m[7][len] = m[4][pre] + m[8][pre] + m[0][pre];
      m[8][len] = m[5][pre] + m[7][pre] + m[9][pre];
      m[9][len] = m[6][pre] + m[8][pre];
    }
    long long total = 0;
    for (int i = 0; i <= 9; ++i) total += m[i][N];
    return total;
  }
};