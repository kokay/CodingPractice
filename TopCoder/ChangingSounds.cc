#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ChanginSounds {
public:
  int maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel) {
    bool memo[51][1001];
    memset(memo, false, sizeof(memo));

    memo[0][beginLevel] = true;
    for (int i = 1; i <= changeIntervals.size(); ++i)
      for (int j = 0; j <= maxLevel; ++j) {
        if (memo[i - 1][j]) {
          int level = j - changeIntervals[i - 1];
          if (level >= 0) memo[i][level] = true;

          level = j + changeIntervals[i - 1];
          if (level <= maxLevel) memo[i][level] = true;
        }
      }

    for (int i = maxLevel; i >= 0; --i)
      if (memo[changeIntervals.size()][i])
        return i;
    return -1;
  }
};

//int main() {
//  ChanginSounds c;
//  cout << c.maxFinal({ 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 }, 500, 1000) << endl;
//}