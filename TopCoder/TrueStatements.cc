#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class TrueStatements {
public:
  int numberTrue(vector<int> statements) {
    int memo[51];
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < statements.size(); ++i)
      ++memo[statements[i]];

    for (int i = 50; i >= 0; --i)
      if (memo[i] == i) return i;
    return -1;
  }
};