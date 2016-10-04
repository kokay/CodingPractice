#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>

using namespace std;

class RepeatStringEasy {
public:
  int dp[50][50][50][50];
  string str;

  int maximalLength(string s) {
    memset(dp, -1, sizeof(dp));
    str = s;
    int len = 0;
    for (int i = 0; i < s.size(); ++i)
      for (int j = i + 1; j < s.size(); ++j) {
        cout << i << " " << j << endl;
        len = max(len, getLength(i, i, j, j));
      }

    return len * 2;
  }

  int getLength(int i, int j, int k, int l) {
    if (dp[i][j][k][l] != -1) {
      cout << "\t\t" << i << " " << j << " " << k << " " << l << endl;
      return dp[i][j][k][l];
    }
    if (j == k || l == str.size()) return 0;
    cout << "\t" << i << " " << j << " " << k << " " << l << endl;

    if (str[j] == str[l]) {
      dp[i][j][k][l] = 1 + getLength(i, j + 1, k, l + 1);
      return dp[i][j][k][l];
    }

    int a = getLength(i, j + 1, k, l);
    int b = getLength(i, j, k, l + 1);
    dp[i][j][k][l] = max(a, b);
    return dp[i][j][k][l];
  }
private:
};
//
//int main() {
//  RepeatStringEasy r;
//  cout << r.maximalLength("signing") << endl;
//}