#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NoRepeatPlaylist {
public:
  int numPlaylists(int N, int M, int P) {
    vector<vector<long long>> memo(P + 1, vector<long long>(N + 1, 0));

    memo[0][0] = 1;
    for (int i = 1; i <= P; ++i) {
      for (int j = 1; j <= N; ++j) { 
        if (j > M) {
          memo[i][j] = (memo[i][j] + memo[i - 1][j] * (j - M)) % module;
        }
        memo[i][j] = (memo[i][j] + memo[i - 1][j - 1] * (N - j + 1)) % module;
      }
    }
    f(memo, P, N);
    cout << endl;

    
    memo = vector<vector<long long>>(P + 1, vector<long long>(N + 1, 0));
    memo[0][0] = 1;
    M = 4;
    for (int i = 1; i <= P; ++i) {
      for (int j = 1; j <= N; ++j) { 
        if (j > M) {
          memo[i][j] = (memo[i][j] + memo[i - 1][j] * (j - M)) % module;
        }
        memo[i][j] = (memo[i][j] + memo[i - 1][j - 1] * (N - j + 1)) % module;
      }
    }
    f(memo, P, N);
//    for (int i = 0; i < P; ++i) {
//      for (int j = 0; j <= N; ++j) { 
//        if (memo[i][j]) {
//          memo[i + 1][j] = memo[i + 1][j] + (long long)memo[i][j] * (j - min(M, i)) % module;
//          memo[i + 1][j + 1] = memo[i + 1][j + 1] + (long long)memo[i][j] * (N - j) % module;
//        }
//      }
//    }
    return memo[P][N];
  }

  void f(vector<vector<long long>>& memo, int P, int N) {
    for (int i = 0; i <= P; ++i) {
      for (int j = 0; j <= N; ++j) { 
        printf("%5d ", memo[i][j]);
      }
      cout << endl;
    }
  }

private:
  const int module = 1000000007;
};
//
//int main() {
//  NoRepeatPlaylist n;
//  cout << n.numPlaylists(6, 3, 8) << endl;
//}